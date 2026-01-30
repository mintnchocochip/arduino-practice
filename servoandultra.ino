#include <servo.h>
Servo sprinkle;
const int trig = 10;
const int echo = 11;
long duration;
int distance;

void setup(){
    sprinkle.attach(9,0,180);
    pinMode(trig, INPUT);
    pinMode(echo, OUTPUT);
    serial.begin(9600);
}

bool visitor(){
    digitalWrite(trig, LOW);
    delay(2);
    digitalWrite(trig, HIGH);
    delay(10);
    digitalWrite(trig, LOW);
    duration = pulseInt(echo,LOW);
    distance = (duration * 0.0343)/2;
    if(distance >= 0.8){
        return false;
    }else{
        return true;
    }
}

void loop(){
    delay(8*60*60*100);
    int i = 0;
    while(i < 15){
        if(visitor()){delay(300);}
        for (int ang = 0; ang <= 180; ang++){
            while(visitor()){delay(300);}
            sprinkle.write(ang);
        }
        sprinkle.write(0);
        i++;
    }
}
