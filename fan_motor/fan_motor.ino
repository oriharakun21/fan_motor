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
// モーター関連
int m_val;  //出力値:1~255
// スイッチ
int state; // 0 オフ 1　オン
int s_val, s_old_val;

void setup(){
  pinMode(m_signal1P,OUTPUT);
  pinMode(m_signal2P,OUTPUT);
  pinMode(in_m_controlP,INPUT);
  m_val = 255;
}

void loop(){
  digitalWrite(m_signal1P,HIGH);
  digitalWrite(m_signal2P,LOW);
  swtchChange();
}
// スイッチ（バウンジング対策済み）
void swtchChange(){
  s_val = digitalRead(in_m_controlP);
  if(s_val == HIGH && s_old_val == LOW){
    state = 1 - state;
    delay(10);
  }
  s_old_val = s_val;
  if(state == 1){
    analogWrite(m_speedP, m_val);
  } else {
    analogWrite(m_speedP, 0);
  }
}
