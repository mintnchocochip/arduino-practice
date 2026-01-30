const int tempPin = A0;
const int ledR = 6;
const int ledG = 5;
const int buzzer = 9;   // PWM pin

void setup(){
    pinMode(tempPin, INPUT);
    pinMode(ledR, OUTPUT);
    pinMode(ledG, OUTPUT);
    pinMode(buzzer, OUTPUT);
    Serial.begin(9600);
}

float getTemp(){                 // TMP36 / LM35 style analog sensor
    int val = analogRead(tempPin);
    float volt = (val * 5.0) / 1023.0;
    float t = (volt - 0.5) * 100.0;   // adjust if your sensor is LM35: t = volt * 100;
    return t;
}

void loop(){
    float t = getTemp();

    if(t < 90){
        digitalWrite(ledR, LOW);      // R OFF
        digitalWrite(ledG, HIGH);     // G ON
        analogWrite(buzzer, 0);       // buzzer OFF
    }
    else{
        digitalWrite(ledR, HIGH);     // R ON
        digitalWrite(ledG, LOW);      // G OFF
        analogWrite(buzzer, 191);     // ~75% duty (191/255) [web:39]
    }

    delay(200);
}
