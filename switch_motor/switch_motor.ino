#define SWITCH_P1 2
#define SWITCH_P2 6
#define SWITCH_N1 3
#define SWITCH_N2 7

void setup() {
  Serial.begin(9600);
  Serial.println(F("Motor Switching experiment"));
  pinMode(SWITCH_P1, OUTPUT);
  pinMode(SWITCH_P2, OUTPUT);
  pinMode(SWITCH_N1, OUTPUT);
  pinMode(SWITCH_N2, OUTPUT);
  digitalWrite(SWITCH_P1,LOW);
  digitalWrite(SWITCH_P2,LOW);
  digitalWrite(SWITCH_N1,LOW);
  digitalWrite(SWITCH_N2,LOW);
}
void allLow(){
  digitalWrite(SWITCH_P1,LOW);
  digitalWrite(SWITCH_P2,LOW);
  digitalWrite(SWITCH_N1,LOW);
  digitalWrite(SWITCH_N2,LOW);
  Serial.println("Switched all off");
}
void loop() {
  //delay(15000);
  int rec=-1;
  if(Serial.available()>0){
    rec = Serial.read();
    Serial.println(rec);
    allLow();
    if (rec==98){
      digitalWrite(SWITCH_P1,HIGH);
      Serial.println("Switched on P1 and N2");
      digitalWrite(SWITCH_N2,HIGH);
    }
    else if(rec==100){
      digitalWrite(SWITCH_P2,HIGH);
      Serial.println("Switched on P2 and N1");
      digitalWrite(SWITCH_N1,HIGH);
    }
    //Serial.flush();
  }
}
