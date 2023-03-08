/*
 * Title: INCREASE LED BLINKING RATE
  --------------------------
  Remember, you can buy all the electronic accessories used in this
  project at our online store: https://daerobotics.com/shop/ 
  at affordable rates.
  You can also buy other materials to build much more interesting projects
  
  
  The code in this sketch increases the blinking rate of an LED connected to 
  Pin 11 with a Tact push button connected to Pin 8 on the Arduino uno board.

 * Description: 
 ---------------
  In this project the rate of a blinking LED is increased using the tact push
  button. That is, when the button is pressed and released multiple times, 
  the LED blinks faster and faster till it reaches the maximum brigthness and then stays on without blinking.
  The LED is connected to digital Pin 11 while the tact push button is connected to Pin 8 
  with resistor pulling it to ground.
  

 * Author: DAEROBOTICS (Department for Automation, Engineering and Robotics)
 ---------
 * Date:   03-FEB-2023
 -------
 
 
 */

const int MIN_BLINK_RATE = 0, MAX_BLINK_RATE = 2000;
bool button_press();
bool debounce(int);
int LED_PIN = 11;
int BUTTON_PIN = 8;
int blink_rate , wait;
unsigned long start_time;
bool state = false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  blink_rate = MIN_BLINK_RATE;
  wait = MAX_BLINK_RATE;
 
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(button_press())
  {
    if(wait == 200)
    wait = 100;
    else
    {
     wait = ((blink_rate += 200)==MAX_BLINK_RATE)? blink_rate = MAX_BLINK_RATE:(MAX_BLINK_RATE - blink_rate);
     start_time = millis();
    }
  }
  
  
    if((millis()-start_time) >= wait)
    {
      digitalWrite(LED_PIN,state = !state );
      start_time = millis();                                          
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
