int rm1=24;   //naming motor pins
int rm2=25;
int lm1=0;
int lm2=1;
int r1[10];
int o[10];
int x;
int l,c1,c2,c3,r;   //sensor pins4
int i=0;
int j=0;

int tdelay=750;   // turn delay
int fdelay=500;    //forward delay

void Stop()          //stop function
{
  digitalWrite(lm1,0);
  digitalWrite(lm2,0);
  digitalWrite(rm1,0);
  digitalWrite(rm2,0);
  digitalWrite(4,HIGH);

}

void forward()       //forward function
{
  digitalWrite(lm1,1);
  digitalWrite(lm2,0);
  digitalWrite(rm1,1);
  digitalWrite(rm2,0);
}

void smallright()                //right for lfr
{
  digitalWrite(lm1,1);
  digitalWrite(lm2,0);
  digitalWrite(rm1,0);
  digitalWrite(rm2,0);
}

void smallleft()              //left for lfr
{
  digitalWrite(lm1,0);
  digitalWrite(lm2,0);
  digitalWrite(rm1,1);
  digitalWrite(rm2,0);
}

void right()     //differential run
{
  digitalWrite(lm1,1);
  digitalWrite(lm2,0);
  digitalWrite(rm1,0);
  digitalWrite(rm2,1);
}

void left()      //differential left
{
  digitalWrite(lm1,0);
  digitalWrite(lm2,1);
  digitalWrite(rm1,1);
  digitalWrite(rm2,0);
}

int eosens()
{
  readsens();
  if(((c1+c2+c3)==1)||((c1+c2+c3)==2))
  return 1;
  else
  return 0;
}

void readsens()         // read sensor values
{
  l=digitalRead(26);
  c1=digitalRead(27);
  c2=digitalRead(28);
  c3=digitalRead(29);
  r=digitalRead(30);
  x=digitalRead(31);   //obstacle sensor pin
}
void inch()             //perform inch function
{
  
  Stop();       //stop
  delay(100);
  forward();        //fwd
  delay(500);
  readsens();      //read sensor values
  delay(100);

}

void align()        //align function
{
  Stop();                  //stop
  delay(500);
  forward();          //fwd
  delay(85);
  readsens();       //read sensor values
}


void setup()
{            
  pinMode(lm1,OUTPUT);         
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(3,OUTPUT);//Red Led
  pinMode(4,OUTPUT);//Green Led
  pinMode(26,INPUT);          //declare input pins
  pinMode(27,INPUT);
  pinMode(28,INPUT);
  pinMode(29,INPUT);
  pinMode(30,INPUT);
  pinMode(31,INPUT);

}

void loop()
{            //clear lcd
  readsens();           //read sensor values
                //clear lcd
  
  //-------------------line follower-----//
  //fwd
  while(x!=1) // when no obstacle is present
  {
  if((l==1)&&(c1==1)&&(c2==0)&&(c3==1)&&(r==1))
  {
    digitalWrite(3,LOW);
    forward();          //forward
  }
  //left
  else if(((l==1)&&(c1==0)&&(c2==0)&&(c3==1)&&(r==1)) || ((l==1)&&(c1==0)&&(c2==1)&&(c3==1)&&(r==1)))
  {
    digitalWrite(3,LOW);
    smallleft();                //small left
  }
  
  //right
  else if(((l==1)&&(c1==1)&&(c2==0)&&(c3==0)&&(r==1))||((l==1)&&(c1==1)&&(c2==1)&&(c3==0)&&(r==1)))
  {
    digitalWrite(3,LOW);
    smallright();            //smallright
  }
    //right
  else if(((l==1)&&(c1==1)&&(c2==0)&&(c3==0)&&(r==0))||((l==1)&&(c1==1)&&(c2==0)&&(c3==1)&&(r==0)))
  {
    right();
    r1[i++]; 
    digitalWrite(3,HIGH);  //right
  
}
else if(((l==0)&&(c1==0)&&(c2==0)&&(c3==1)&&(r==1))||((l==0)&&(c1==1)&&(c2==0)&&(c3==1)&&(r==1)))
  {
    left();
    digitalWrite(3,LOW);  //left
  
}
  
  
  
//--------------dead end-------------
else if((l==1)&&(c1==1)&&(c2==1)&&(c3==1)&&(r==1))
{
  digitalWrite(3,LOW);
  right();          //U turn
  delay(850);              //delay for u trun
 // directions[i]='U';     //store 'U' in the arraay
      //inward circular strip            //increment the position
}
  }
   Stop();  
   o[j++]; 
     //no of obstacles counter is incremented

}

