/*
 * Title: DECREASE LED BRIGHTNESS WITH BUTTON
  --------------------------
  Remember, you can buy all the electronic accessories used in this
  project at our online store: https://daerobotics.com/shop/ 
  at affordable rates.
  You can also buy other materials to build much more interesting projects
  
  
  The code in this sketch increases the brightness of an LED connected to 
  Pin 11 with a Tact push button connected to Pin 8 on the Arduino uno board.

 * Description: 
 ---------------
  In this project the brigtness of an LED is decreased using the tact push
  button. That is, when the button is pressed and released multiple times, 
  the LED becomes dimmer and dimmer till it reaches the minimum brigthness and then goes off.
  The LED is connected to digital Pin 11 while the tact push button is connected to Pin 8 
  with resistor pulling it to ground.

  NOTE!! You can only connect the LED to pin 3,5,6,9,10 and 11 on Arduino UNO board for this example. Here
  we chose pin 11.

 * Author: DAEROBOTICS (Department for Automation, Engineering and Robotics)
 ---------
 * Date:   03-FEB-2023
 -------
 
 
 */
const int MIN_BRIGHTNESS = 0, MAX_BRIGHTNESS = 200 ;
bool button_press();
bool debounce(int);
int LED_PIN = 11;
int BUTTON_PIN = 8;
int brightness ;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  brightness = MAX_BRIGHTNESS;
  analogWrite(LED_PIN, brightness);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(button_press())
  {
    analogWrite(LED_PIN, ((brightness -= 10)<MIN_BRIGHTNESS)? brightness = MAX_BRIGHTNESS:brightness);

    //Serial.print("brightness:"); Serial.println(brightness);
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
