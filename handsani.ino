#include <Servo.h>
Servo dis;
const int ldr = A0;
const int temp = A1;
const int buzz = 2;
void setup(){
    dis.attach(9);
    pinMode(ldr, INPUT);
    pinMode(temp, INPUT);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    pinMode(buzz, OUTPUT);
    Serial.begin(9600);
}

float gettemp(){
    float volt = analogRead(temp);
    float tmp = (volt * 5 /1024);
    tmp = (tmp - 0.5)*100;
    return tmp;
}

void alarm(){
   digitalWrite(buzz, HIGH);
   delay(30);
   digitalWrite(buzz, LOW);
   delay(30);
}

void loop(){
    int light = analogRead(ldr);
        if(light < 150 ){
            float t = gettemp();
            if(t <= 37.5 && t >= 36.5){
                for(int ang = 0; ang <= 90; ang ++){
                    dis.write(ang);
                }
                for(int ang = 90; ang >=0; ang--){
                    dis.write(ang);
                }
            else{
                for(int i = 0; i < 5; i++){
                    alarm();
                }
            }
        }
    }
}
