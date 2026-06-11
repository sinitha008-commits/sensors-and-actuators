#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


int val;
float Temp;
int motor = 6 ;
int speed = 0;
const int buttonPin = 8; 
int buttonState = 0; 

void setup()
{
 lcd.begin(16,2);
  pinMode(motor, OUTPUT);
  
  
  analogWrite(motor,speed);
  lcd.clear();
  speed = 0;
  analogWrite(motor,speed);
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("Temperature");
  lcd.setCursor(0,1);
  lcd.print("Controlled");
  lcd.setCursor(12,1);
  lcd.print("Fan");
  delay(1000);
  lcd.clear();
  lcd.print("Acmegrade");
 lcd.setCursor(0,1);
  lcd.print("Project Batch 6");
  delay(3000);
  lcd.clear();
  lcd.noDisplay(); 
  pinMode(buttonPin, INPUT);
  while(!(digitalRead(buttonPin)));
}



void loop() {
   
    lcd.display(); 
    val= analogRead(0);
 
   float voltage = val * 5.0;
 voltage /= 1024.0; 
  float temperatureC = (voltage - 0.5) * 100 ;
  lcd.setCursor(0,0);
  lcd.print("Temp :");
  lcd.setCursor(8,0);
  lcd.print(temperatureC);
  delay(1000);
  lcd.clear();
  if(temperatureC>20 && temperatureC<24)
  {
    speed=60;
    analogWrite(motor,speed); 
    lcd.print("Fan Speed: 25% ");
    delay(2000);
    lcd.clear();
    
  }
  
  if(temperatureC>24 && temperatureC<30)
  { 
    speed = 125;
    analogWrite(motor,speed);
    lcd.print("Fan Speed: 50% ");
    delay(2000);
    lcd.clear();
  }
  
  if(temperatureC>30 && temperatureC<50)
  { 
    speed = 250;
    analogWrite(motor,speed);
    lcd.print("Fan Speed: 100% ");
    delay(2000);
    lcd.clear();
  }
  
  
   else {
    lcd.noDisplay();
   }
}