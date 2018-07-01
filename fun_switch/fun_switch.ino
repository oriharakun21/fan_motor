#include <SoftwareSerial.h>
SoftwareSerial btport(2, 3);

// スイッチ
int state; // 0 オフ 1　オン
int s_val, s_old_val;
int in_m_controlP=4;

void setup() {
  Serial.begin(9600);
  btport.begin(38400);
  pinMode(in_m_controlP,INPUT);
}

void loop(){
  swtchChange();

  while(btport.available()){
    Serial.write(btport.read());
  }
  while(Serial.available()){
    btport.write(Serial.read());
  }
delay(200);
}

// スイッチ（バウンジング対策済み）
void swtchChange(){
  s_val = digitalRead(in_m_controlP);
  if(s_val == HIGH && s_old_val == LOW){
    state = 1 - state;
    delay(30);
  }
  if(state==1){
    btport.write('1');
  } else {
    btport.write('0');
  }
  
  s_old_val = s_val;
}
