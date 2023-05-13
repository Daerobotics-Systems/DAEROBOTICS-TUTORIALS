/*
 * Title: Toggle LED with Button
  --------------------------

  Remember, you can buy all the electronic accessories used in this
  project at our online store: https://daerobotics.com/shop/ 
  at affordable rates.
  You can also buy other materials to build much more interesting projects

  
  The code in this sketch toggles the LED connected to 
  Pin 12 with a Tact push button connectd to Pin 8 
  on the Arduino uno board.

 * Description: 
 ---------------
  In this project the LED is toggled using the tact push
  button. That is:
  When the button pressed, the LED is turned on and when
  the button is released, the LED is turned off.
  The LED is connected to digital Pin 12 while the tact push
  button is connected to Pin 8 with resistor pulling it to ground.


 * Author: DAEROBOTICS (Department for Automation, Engineering and Robotics)
 ---------
 * Date:   23-01-2023
 -------
 
 */
 
bool button_press(uint8_t);
int LED_PIN = 12;
int BUTTON_PIN = 8;
void setup() {
  // put your setup code here, to run once:

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(LED_PIN, button_press(BUTTON_PIN));
}

bool button_press(uint8_t button)
{
  if(digitalRead(button))
  {
    delay(50);
    if(digitalRead(button))
     return true;
    else return false;
  } 

  return false;
}
