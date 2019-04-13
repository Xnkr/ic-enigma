int VU;
void setup()
{
  Serial.begin(9600); //set baud rate
  //set pins attached to LEDs as outputs
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
}
void loop()
{
  VU=analogRead(5); //set VU as value of pin A5 reading

  //glow the LEDs depending on the ammount of sound detected by the electret  
  if (VU>455&&VU<555)
  {//glow first LED
    Clear(4);
    Glow(4);
  } 
  else if (VU>378&&VU<624)
  {//glow 2nd LED
    Clear(5);
    Glow(5);
  }
  else if (VU>311&&VU<693)
  {//glow 3rd LED
    Clear(6);
    Glow(6);
  }
  else if (VU>244&&VU<762)
  {//glow 4th LED
    Clear(7);
    Glow(7);
  }
  else if (VU>177&&VU<831)
  {//glow 5th LED
    Clear(8);
    Glow(8);
  }
  else if (VU<177||VU>831)
  {//glow 6th LED
    Clear(9);
    Glow(9);
  }

}

void Glow(int initial)//function to glow LEDs
{
  for(int i=3;i<initial;i++)digitalWrite(i,HIGH);
}

void Clear(int initial)//function to clear LEDs
{
  for(int i=initial;i<9;i++)digitalWrite(i,LOW);
}
