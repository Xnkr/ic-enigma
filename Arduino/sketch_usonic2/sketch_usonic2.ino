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
  long duration1, distance1, duration2, distance2;
//  digitalWrite(trigPin1, LOW);  // Added this line
  digitalWrite(trigPin2, LOW);  // Added this line
//  delayMicroseconds(2); // Added this line
  delayMicroseconds(2); // Added this line
 // digitalWrite(trigPin1, HIGH);
  digitalWrite(trigPin2, HIGH);
 // delayMicroseconds(10); // Added this line
   delayMicroseconds(10); // Added this line
  //digitalWrite(trigPin1, LOW);
    digitalWrite(trigPin2, LOW);
 // duration1 = pulseIn(echoPin1, HIGH);
    duration2 = pulseIn(echoPin2, HIGH);
 // distance1 = (duration1/2) / 29.1;
    distance2 = (duration2/2) / 29.1;
  if (distance2 > 4) {//  if (distance1 < distance2) {  // This is where the LED On/Off happens
    digitalWrite(ledg,HIGH); // When the Red condition is met, the Green LED should turn off
  digitalWrite(ledr,LOW);
}
  else {
    digitalWrite(ledg,LOW);
    digitalWrite(ledr,HIGH);
  }
  if (distance2 >= 200 || distance2 <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.println(" Distance2 = ");
    Serial.print(distance2);
    Serial.println(" cm");
  }
  delay(500);
}
