#include <16F877A.h>
#device ADC=10
#FUSES NOWDT                     // No Watch Dog Timer
#FUSES NOBROWNOUT                // No brownout reset
#FUSES NOLVP                     // No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=20000000)     // CONFIGURE According to your crystal frequency

// Configuration for Serial Communication
#use rs232 (baud=9600,xmit=PIN_C6, rcv=PIN_C7, parity=N, stop=1) // UNCOMMENT If you need serial communication

#define MOTOR_DIR PIN_B1       // CONFIGURE; According to your direction pin

//custom function prototype
void pwm1_set(int16 mypwm);      // Used for changing PWM1 value

unsigned long int_ctr=0;    // interrupt counter

#int_timer0        // timer interrupt function tag
void tmr_int(){    // timer interrupt function (works when timer0 overflows)
   set_timer0(60);     // setting timer0 value again
   int_ctr++;     
}

void main()
{
   // PWM CONFIGURATION
  //delay_ms(10);
   set_tris_c(0x00);                      // Set all portc pins as output
   set_tris_b(0x00);
   set_tris_d(0x00);                      // Set all portc pins as output
   setup_ccp1(CCP_PWM);                   // PWM signal output at CCP1 pin 17
   setup_timer_2(T2_DIV_BY_16, 255, 1);   // CONFIGURE Timer Settings
   
   set_timer0(60);     //timer0 value set
           //internal clock        //prescaling 256
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_256); 
   enable_interrupts(int_timer0);
   enable_interrupts(global);  
   
   // ANALOG CONFIGURATION
   float voltagePot;
   
   setup_adc_ports(ALL_ANALOG);           // CONFIGURE Analog Pin
   setup_adc(ADC_CLOCK_DIV_32);           // Enable ADC and set clock for ADC
   
   float potValue;
   float degree;
   float ref =90;
   float error;
   float Kp =  40;  //frekans=6 period=0.1667 Kp= 0.6*40=24 Ti = 0.5*0.1667= 0.08335 Td=0.12*0.1667= 0.02

    delay_ms(10);                   
   
   set_adc_channel(3);
   voltagePot = read_adc();
   potValue = (voltagePot);
   delay_ms(100);
   
   while(1)
   {
      set_adc_channel(3);                    // CONFIGURE Analog Reading Channel
      voltagePot = read_adc(); 
      delay_us(10);
      
      degree= ((0.245*voltagePot)-(32));
      
      error =  ref - degree;
      float ctrl_signal;
      ctrl_signal = error*Kp;
      
      //unsigned int pwm = error*Kp;
      if (ctrl_signal<0)
      {
         ctrl_signal=(-1)*ctrl_signal;
         output_low(MOTOR_DIR);
      }
      else if (ctrl_signal >0) 
      {
         output_high(MOTOR_DIR);
      }
      if(ctrl_signal > 255)
      {
         ctrl_signal = 255;
      }
      set_pwm1_duty(ctrl_signal);
      
      unsigned long elapsedTime = int_ctr*10;
      //printf("int_ctr: %lu",int_ctr);
      //printf("t: %lu ",elapsedTime);
//!      printf("  voltagePot= %f  ", voltagePot);
//!      printf(" pwm= %d  ", pwm);
//!      printf("  degree= %f  \n", degree);
//!      delay_ms(20);
 
   }
}
