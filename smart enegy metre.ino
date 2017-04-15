#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int led1 =14;
int led2 = 15;
int led3 = 16;
int i=0;
int k=0;
int j=0;
int a=0;


void setup() 
{
  Serial.begin(9600);
   lcd.begin(16, 2); 
    pinMode(14,OUTPUT);
    pinMode(15,OUTPUT);
    pinMode(16,OUTPUT);
  }


void loop() 
{ 
 lcd.setCursor(0,0);  
 lcd.print("COUNT=");
 lcd.print(i); 
 lcd.setCursor(0,1);  
 lcd.print("UNIT=");  
 lcd.print(j);
 lcd.setCursor(8,0);  
 lcd.print("SLAB=");  
 lcd.print(k);
 lcd.setCursor(8,1);  
 lcd.print("AMT=");  
 lcd.print(a); 


 if(i<10)
  {
  digitalWrite(led1,HIGH);
  lcd.setCursor(6,0);
  lcd.print(i);
   delay(500);
   digitalWrite(led1,LOW);
   delay(100);
   i++;
   }

   if(i==10)
   {
  lcd.setCursor(5,1);
  lcd.print(j);
    digitalWrite(led1,HIGH); 
    digitalWrite(led2,HIGH);
  
    delay(1000);
     
     digitalWrite(led2,LOW);
     digitalWrite(led1,LOW); 
   delay(100);
      
   
  j++;
  i=0;
   if(j==30) 
   {
   digitalWrite(led1,HIGH); 
   digitalWrite(led2,HIGH);
   digitalWrite(led3,HIGH);
    k=1;
   message1();
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led3,LOW);
    
   }
   else if(j==50)
   {
    digitalWrite(led1,HIGH); 
   digitalWrite(led2,HIGH);
   digitalWrite(led3,HIGH);
    k=2;
    delay(1000);
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led3,LOW);
   }
    else if(j==100)
   {
    digitalWrite(led1,HIGH); 
   digitalWrite(led2,HIGH);
   digitalWrite(led3,HIGH);
    k=3;
    delay(1000);
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led3,LOW);
   }
  if(k==0)
   {
    a=j*2; 
   }
   else if(k==1)
   {
    a=(j*2)+5;
   
   }
   else if(k==2)
   {
    a=(j*2)+10;
   }
   
 else if(k==3)
   {
    a=(j*2)+20;
   }
   
  lcd.setCursor(12,1);
  lcd.print(a);
  lcd.setCursor(13,0);
  lcd.print(k);
   
  }
}


void message1()
{
Serial.print("AT+CMGF=1\r\n");
delay(1000);
Serial.print("AT+CMGS=\"");
Serial.print("#####");//enter phone number
Serial.print("\"\r\n");
delay(1000);
Serial.print("Warning!!\t");
Serial.print("dear consumer your 1st slab crossed");
Serial.print("current ammount is\t");
Serial.print(a);
Serial.write(0x1A);
}


void message2()
{
Serial.print("AT+CMGF=1\r\n");
delay(1000);
Serial.print("AT+CMGS=\"");
Serial.print("###");//enter phone number
Serial.print("\"\r\n");
delay(1000);
Serial.print("Warning!!\t");
Serial.write(0x1A);
}


void message3()
{
Serial.print("AT+CMGF=1\r\n");
delay(1000);
Serial.print("AT+CMGS=\"");
Serial.print("####");//enter phone number
Serial.print("\"\r\n");
delay(1000);
Serial.print("Warning!!\t");
Serial.write(0x1A);
}

