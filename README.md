# Modelling and PID Control of a Brushless DC Motor

### [Video Demo For P-Controller!](https://www.youtube.com/watch?v=C9_8D4adrs4)

![Block_Diagram.JPG](/Block_Diagram.JPG)

We have some parameters which we showed in above figure are known. One of the parameters [L] ignored due to negligible value. For the other values, [J and B] should be found. Finding [R] is measuring from two terminals of motor which is 2.16 Ohms. By adding stone resistor, it becomes 2.26 Ohms The main purpose of this project is to find some parameters empirically that are given in the figure. To control by using PID control we need to design 3 parts on PCB. Which is power distribution, and back EMF & filter.

## Pre-Modelling
𝑃𝑊𝑀 𝑃𝑒𝑟𝑖𝑜𝑑=4𝑥[(𝑃𝑅2)+1]𝑥[𝑇𝑀𝑅2 𝑃𝑟𝑒𝑠𝑐𝑎𝑙𝑒𝑉𝑎𝑙𝑢𝑒]𝑥𝑇𝑜𝑠𝑐 
According to Our circuit design and choice
PR2= 255
TMR2=16
Microcontroller Frequency=20 MHz
Tosc=1/20MHz
𝑃𝑊𝑀 𝑃𝑒𝑟𝑖𝑜𝑑=4*(255+1)*(16)*(1/20MHz)=1220 Hz
Then, the CCS Timer2 configuration has the following form,
setup_timer_2(T2_DIV_BY_16,255,1);
### Calibration of DC Motor
![Calibration_of_DC_Motor.JPG](/Calibration_of_DC_Motor.JPG)










