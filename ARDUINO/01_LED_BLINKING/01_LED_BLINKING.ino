/*
 * Title: LED blinking code
  --------------------------

  Remember, you can buy all the electronic accessories used in this
  project at our online store: https://daerobotics.com/shop/ 
  at affordable rates.
  You can also buy other materials to build much more interesting projects

  
  The code in this sketch blinks the on-board LED on the 
  Arduino uno board every 1 second(1000 milliseconds)

 * Description: 
 ---------------
  The on-board LED is connected to Pin 13 of the Arduino board
  so you may not need to connect any external LED to the board.
  But if you choose to connect an external LED to the board you
  can use a 390 ohms resistor. You can connect the external LED
  to any digital pin number on the board and change the "LED_PIN"
  within the code. For example:
  change:
  LED_PIN = LED_BUILTIN;

  to:
  
  LED_PIN = 10; ("10" here is your desired pin)


 * Author: DAEROBOTICS (Department for Automation, Engineering and Robotics)
 ---------
 * Date:   23-01-2023
 -------
 */

int LED_PIN = LED_BUILTIN;

void setup(void)
{
  pinMode(LED_PIN, OUTPUT);
}


void loop(void)
{
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN,LOW);
  delay(1000);
}
