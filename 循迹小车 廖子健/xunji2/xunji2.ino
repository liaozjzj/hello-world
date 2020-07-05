const int speed = 70;
int right = 2;      //右侧传感器接收端
int left = 3;       //左侧传感器接收端

void setMotor(int pin1, int Speed){    //4、5，6、7分别用于控制右左两个轮子的转动，4，7端始终保持LOW的状态，通过5、6(pin1)控制轮子的运动，Speed可调整轮子转速  
  if (Speed <= 0){
    digitalWrite(pin1, LOW);     //轮子不转
  }
  else {
    analogWrite(pin1, Speed);    //轮子转动
  }
}

void setup(){
  pinMode(right, INPUT);//右边传感器
  pinMode(left, INPUT); //左边传感器
  pinMode(5, OUTPUT);   //4、5，6、7控制两个轮子转动，4、5控制右侧车轮
  pinMode(4, OUTPUT);  
  pinMode(6, OUTPUT);   //6、7控制左侧车轮
  pinMode(7, OUTPUT);
  digitalWrite(4, LOW); //初始设置为不转
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}

void loop(){
  if (digitalRead(right) == true && digitalRead(left) == false) {         //右边检测到黑线，向右转
    setMotor(5, 0);       //右侧车轮不转
    setMotor(6, speed);   //左侧车轮转动，实现右转

  } else if (digitalRead(right) == false && digitalRead(left) == true) {  //左边检测到黑线，向左转
    setMotor(5, speed);
    setMotor(6, 0);
    
  } else if (digitalRead(left) == false && digitalRead(right) == false) { //两边都没有检测到黑线，前进
    setMotor(5, speed);
    setMotor(6, speed);
    
  } else {   //都检测到黑线，停止
    setMotor(5, 0);
    setMotor(6, 0);

  }

}
