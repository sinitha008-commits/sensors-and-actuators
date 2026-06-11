int sensor=A0;  //Analog 0 pin named as sensor
int output=9;   //Pin-9 is declared as output

void setup()                                                          
{
pinMode(output, OUTPUT); //Pin-9 is declared as output 
//We dont need to declare the A0 pin as input since it is predefined as input                                                
}

void loop()
{ 
int reading=analogRead(sensor); //Reading the voltage out by potentiometer
int bright=reading/4;           //Dividing reading by 4 to bring it in range of 0 - 255                               
delay(500);                     //Delay is not necessary you can remove it
analogWrite(output, bright);    //Finally outputting the read value on pin-9 fading led
}  