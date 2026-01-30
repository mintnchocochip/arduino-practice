#include <Servo.h>
Servo sprinkle;

const int trig = 10;
const int echo = 11;
long duration;
int distance;

void setup(){
    sprinkle.attach(9);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    Serial.begin(9600);
}

bool visitor(){
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    duration = pulseIn(echo, HIGH);
    distance = (duration * 0.0343) / 2;

    if(distance >= 80){
        return false;
    } else {
        return true;
    }
}

void loop(){
    delay(8UL * 60 * 60 * 1000);

    int i = 0;
    while(i < 15){
        if(visitor()){
            delay(30000);
        }

        for (int ang = 0; ang <= 180; ang++){
            if(visitor()){
                delay(30000);
            }
            sprinkle.write(ang);
            delay(2000);
        }

        for (int ang = 180; ang >= 0; ang--){
            if(visitor()){
                delay(30000);
            }
            sprinkle.write(ang);
            delay(2000);
        }

        i++;
    }
}
