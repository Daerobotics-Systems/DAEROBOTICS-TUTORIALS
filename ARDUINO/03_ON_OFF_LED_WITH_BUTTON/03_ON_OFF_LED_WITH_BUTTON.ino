/*
 * Title: ON_OFF LED WITH BUTTON
  --------------------------
  Remember, you can buy all the electronic accessories used in this
  project at our online store: https://daerobotics.com/shop/ 
  at affordable rates.
  You can also buy other materials to build much more interesting projects
  
  
  The code in this sketch switches the LED connected to 
  Pin 12 with a Tact push button connected to Pin 8 
  on the Arduino uno board.

 * Description: 
 ---------------
  In this project the LED is switched On and Off using the tact push
  button. That is, as opposed to the 'Toggle LED with Button' example,
  In this project when the button pressed, the LED is turned on and
  remains in the On state when the button is released and the LED is only 
  turned off when the button is pressed again and remains in the Off state till
  the button is pressed again. The LED is connected to digital Pin 12 while 
  the tact push button is connected to Pin 8 with resistor pulling it to ground.


 * Author: DAEROBOTICS (Department for Automation, Engineering and Robotics)
 ---------
 * Date:   23-01-2023
 -------
 
 
 */
 
bool button_press();
bool debounce(int);
int LED_PIN = 12;
int BUTTON_PIN = 8;
bool led_previous_state = LOW;
void setup() {
  // put your setup code here, to run once:

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(button_press())
  {
    digitalWrite(LED_PIN, led_previous_state = !led_previous_state );
  }
}

bool button_press()
{
  if(debounce(BUTTON_PIN))
  {
    delay(200);
    if(!digitalRead(BUTTON_PIN))
    return true;
  }
  return false;
}

bool debounce(int button)
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
