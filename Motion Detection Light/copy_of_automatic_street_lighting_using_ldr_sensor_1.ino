int LEDwhite = 10;
int DO_Sensor = 8;
int Sensitivity = 0;
int PIR_state = LOW;

void setup() {
  pinMode(LEDwhite, OUTPUT);
  pinMode(DO_Sensor, INPUT);
  Serial.begin(9600);
}
void loop() {
  Sensitivity = digitalRead(DO_Sensor);

  if (Sensitivity == HIGH) {
    digitalWrite(LEDwhite, HIGH);
    Serial.println("Light ON");

    if (PIR_state == LOW) {
      PIR_state = HIGH;
      Serial.println("Motion is detected");
    }
  }else{
    digitalWrite(LEDwhite, LOW);

    if(PIR_state == HIGH){
      PIR_state = LOW;
      }
    }
}