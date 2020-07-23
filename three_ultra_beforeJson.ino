
// JSON 객체 선언 (동적 메모리 할당, 정적 메모리 할당하고자 할 경우 Dynamic => Static 변경)

/*
 * 초음파 센서 3개를 사용해 측정하기.
 */
int trig1 = 2;
int echo1 =  3;

int trig2= 4;
int echo2 = 5;

const int trig3 = 8;
const int echo3 =  9;

long duration1, distance1, duration2,distance2, duration3,distance3;

void setup () {
  // 초음파센서의 동작 상태를 확인하기 위하여 시리얼 통신을 설정(전송속도 9600bps)
  Serial.begin(9600);
  //초음파 송신부-> OUTPUT, 초음파 수신부 -> INPUT
  pinMode(trig1,OUTPUT);
  pinMode(echo1,INPUT);
  pinMode(trig2,OUTPUT);
  pinMode(echo2,INPUT);

  pinMode(trig3,OUTPUT);
  pinMode(echo3,INPUT);
}



void loop() {
  long duration;

  digitalWrite(trig1,LOW);
  delayMicroseconds(2);
  digitalWrite(trig1,HIGH);
  delayMicroseconds(5);
  digitalWrite(trig1,LOW);
  duration1= pulseIn(echo1, HIGH);

  digitalWrite(trig2,LOW);
  delayMicroseconds(2);
  digitalWrite(trig2,HIGH);
  delayMicroseconds(5);
  digitalWrite(trig2,LOW);
  duration2= pulseIn(echo2, HIGH);

  digitalWrite(trig3,LOW);
  delayMicroseconds(2);
  digitalWrite(trig3,HIGH);
  delayMicroseconds(5);
  digitalWrite(trig3,LOW);
  duration3= pulseIn(echo3, HIGH);

  //초음파는 29마이크로초 당 1센치를 이동
  //초음파의 이동 거리 = duration(왕복에 걸린시간) / 29 / 2
  distance1 = (duration1/2)/29;
  distance2 = (duration2/2)/29;
  distance3 = (duration3/2)/29;

  Serial.print(" col1 : ");
  Serial.println(distance1 );
  Serial.print(" col2 :  ");
  Serial.println(distance2 );
  Serial.print(" col3 : ");
  Serial.println(distance3 );
 
  delay(2000);

}
