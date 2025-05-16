#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN   11      // WS2812 接在 D11
#define LED_COUNT 7

#define BAUDRATE 9600

#define SERVOMIN 60      // 0 度脈衝
#define SERVOMAX 580     // 180 度脈衝

print("hello world!")

char val;
int R_back[] = {0,1,2};
int L_back[] = {4,5,6};
int R_front[] = {8,9,10};
int L_front[] = {12,13,14};
int head[] = {7}; 
int test_servo[] = {11};

Adafruit_PWMServoDriver myServo = Adafruit_PWMServoDriver();
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN);

void setup() {
  Serial.begin(BAUDRATE);

  myServo.begin();
  myServo.setPWMFreq(50);  // 設定伺服 PWM 頻率
  
  strip.begin();       // 初始化燈條
  strip.show();        // 關閉所有 LED

  val = 't';
}

void loop() {
  if (Serial.available()) {
    char incoming = Serial.read();
    if (isAlpha(incoming)) {
      val = toupper(incoming);
      Serial.print("收到指令: ");
      Serial.println(val);
    }
  }

  switch (val) {
    case 'A':
      Serial.println("動作 A : 全腳位初始化");
      initialized();
      val = 'n';
      break;

    case 'B':
      Serial.println("動作 B : 站立");
      stand();
      val = 'n';
      break;

    case 'C':
      Serial.println("動作 C: 燈光開啟");
      white_light_open();
      val = 'n';
      break;

    case 'D':
      Serial.println("動作 D: 燈光關閉");
      light_close();
      val = 'n';
      break;

    case 'Z':
      Serial.println("動作 Z: ZERO");
      initialized();
      val = 'n';
      break;

    case 'T':
      Serial.println("動作 T: 測試");
      moveServo(11,90 );
      val = 'n';
      break;

    case 'J':
      Serial.println("動作 J: 轉向_邊");
      head_left();
      val = 'n';
      break;
    
    case 'K':
      Serial.println("動作 K: 看前面");
      head_zero();
      val = 'n';
      break;

    case 'L':
      Serial.println("動作 L: 轉向_邊");
      head_right();
      val = 'n';
      break;

    default:
      break;
  }

  delay(100);
}

// ===================== 燈光控制區塊 =====================
// 內容已移至 light_function.ino

// ===================== 腳部與頭部控制區塊 =====================
// 內容已移至 legs_function.ino

// 頭部
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

// 腳部
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
