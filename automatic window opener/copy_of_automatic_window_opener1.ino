#include <Servo.h>

Servo windowServo;
int ldrPin = A0;
int ldrValue = 0;

void setup() {
  windowServo.attach(9);
  Serial.begin(9600);
}

void loop() {
  ldrValue = analogRead(ldrPin);  // Read light level
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  if (ldrValue > 500) {           // Bright → Open window
    windowServo.write(90);        // Rotate servo to 90°
    Serial.println("Bright → Window Open");
  } else {                        // Dark → Close window
    windowServo.write(0);         // Rotate servo back to 0°
    Serial.println("Dark → Window Closed");
  }

  delay(500);
}
