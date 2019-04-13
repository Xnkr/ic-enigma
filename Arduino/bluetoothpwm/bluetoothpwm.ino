/*
PIN SEQUENCE

HC05 VCC - 5V
HC05 GND - GND
HC05 TX - PIN 0
PIN 1 - 1.5K - 3.3K - GND
HC05 RX - Voltage Divider

LM293D
2 - PIN 8
7 - PIN 9
10 - PIN 10
11 - PIN 15
*/
// TRANSMISSION
/*
int counter =0;

void setup() {
  Serial.begin(9600); 
  delay(50);
}

void loop() {
  counter++;
  Serial.print("Arduino counter: ");
  Serial.println(counter);
  delay(500); // wait half a sec
}

*/
char input,init,spd;
int  LED = 13; // LED on pin 13
int ip1 = 8;
int ip2 = 9;
int ip3 = 10;
int ip4 = 11;
int sp= -1;

void setup() {
  Serial.begin(9600); 
  Serial.println("Awesomeness Bot v2 ....... ....... :D");
  pinMode(LED, OUTPUT);
  pinMode(ip1, OUTPUT);
  pinMode(ip2, OUTPUT);
  pinMode(ip3, OUTPUT);
  pinMode(ip4, OUTPUT);
}

void botstop()
{
  digitalWrite(LED, LOW); 
      digitalWrite(ip1, HIGH);
       digitalWrite(ip2, HIGH);
        digitalWrite(ip3, HIGH);
         digitalWrite(ip4, HIGH);
}

void forward()
{  
      digitalWrite(LED, HIGH);      
      digitalWrite(ip1, LOW);
       digitalWrite(ip2, HIGH);
        digitalWrite(ip3, HIGH);
         digitalWrite(ip4, LOW);
}

void reverse()
{
        digitalWrite(LED, HIGH);  
        digitalWrite(ip1, HIGH);
         digitalWrite(ip2, LOW);
          digitalWrite(ip3, LOW);
         digitalWrite(ip4, HIGH);
}

void left()
{
        digitalWrite(LED, HIGH); 
        digitalWrite(ip1, HIGH);
         digitalWrite(ip2, LOW);
        digitalWrite(ip3, HIGH);
         digitalWrite(ip4, LOW);
}

void right()
{
        digitalWrite(LED, HIGH);
       digitalWrite(ip1, LOW);
       digitalWrite(ip2, HIGH);
        digitalWrite(ip3, LOW);
         digitalWrite(ip4, HIGH);
}

void speedset(char spd)
{
    sp = (int)spd;
}

void loop() {
  Serial.println("Bot Begin!");
  while (!Serial.available());   // stay here so long as COM port is empty   
  if(sp == -1)
  {  
          Serial.println("Awesomeness Bot Interface.");
          Serial.println("Do you want to set speed ? y/n");
          init = Serial.read();
          if (init == 'y')
          {
                  Serial.println("Set the value of Speed. 10-100");
                  spd = Serial.read();
                  speedset(spd);
          }
          else
          {
                Serial.println("Setting Default Full Speed....");
                sp = 100;
          }
  }
  else
  {
  Serial.println("Press 'w' to move forward.\n 'a' to move left. \n 'd' to move right.\n 's' to move reverse.\n '0' to stop. \n 'b' back to menu.");
  input = Serial.read(); 
                if( input == '0' )
               {   
                 botstop();
               }
               if( input == 'w' ) //Forward
              { 
                forward();
              }
                if( input == 'a' ) //LEFT
               {   
                 left();
                 delay(400);
                 input = 1;
               }
               if( input == 'd' ) //RIGHT
              { 
                  right();
                  delay(400);
                  input = 1;
              }
                if( input == 's' ) //Reverse
               {   
                 reverse();
               }
                 if( input == 'b' ) //Back to menu
               {   
                 sp = -1;
               }
  }
  delay(50);
}
