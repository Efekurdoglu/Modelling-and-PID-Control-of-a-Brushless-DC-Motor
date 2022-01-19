# Modelling and PID Control of a Brushless DC Motor

![Block_Diagram.JPG](/Block_Diagram.JPG)

We have some parameters which we showed in above figure are known. One of the parameters [L] ignored due to negligible value. For the other values, [J and B] should be found. Finding [R] is measuring from two terminals of motor which is 2.16 Ohms. By adding stone resistor, it becomes 2.26 Ohms The main purpose of this project is to find some parameters empirically that are given in the figure. To control by using PID control we need to design 3 parts on PCB. Which is power distribution, and back EMF & filter.

## Pre-Modelling
#### 𝑃𝑊𝑀 𝑃𝑒𝑟𝑖𝑜𝑑=4𝑥[(𝑃𝑅2)+1]𝑥[𝑇𝑀𝑅2 𝑃𝑟𝑒𝑠𝑐𝑎𝑙𝑒𝑉𝑎𝑙𝑢𝑒]𝑥𝑇𝑜𝑠𝑐 
- According to Our circuit design and choice
- PR2= 255
- TMR2=16
- Microcontroller Frequency=20 MHz
- Tosc=1/20MHz
- 𝑃𝑊𝑀 𝑃𝑒𝑟𝑖𝑜𝑑=4*(255+1)*(16)*(1/20MHz)=1220 Hz
- Then, the CCS Timer2 configuration has the following form,
- setup_timer_2(T2_DIV_BY_16,255,1);
### Calibration of DC Motor
![Calibration_of_DC_Motor.JPG](/Calibration_of_DC_Motor.JPG)
### [Video Demo For P-Controller!](https://www.youtube.com/watch?v=C9_8D4adrs4)
## Modelling
The relation between the rotational velocity and the back-emf voltage can be found with the Equation below :
#### 𝑉𝑏= 𝐾𝑏*𝜔
To estimate the value of 𝐾𝑏 voltage and rotational velocity data were obtained by measurements and the data were processed with MatLab curve fitting tool.
![With_EMF.JPG](/With_EMF.JPG)

![Angular_Velocity_vs_Vb.JPG](/Angular_Velocity_vs_Vb.JPG)
- The angle between this curve and x axis is represents Kb. 
### Circuit Design by Hand
![Circuit_Design.png](/Circuit_Design.png)
## Conclusion
We have a Brushed Dc Motor and we asked to find all the unknown parameters which are shown in Armature Control Brushed DC Motor Block Diagram. First we found frequency and period in premodeling part after that we implemented the supplied code into pic with small changes according to our system. And pwm frequrency are observed. When we rotated the motor we observed voltage out of motor. According to our frequency response we calculated rotational velocity according to duty cycle as shown in Table1.
In modeling, we started measuring resistor of motor which 2.16 ohms + 0.1 from stone resistor. After that we estimated back emf constant by drawing w to Vb in Figure 2. 
Foundations could be seen in Table2. 



