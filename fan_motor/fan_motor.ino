#include <SoftwareSerial.h>
// rx, tx
SoftwareSerial btport(5, 6);

// モーター用ピン
const int m_signal1P = 2;
const int m_signal2P = 3;
const int m_speedP = 4;
// モーター関連
int m_val;  //出力値:1~255
int s_tmp;


void setup(){
  Serial.begin(9600);
  btport.begin(38400);
  
  pinMode(m_signal1P,OUTPUT);
  pinMode(m_signal2P,OUTPUT);
  m_val = 140;
  s_tmp=0;
}

void loop(){
  digitalWrite(m_signal1P,HIGH);
  digitalWrite(m_signal2P,LOW);

  while(btport.available()){
    s_tmp=int(btport.read());
  }

  switchSerial();
  delay(50);
}

void switchSerial(){
  if(s_tmp == 49){
      analogWrite(m_speedP, m_val);
    } else {
      analogWrite(m_speedP, 0);
    }
}
