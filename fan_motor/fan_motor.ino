#include <SoftwareSerial.h>
// rx, tx
SoftwareSerial btport(4, 5);

// モーター用ピン
const int m_signal1P = 2;
const int m_signal2P = 3;
const int m_speedP = 6;
// モーター関連
int s_tmp;


void setup(){
  Serial.begin(9600);
  btport.begin(38400);
  
  pinMode(m_signal1P,OUTPUT);
  pinMode(m_signal2P,OUTPUT);
  s_tmp=0;

  digitalWrite(m_signal1P,HIGH);
  digitalWrite(m_signal2P,LOW);
}

void loop(){
  while(btport.available()){
    s_tmp=int(btport.read());
  }

  switchSerial();
  delay(50);
}

void switchSerial(){
  if(s_tmp == 49){
      analogWrite(m_speedP, 75);
    } else if(s_tmp == 50){
      analogWrite(m_speedP, 160);
    } else if(s_tmp == 51){
      analogWrite(m_speedP, 255);
    } else {
      analogWrite(m_speedP, 0);
    }
}
