void setup(){
  pinMode(1,OUTPUT); //信号用ピン 6番ピン
  pinMode(2,OUTPUT); //信号用ピン 5番ピン
}

void loop(){
  int val = 200;

  // 5番ピンをHIGH, 6番ピンをLOW
  digitalWrite(1,LOW);
  digitalWrite(2,HIGH);

  //valが大きいほど出力値も大きくなる
  analogWrite( 3 , val ); //出力値:1~255
}
