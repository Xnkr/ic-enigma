/*
Pin 4 ,Pin 5,Pin 12 and Pin 13 from L293D Chip Connect to Ground (Negative On Breadboard)

Pin 1,Pin 9 and Pin 16 from L293D Chip Connect to 5 Volts (Positive On Breadboard)

Pin 8 from L293D Chip Connects to 6 Volts (Positive On Breadboard)

Pin 3 from L293D Chip Connects to Right Motor positive
Pin 6 from L293D Chip Connects to Right Motor negative

Pin 11 from L293D Chip Connects to Left Motor Positive 
Pin 14 from L293D Chip Connects to Left Motor Negative

Output pins on Arduino to control Right Motor :
Pin 2 from L293D Chip Connects to Output Pin on Arduino 13
Pin 7 from L293D Chip Connects to Output Pin on Arduino 12

Output pins on Arduino to control Left Motor :
Pin 10 from L293D Chip Connects to Output Pin on Arduino 10
Pin 15 from L293D Chip Connects to Output Pin on Arduino11

*/
int LeftMotorForward = 11; // Pin 10 has Left Motor connected on Arduino boards.
int LeftMotorReverse = 10; // Pin 9 has Left Motor connected on Arduino boards.

int RightMotorForward = 13; // Pin 12 has Right Motor connected on Arduino boards.
int RightMotorReverse = 12; // Pin 13 has Right Motor connected on Arduino boards.


void setup()
{
  pinMode(LeftMotorForward, OUTPUT);  // initialize the  pin as an output.
  pinMode(RightMotorForward, OUTPUT);  // initialize the  pin as an output.
  pinMode(LeftMotorReverse, OUTPUT);  // initialize the  pin as an output.
  pinMode(RightMotorReverse, OUTPUT);  // initialize the  pin as an output.
}

// The following Loop is to make the Robot go staright
void loop()

{
   digitalWrite(RightMotorForward, HIGH);   // turn the Right Motor ON
   digitalWrite(LeftMotorForward, HIGH);   // turn the Left Motor ON
   delay(5000);               // wait for  10 seconds
 
   digitalWrite(RightMotorForward,LOW);   // turn the Right Motor OFF
   digitalWrite(LeftMotorForward, LOW);   // turn the Left Motor OFF
   delay(1000);               // wait for  10 seconds
}
