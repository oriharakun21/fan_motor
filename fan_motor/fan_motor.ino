// モーター用ピン
const int m_signal1P = 2;
const int m_signal2P = 3;
const int m_speedP = 4;
// モーター関連
int m_val;  //出力値:1~255

void setup(){
  Serial.begin(115200);
  Serial.println("Ready");
  pinMode(m_signal1P,OUTPUT);
  pinMode(m_signal2P,OUTPUT);
  m_val = 255;
}

void loop(){
  digitalWrite(m_signal1P,HIGH);
  digitalWrite(m_signal2P,LOW);
  switchSerial();
  Serial.print(Serial.read());
}

void switchSerial(){
  if(Serial.available()){
    int tmp=Serial.read();
    if(tmp == 1){
        analogWrite(m_speedP, m_val);
      } else {
        analogWrite(m_speedP, 0);
      }
  }
}
