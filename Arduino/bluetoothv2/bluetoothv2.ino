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
15 - PIN 11
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
char input;
int  LED = 13; // LED on pin 13
int ip1 = 8;
int ip2 = 9;
int ip3 = 10;
int ip4 = 11;


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

void loop() {
  while(!Serial.available());
  input = Serial.read(); 
                if( input == '0' )
               {   
                 botstop();
               }
               if( input == 'w' ) //Forward
              { 
                forward();
                delayMicroseconds(10);
                 botstop();
                delayMicroseconds(10);
              }
                if( input == 'a' ) //LEFT
               {   
                 left();
                 delayMicroseconds(10);
                 botstop();
                  delayMicroseconds(10);
               }
               if( input == 'd' ) //RIGHT
              { 
                  right();
                 delayMicroseconds(10);
                 botstop();
                  delayMicroseconds(10);
              }
                if( input == 's' ) //Reverse
               {   
                 reverse();
                  delayMicroseconds(10);
                   botstop();
                   delayMicroseconds(10);
               }
            
  delay(50);
}
