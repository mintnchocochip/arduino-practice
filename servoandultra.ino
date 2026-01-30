#include <Servo.h>  // Capital S in Servo
Servo sprinkle;

const int trig = 10;
const int echo = 11;
long duration;
int distance;

void setup(){
    sprinkle.attach(9);  // Remove 0,180 parameters - not needed
    pinMode(trig, OUTPUT);  // TRIG is OUTPUT, not INPUT
    pinMode(echo, INPUT);   // ECHO is INPUT, not OUTPUT
    Serial.begin(9600);     // Capital S in Serial
}

bool visitor(){
    digitalWrite(trig, LOW);
    delayMicroseconds(2);  // Use delayMicroseconds, not delay
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);  // Use delayMicroseconds, not delay
    digitalWrite(trig, LOW);

    duration = pulseIn(echo, HIGH);  // pulseIn (not pulseInt), and HIGH (not LOW)
    distance = (duration * 0.0343) / 2;

    // Distance should be in cm, 80cm = 0.8m
    if(distance >= 80){  // Changed from 0.8 to 80 (cm)
        return false;
    } else {
        return true;
    }
}

void loop(){
    delay(8UL * 60 * 60 * 1000);  // 8 hours in milliseconds (use UL for long)

    int i = 0;
    while(i < 15){
        if(visitor()){
            delay(30000);  // 30 seconds pause, not 300ms
        }

        // 0° to 180° sweep (takes ~360 seconds with 2-second intervals)
        for (int ang = 0; ang <= 180; ang++){
            if(visitor()){
                delay(30000);  // 30 seconds pause
            }
            sprinkle.write(ang);
            delay(2000);  // 2 seconds per 1° movement
        }

        // 180° to 0° sweep (return motion)
        for (int ang = 180; ang >= 0; ang--){
            if(visitor()){
                delay(30000);  // 30 seconds pause
            }
            sprinkle.write(ang);
            delay(2000);  // 2 seconds per 1° movement
        }

        i++;
    }
}
