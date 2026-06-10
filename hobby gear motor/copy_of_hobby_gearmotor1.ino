const int in3 = 2;
const int in4 = 3;
const int en2 = 5;

void setup() {
 pinMode(in3, OUTPUT);
 pinMode(in4, OUTPUT);
 pinMode(en2, OUTPUT);
}

void loop() {
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    analogWrite(en2, 150);
    delay(2000);
    analogWrite(en2, 255);
    delay(2000);

    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);

    analogWrite(en2, 150);
    delay(2000);
    analogWrite(en2, 255);
    delay(2000);
}