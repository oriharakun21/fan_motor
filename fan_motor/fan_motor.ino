/*
 * 2018/6/6 オリハラ
 * fan_motor
 * モーターを回転させるだけのシステム
 */
 
// モーター用ピン
const int m_signal1P = 2;
const int m_signal2P = 3;
const int m_speedP = 4;
// そのた
const int in_m_controlP = 5;

void setup(){
  pinMode(m_signal1P,OUTPUT);
  pinMode(m_signal2P,OUTPUT);
  pinMode(in_m_controlP,INPUT);
}

void loop(){
  int val = 180;

  digitalWrite(m_signal1P,HIGH);
  digitalWrite(m_signal2P,LOW);

  if(digitalRead(in_m_controlP) == HIGH){
    analogWrite(m_speedP, val); //出力値:1~255
  }else{
    analogWrite(m_speedP, 0); //出力値:1~255
  }
}
