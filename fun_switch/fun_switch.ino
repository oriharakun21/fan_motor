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
  state=0; // 初期値
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
    state++;
    if(state==4){
      state=0;
    }
    delay(30);
  }
  switch(state){
    case 1:
    btport.write('1');
    break;
    case 2:
    btport.write('2');
    break;
    case 3:
    btport.write('3');
    break;
    default:
    btport.write('0');
    break;
  }
  
  s_old_val = s_val;
}
