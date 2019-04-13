#include "SIM900.h"
#include <SoftwareSerial.h>
//If not used, is better to exclude the HTTP library,
//for RAM saving.
//If your sketch reboots itself proprably you have finished,
//your memory available.
//#include "inetGSM.h"

//If you want to use the Arduino functions to manage SMS, uncomment the lines below.
#include "sms.h"
SMSGSM sms;

//To change pins for Software Serial, use the two lines in GSM.cpp.

//GSM Shield for Arduino
//www.open-electronics.org
//this code is based on the example of Arduino Labs.

//Simple sketch to send and receive SMS.

int numdata;
boolean started=false;
char smsbuffer[160];
char n[20];
int count = 1;

void setup() 
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  //Serial connection.
  Serial.begin(9600);
  //Start configuration of shield with baudrate.
  //For http uses is raccomanded to use 4800 or slower.
  if (gsm.begin(2400)){
    Serial.println("\nstatus=READY");
    started=true;  
  }
  else Serial.println("\nstatus=IDLE");
};

void loop() 
{
 char INBYTE = Serial.read();
  if( INBYTE == 's' )
  {
  if(count > 0)
 {
    if(started){
    //Enable this two lines if you want to send an SMS.
    if (sms.SendSMS("+xxxxxx", "Arduino SMS"))
      Serial.println("\nSMS sent OK");
      count--;
  }
 }
  }
  if( INBYTE == 'l' ) //LEFT LED
  {        digitalWrite(13, HIGH);
         digitalWrite(12, LOW);
         digitalWrite(11, LOW);
 }
 if( INBYTE == 'c' ) //CENTER LED
{ digitalWrite(13, LOW);      
digitalWrite(12, HIGH);
         digitalWrite(11, LOW);
 }
  if( INBYTE == 'r' ) //RIGHT LED
{ digitalWrite(13, LOW);      
digitalWrite(12, LOW);
         digitalWrite(11, HIGH);
 }
  
};
