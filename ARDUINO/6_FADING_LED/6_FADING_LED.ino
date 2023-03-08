/*
 * Title: FADING LED 
  --------------------------
  Remember, you can buy all the electronic accessories used in this
  project at our online store: https://daerobotics.com/shop/ 
  at affordable rates.
  You can also buy other materials to build much more interesting projects
  
  
  The code in this sketch fades an LED connected to Pin 11 on the Arduino uno board.

 * Description: 
 ---------------
  In this project the brigtness of an LED is increased gradually and decreased gradually.
  That is, the LED glows brighter with time until in reaches it maximum brightness and then 
  the LED becomes dimmer and dimmer till it reaches the minimum brigthness. This happens over
  and over again. The LED is connected to digital Pin 11.
  
  NOTE!! You can only connect the LED to pin 3,5,6,9,10 and 11 on Arduino UNO board for this example. Here
  we chose pin 11.

 * Author: DAEROBOTICS (Department for Automation, Engineering and Robotics)
 ---------
 * Date:   03-FEB-2023
 -------
 
 
 */
const int MIN_BRIGHTNESS = 0, MAX_BRIGHTNESS = 200 ;

int LED_PIN = 11;
int brightness ;
bool increment;
bool DELAY(void);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  brightness = MIN_BRIGHTNESS;
  increment = true;

}

void loop() {
  // put your main code here, to run repeatedly:
  if(increment)
  {
    analogWrite(LED_PIN, ((brightness += 5)> MAX_BRIGHTNESS)? brightness = MAX_BRIGHTNESS :brightness);
    (brightness == MAX_BRIGHTNESS)?increment = false&&DELAY():0;
    //Serial.print("brightness:"); Serial.println(brightness);
  }
  else
  {
    analogWrite(LED_PIN, ((brightness -= 10) < MIN_BRIGHTNESS)? brightness = MIN_BRIGHTNESS :brightness);
    (brightness == MIN_BRIGHTNESS)?increment = true && DELAY():0;
    //Serial.print("brightness:"); Serial.println(brightness);
  }

  delay(200);

}

bool DELAY(void)
{
  delay(2000);
  return true;
}
