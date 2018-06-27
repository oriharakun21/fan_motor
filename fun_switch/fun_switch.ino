// スイッチ
int state; // 0 オフ 1　オン
int s_val, s_old_val;
int in_m_controlP=3;

void setup() {
  Serial.begin(115200);
  pinMode(in_m_controlP,INPUT);
}

void loop() {
  swtchChange();
  Serial.print(state);
}

// スイッチ（バウンジング対策済み）
void swtchChange(){
  s_val = digitalRead(in_m_controlP);
  if(s_val == HIGH && s_old_val == LOW){
    state = 1 - state;
    delay(10);
  }
  s_old_val = s_val;
}
