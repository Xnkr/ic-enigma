
char INBYTE;

void setup() {
  Serial.begin(9600); 
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  INBYTE = Serial.read();        // read next available byte
  if( INBYTE == '0' )
  {        digitalWrite(3, LOW);
         digitalWrite(4, HIGH);
 }
 if( INBYTE == '1' ) //Forward
{ digitalWrite(3, HIGH);      
digitalWrite(4, LOW);
 }
  delay(50);
}
