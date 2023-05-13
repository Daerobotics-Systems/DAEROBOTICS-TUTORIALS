/*
 * Title: SEVEN SEGMENT COUNTUP WITH BUTTON 
  ------------------------------------------
  Remember, you can buy all the electronic accessories used in this
  project at our online store: https://daerobotics.com/shop/ 
  at affordable rates.
  You can also buy other materials to build much more interesting projects
  
  
  The code in this sketch counts up from 0 to 9 on the seven segment display when a button
  is pressed. The button is connected to Pin 13 on the Arduino uno board.

 * Description: 
 ---------------
  In this project the we count up 0 to 9 by pressing a push button and display it on the seven segment display. Each time
  we press the push button, the numbers are counted up. The lowest number is 0 and the highest number is 9.
  The button is connected to digital Pin 13.
  

 * Author: DAEROBOTICS (Department for Automation, Engineering and Robotics)
 ---------
 * Date:   12-MAY-2023
 -------
 
 
 */
char A=2, B=3, C=4, D=5, E=6, F=7, G=8, DP=9;
char segments[8] = {A,B,C,D,E,F,G,DP};
unsigned char digits[10]= 
{
  0b11111100, //0
  0b01100000, //1
  0b11011010, //2
  0b11110010, //3
  0b01100110, //4
  0b10110110, //5
  0b10111110, //6
  0b11100000, //7
  0b11111110, //8
  0b11110110, //9
};

int BUTTON_PIN = 13;
int MIN_NUM = 0, MAX_NUM = 9;
int num = MIN_NUM;

void count_up(void);
void count_down(void);



bool button_press(void);
void display_digits(int num);
bool debounce(int button);


void setup() {
  // put your setup code here, to run once:
   
   num = MIN_NUM;
   pinMode(BUTTON_PIN, INPUT);
}



void loop() {
  // put your main code here, to run repeatedly:

  if(button_press())
  {
    count_up(num);
  }
}


void display_digits(int num)
{
  if(num > 9)return;
  int index = (sizeof digits) - (((sizeof digits)/sizeof(unsigned char)) - num);
  unsigned char digit = digits[index];
  for(uint8_t i = 0; i<8; i++)
  {
    digitalWrite(segments[i], LOW);
  }
  for(uint8_t i = 0; i<=7; i++, digit <<= 1)
  {
    
    if(digit & 0b10000000)digitalWrite(segments[i], HIGH);
    else digitalWrite(segments[i], LOW);
    if(i == 7)continue;    
    
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

void count_down(int& num)
{
  if(num < MIN_NUM)
  {
    num = MAX_NUM;
  }
  display_digits(num--);
}

void count_up(int& num)
{
  if(num > MAX_NUM)
  {
    num = MIN_NUM;
  }
  display_digits(num++);
}
