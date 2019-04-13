
char INBYTE;

void setup() {
  Serial.begin(9600); 
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  INBYTE = Serial.read();        // read next available byte
  if( INBYTE == 'l' ) //LEFT LED
  {        digitalWrite(3, HIGH);
         digitalWrite(4, LOW);
         digitalWrite(5, LOW);
 }
 if( INBYTE == 'c' ) //CENTER LED
{ digitalWrite(3, LOW);      
digitalWrite(4, HIGH);
         digitalWrite(5, LOW);
 }
  if( INBYTE == 'r' ) //RIGHT LED
{ digitalWrite(3, LOW);      
digitalWrite(4, LOW);
         digitalWrite(5, HIGH);
 }
  if( INBYTE == 'o' ) //OFF
{ digitalWrite(3, LOW);      
digitalWrite(4, LOW);
         digitalWrite(5, LOW);
 }  
 if( INBYTE == 'n' ) //ON
{ digitalWrite(3, HIGH);      
digitalWrite(4, HIGH);
         digitalWrite(5, HIGH);
 }
}
