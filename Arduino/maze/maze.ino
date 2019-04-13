char directions[30];
#include<LiquidCrystal.h>  //header for lcd
LiquidCrystal lcd(12,11,5,4,3,2);
int rm1=24;   //naming motor pins
int rm2=25;
int lm1=0;
int lm2=1;
int l,c1,c2,c3,r;   //sensor pins4
int i=0;
int tdelay=750;   // turn delay
int fdelay=500;    //forward delay

void Stop()          //stop function
{
  digitalWrite(lm1,0);
  digitalWrite(lm2,0);
  digitalWrite(rm1,0);
  digitalWrite(rm2,0);
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
  lcd.print(l);
  lcd.print("--");
  lcd.print(c1);
  lcd.print("--");
  lcd.print(c2);
  lcd.print("--");
  lcd.print(c3);
  lcd.print("--");
  lcd.print(r);
  lcd.print("--");
}
void inch()             //perform inch function
{
  lcd.print("Inch Function");
  Stop();       //stop
  delay(100);
  forward();        //fwd
  delay(500);
  readsens();      //read sensor values
  delay(100);
  lcd.clear();
}

void align()        //align function
{
  Stop();                  //stop
  delay(500);
  forward();          //fwd
  delay(85);
  lcd.clear();             
  readsens();       //read sensor values
}

void printing(char prtdirection[])             // func to print values on lcd
{
  lcd.clear();
  for(i=0;prtdirection[i]!='E';i++)
  {
    lcd.print(prtdirection[i]);
  }
  delay(2000);
}
void setup()
{
  lcd.begin(16,2);            //initialise lcd
  lcd.print("Awesome");
  delay(500);
  lcd.clear();              //clear lcd
  pinMode(lm1,OUTPUT);         //declare output pins
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(26,INPUT);          //declare input pins
  pinMode(27,INPUT);
  pinMode(28,INPUT);
  pinMode(29,INPUT);
  pinMode(30,INPUT);
}

void loop()
{
  lcd.clear();            //clear lcd
  readsens();           //read sensor values
  lcd.clear();                //clear lcd
  
  //-------------------line follower-----//
  //fwd
  if((l==1)&&(c1==1)&&(c2==0)&&(c3==1)&&(r==1))
  {
    lcd.print("Forward");
    forward();          //forward
  }
  //left
  else if(((l==1)&&(c1==0)&&(c2==0)&&(c3==1)&&(r==1)) || ((l==1)&&(c1==0)&&(c2==1)&&(c3==1)&&(r==1)))
  {
    lcd.print("left");
    smallleft();                //small left
  }
  
  //right
  else if(((l==1)&&(c1==1)&&(c2==0)&&(c3==0)&&(r==1))||((l==1)&&(c1==1)&&(c2==1)&&(c3==0)&&(r==1)))
  {
    lcd.print("Right");
    smallright();            //smallright
  }
//--------------dead end-------------
else if((l==1)&&(c1==1)&&(c2==1)&&(c3==1)&&(r==1))
{
  lcd.print("U turn");
  right();          //U turn
  delay(850);              //delay for u trun
  directions[i]='U';     //store 'U' in the arraay
  i++;            //increment the position
}

  //--------------Maze cases-----------
  else if(((l==0)&&(c1==0))||((c3==0)&&(r==0)))
  {
    align();          //align
    //----------right only and strt and right
    if(((l==1)&&(c1==0)&&(c2==0)&&(c3==0)&&(r==0))||((l==1)&&(c1==1)&&(c2==0)&&(c3==0)&&(r==0)))
    {
      lcd.print("RT/Strt n rt?");
      inch();
      if((l==1)&&(c1==1)&&(c2==1)&&(c3==1)&&(r==1))
      {
        lcd.print("right");
        right();          //turn right
       delay(tdelay);     //turn delay
      }
    else if((l==1)&&(r==1)&&(eosens()))
  {
    lcd.print("straight");
  directions[i]='S';    //store 'S' in array
  i++;             //increment to the next position
  forward();       //fwd
  delay(fdelay);     //fwd delay
  }
    }
    
 //---------left and strt left

else if(((l==0)&&(c1==0)&&(c2==0)&&(c3==0)&&(r==1)) ||((l==0)&&(c1==0)&&(c2==0)&&(c3==1)&&(r==1)))
{
  lcd.print("lft/strt n left");
  inch();   //inch
  if((l==1)&&(c1==1)&&(c2==1)&&(c3==1)&&(r==1))
  {
    lcd.print("Left");
    left();             //left
    delay(tdelay);         //turn delay
  }
  else if((l==1)&&(r==1)&&(eosens()))
  {
    lcd.print("left");
    directions[i]='L';    //store 'L' in array
    i++;     //increment to the next position
    left();
    delay(tdelay);
  }
}
//----------4 way /t intersection/ finish
else if((l==0)&&(c1==0)&&(c2==0)&&(c3==0)&&(r==0))
{
  lcd.print("T/END/4");
  inch();   //inch
  if((l==1)&&(r==1)&&(eosens()))
  {
    lcd.print("4 Way");
    directions[i]='L';  //store 'L' into the array
    i++;      //increment
    left();      ///left
    delay(tdelay);       //turn delay
  }
 else if((l==1)&&(c1==1)&&(c2==1)&&(c3==1)&&(r==1))
 {
   lcd.print("T-int");
   directions[i]='L';     //store 'L' in to the aray
   i++;               //increment
   left();            // left
   delay(tdelay);       //turn delay
 }
 else if((l==0)&&(c1==0)&&(c2==0)&&(c3==0)&&(r==0))
 {
   lcd.print("End of maze");
   directions[i]='E';       //store 'E' in to the array
   printing(directions);        //printing the final path
   while (1)
   {
     Stop();
   }
 }
}
  }
}
