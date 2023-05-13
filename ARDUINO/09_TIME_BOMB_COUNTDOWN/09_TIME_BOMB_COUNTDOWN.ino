/*
 * Title: TIME_BOMB_COUNTDOWN 
  --------------------------
  Remember, you can buy all the electronic accessories used in this
  project at our online store: https://daerobotics.com/shop/ 
  at affordable rates.
  You can also buy other materials to build much more interesting projects
  
  
  The code in this sketch demonstrates the simple operational countdown of likely
  TIME BOMB. Our Time bomb here is simulated with a Seven segment Display and an LED connected to Pin 13
  on the Arduino uno board.

 * Description: 
 ---------------
  In this project the Seven Segment counts down from 9 to 0 and the LED turns on as an indication
  of explosion of a time bomb. The LED is connected to digital Pin 13.
  

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

int led_pin = 13;
int MIN_NUM = 0, MAX_NUM = 9;
int num;
bool explode_bomb;


void count_up(void);
void count_down(void);


void display_digits(int num);

void setup(void) {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);
  num = MAX_NUM;
  explode_bomb = 0;
}

void loop(void) {
  // put your main code here, to run repeatedly:
  if(num == MIN_NUM)
  {
    digitalWrite(led_pin, HIGH);
    explode_bomb = 1;
  }
  
  count_down(num);
  
  if(explode_bomb)
  {
    delay(6000);
    digitalWrite(led_pin, LOW);
    explode_bomb = 0;
    return;  
  }
  delay(2000);
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
