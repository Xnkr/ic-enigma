#define trigPin1 13
#define echoPin1 12
#define trigPin2 9
#define echoPin2 8
#define ledr 11
#define ledg 10

void setup() {
    Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(ledg, OUTPUT);
  pinMode(ledr, OUTPUT);
}

void loop() {
 long distance1,distance2;
//  distance1=us1();
 distance2=us2();
  if (distance2 < 4) {  // This is where the LED On/Off happens
    digitalWrite(ledr,HIGH); // When the Red condition is met, the Green LED should turn off
  digitalWrite(ledg,LOW);
}
  else {
    digitalWrite(ledr,LOW);
    digitalWrite(ledg,HIGH);
  }
  delay(500);
}

long us1()
{  
    long duration, distance;
  digitalWrite(trigPin1, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin1, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin1, LOW);
  duration = pulseIn(echoPin1, HIGH);
    if (distance >= 200 || distance <= 0){
    Serial.println("D1 Out of range");
  }
  else {
    Serial.println(" Distance 1 = ");
    Serial.print(distance);
    Serial.println(" cm;");
  }
  return distance;
}

long us2()
{ 
  long duration, distance;
  digitalWrite(trigPin2, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin2, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin2, LOW);
  duration = pulseIn(echoPin2, HIGH);
    if (distance >= 200 || distance <= 0){
    Serial.println("D2 Out of range");
  }
  else {
    Serial.println(" Distance 2 = ");
    Serial.print(distance);
    Serial.println(" cm;");
  }
    if (distance < 4) {  // This is where the LED On/Off happens
    digitalWrite(ledr,HIGH); // When the Red condition is met, the Green LED should turn off
  digitalWrite(ledg,LOW);
}
  else {
    digitalWrite(ledr,LOW);
    digitalWrite(ledg,HIGH);
  }
  return distance;
}
