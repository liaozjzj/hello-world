const int speed = 100;//调整小车速度
int right1 = 2;     //右边内侧传感器
int right2 = 10;    //右边外侧传感器
int left1 = 3;      //左边内侧传感器
int left2 = 9;      //左边外侧传感器

void setMotor(int pin1, int Speed){ //4、5，6、7分别用于控制右左两个轮子的转动，其中4、7端始终保持LOW的状态，通过5、6(pin1)控制轮子的运动
  if (Speed <= 0)
  {
    digitalWrite(pin1, LOW);        //轮子不动 
  }
  else 
  {
    analogWrite(pin1, Speed);       //轮子转动，Speed可调节速度
  }
}

void setup(){
  pinMode(right1, INPUT); //右边内侧传感器
  pinMode(left1, INPUT);  //左边内侧传感器
  pinMode(right2,INPUT);  //右边外侧传感器
  pinMode(left2,INPUT);   //左边外侧传感器
  pinMode(4, OUTPUT);     //4、5，6、7分别用于控制右左两个轮子的转动，起始设置轮子均不转
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}

void loop(){
  bool a1=digitalRead(right1), a2=digitalRead(left1), a3=digitalRead(right2), a4=digitalRead(left2);
   if ( a1 == false && a2 == false && a3 ==false && a4 ==false) {  //都没检测到黑线，两个轮子都转动，前进
    setMotor(5, speed);
    setMotor(6, speed);
    
  } else if ( a3 == true && a4 == true) {    //左右外侧传感器均检测到黑线时，停止
    setMotor(5, 0);
    setMotor(6, 0);
    delay(200);

  } else if ( a3 == true ) {   //右边外侧传感器检测到黑线
    setMotor(5, 0);            //右轮不转 
    setMotor(6, speed );       //左轮转动,右转
    delay(100);
    while ( digitalRead(left2) == false && digitalRead(left1) == false){ //在没有完全完成转弯前（左侧传感器没有检测到黑线前），继续转弯直至完成；可以实现直角转弯
      setMotor(5, 0);          //右轮不转 
      setMotor(6, speed * 1.5);//左轮更快地转动，更顺畅地完成转弯
    }
    
  } else if ( a4 == true ) {   //左边外侧传感器检测到黑线
    setMotor(6, 0);
    setMotor(5, speed );    //向左转
    delay(100);
    while ( digitalRead(right2) ==false && digitalRead(right1) == false){  //在没有完全完成转弯前（右侧传感器没有检测到黑线前），继续转弯直至完成；可以实现直角转弯
      setMotor(6, 0);
      setMotor(5, speed * 1.5);  //快速完成转弯
    }
    
  } else if (a1 == true && a2 == true) {  //仅有内侧两个传感器检测到黑线，停止
    setMotor(5, 0);
    setMotor(6, 0);
    
  } else if ( a1 == true ) { //右边外侧传感器没检测到黑线，右边内侧传感器检测到黑线
    setMotor(5, 45);
    setMotor(6, speed);      //向右微调，两只轮子都没有完全停下，提高小车行进速度
    
  } else {            //左边外侧传感器没检测到黑线，内侧检测到黑线，向左微调    
    setMotor(6, 45);
    setMotor(5, speed);
  }

}
