int pinSW =2;
void setup() {
  
  Serial.begin(9600);                                                      // 시리얼 통신을 시작, 통신속도는 (9600)
  pinMode(pinSW, INPUT);                                                    // 디지털 3번 핀을 입력모드로 설정
}
void loop() {
  int a = digitalRead(pinSW);                                                // 정수형 변수 a를 생성한 후 디지털 3번핀에 입력되는 신호를 입력
  Serial.println("Vibration Sensing!");                            // 시리얼 모니터에 "Vibration Sensing!" 를 출력
  Serial.println(a);
  delay(2000);                                                            // 2초간 대기
  /*
  if (a == LOW) {                                                         // a가 LOW (0)이면
    Serial.println("Vibration Sensing!");                            // 시리얼 모니터에 "Vibration Sensing!" 를 출력
    delay(2000);                                                            // 2초간 대기
  }
  else {                                                                         // 그게 아니라면 (a가 LOW가 아니라면)
    delay(1000);
    Serial.println("Nothing");                                            // 시리얼 모니터에 "Nothing"을 입력
  }*/
}
