// 腳部與頭部控制區塊
#include "global.h"

//轉換脈衝與角度
void moveServo(int channel, int angle) {
  int pulse = map(angle, 0, 180, SERVOMIN, SERVOMAX);
  myServo.setPWM(channel, 0, pulse);
}

//頭部控制區塊
void head_zero(){
  Serial.println("head zero");
  myServo.setPWM(head[0], 0, 320);
  delay(50);
}

void head_left(){
  myServo.setPWM(head[0], 0, 450);
  Serial.println("head left!");
  delay(50);
}

void head_right(){ 
  myServo.setPWM(head[0], 0, 190);
  Serial.println("head right!");
  delay(50);
}

//腳部控制區塊
void initialized(){
  //右後方
  Serial.println("RB,initialized...");
  myServo.setPWM(R_back[0], 0, 320);//#0
  delay(50);
  myServo.setPWM(R_back[1], 0, 320);//#1
  delay(50);
  myServo.setPWM(R_back[2], 0, 493);//#2
  delay(1000);
  Serial.println("RB,done!!!");

  delay(1000);

  //左後方
  Serial.println("LB,initialized...");
  myServo.setPWM(L_back[0], 0, 320);//#4
  delay(50);
  myServo.setPWM(L_back[1], 0, 350);//#5
  delay(50);
  myServo.setPWM(L_back[2], 0, 147);//#6
  delay(1000);
  Serial.println("LB,done!!!");

  delay(1000);

  //右前方
  Serial.println("RF,initialized...");
  myServo.setPWM(R_front[0], 0, 320);//#8
  delay(50);
  myServo.setPWM(R_front[1], 0, 330);//#9
  delay(50);
  myServo.setPWM(R_front[2], 0, 493);//#10
  delay(1000);
  Serial.println("RF,done!!!");

  delay(1000);

  //左前方
  Serial.println("LF,initialized...");
  myServo.setPWM(L_front[0], 0, 320);//#12
  delay(50);
  myServo.setPWM(L_front[1], 0, 350);//#13
  delay(50);
  myServo.setPWM(L_front[2], 0, 160);//#14
  delay(1000);
  Serial.println("LF,done!!!");
}

void stand(){
  Serial.println("standing...");
  myServo.setPWM(R_back[0], 0, 320);//#0
  delay(50);
  myServo.setPWM(R_back[1], 0, 440);//#1
  delay(50);
  myServo.setPWM(R_back[2], 0, 520);//#2
  delay(50);

  myServo.setPWM(L_back[0], 0, 320);//#4
  delay(50);
  myServo.setPWM(L_back[1], 0, 350);//#5
  delay(50);
  myServo.setPWM(L_back[2], 0, 120);//#6
  delay(1000);

  /*myServo.setPWM(R_front[0], 0, 320);//#8
  delay(50);
  myServo.setPWM(R_front[1], 0, 450);//#9
  delay(50);
  myServo.setPWM(R_front[2], 0, 500);//#10*/

  delay(2000);
  Serial.println("done!");
}
