Servo turret;
int pos = 0;
int motionSensor = 7;
int laser = 10;

void setup() {
  turret.attach(9);
  pinMode(motionSensor, INPUT);
  pinMode(laser, OUTPUT);
}

void loop() { 
  for(pos = 0; pos <= 180; pos += 1){
    if(digitalRead(motionSensor)){
      digitalWrite(laser,HIGH);
      delay(100);
      digitalWrite(laser,LOW);
    }
    turret.write(pos);
    delay(15);
  }
  for(pos = 180; pos >= 0; pos -= 1){
    if(digitalRead(motionSensor)){
      digitalWrite(laser,HIGH);
      delay(100);
      digitalWrite(laser,LOW);
    }
    turret.write(pos);
    delay(15);
  }
}