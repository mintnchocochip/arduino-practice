#include <Servo.h>
Servo DSM;
Servo CSM;
const int trig(7);
const int echo(8);
const int pot = A0;

void setup(){
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    pinMode(pot, INPUT);
    DSM.attach(9);
    CSM.attach(10);
    Serial.begin(9600);
}

bool US(){
   digitalWrite(trig, LOW);
   delay(2);
   digitalWrite(trig, HIGH);
   delay(10);
   digitalWrite(trig, LOW);
   long time = pulseIn(echo, HIGH);
   long distance = time * 343 / 20000; //distance in cm
   if(distance <= 8){
       return true;
   }
   else{
       return false;
   }
}

int POT(){
    int p = analogRead(pot);
    if( p >= 1023 ){
        return 180;
    }
    else if( p >= 512 ){
        return 90;
    }
    else{
        return 45;
    }
}

void loop(){
    if(US()){
        DSM.write(180);  // Open door
        delay(1000);
        DSM.write(127);  // Close door
    }
    else{
        DSM.write(90);   // Keep closed
    }

    CSM.write(POT());  // Coolant flow control
    delay(100);
}
