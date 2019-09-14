#include <vs-rc202.h>
#include "motion.hpp"
#include "number.hpp"

int sonicSensor;
                 
void selectMotion()
{
  switch(getMotionNumber())
  {              
    case STOP:
      playMotionOnce(stopMotion, 1);
      break;
    case rGO:
      playMotionOnce(goStepRight, 3);
      break;
    case lGO:
      playMotionOnce(goStepLeft, 3);
      break;
    case rBACK:
      playMotionOnce(backStepRight, 3);
      break;
    case lBACK:
      playMotionOnce(backStepLeft, 3);
      break;
    case RIGHT45:
      playMotionOnce(turningRight45, 10);
      break;
    case RIGHT90:
      playMotionOnce(turningRight90, 20);
      break;
    case LEFT45:
      playMotionOnce(turningLeft45, 10);
      break;
    case LEFT90:
      playMotionOnce(turningLeft90, 20);
      break;      
    case rHAND:
      playMotionOnce(waveRightHand, 3);
      break;
    case lHAND:
      playMotionOnce(waveLeftHand, 3);
      break;
    case bHAND:
      playMotionOnce(waveBothHand, 3);
      break;
    case rFACE:
      playMotionOnce(turnRight, 1);
      break;
    case lFACE:
      playMotionOnce(turnLeft, 1);
      break;
  }
}

void goSelect() //進ませる足を決定する
{
  if(readServoPos(1) > -300)
  {
    setMotionNumber(rGO); //右足
  }
  else
  {
    setMotionNumber(lGO); //左足
  }
}

void backSelect() //goSelect()とほぼ同じ
{
  if(readServoPos(2) < -300)
  {
    setMotionNumber(rBACK);
  }
  else
  {
    setMotionNumber(lBACK);
  }
}

void getCommand()
{ 
  if(Serial.available())
  {
    char a = Serial.read(); //シリアルモニタからコマンドを受け取る

    switch(a)
    {              
      case 'x':
        setMotionNumber(STOP);
        break;
      case 'w':
        goSelect();
        break;
      case 's':
        backSelect();
        break;
      case 'h':
        setMotionNumber(RIGHT45);
        break;
      case 'j':
        setMotionNumber(RIGHT90);
        break;
      case 'g':
        setMotionNumber(LEFT45);
        break;
      case 'f':
        setMotionNumber(LEFT90);
        break;
      case 'u':
        setMotionNumber(rHAND);
        break;
      case 't':
        setMotionNumber(lHAND);
        break;
      case 'y':
        setMotionNumber(bHAND);
        break;
      case 'p':
        setMotionNumber(rFACE);
        break;
      case 'o':
        setMotionNumber(lFACE);
        break;
    }

    Serial.print(a);
    Serial.println();
    Serial.println("Enter Command w, a, s, d, x");
    Serial.print("$>");
  }
}

void setup()
{
  initLib();                //Initilize vs-rc202 library
  
  servoEnable(1, 1);        //Enable SV1 PWM
  servoEnable(2, 1);        //Enable SV2 PWM
  servoEnable(3, 1);        //Enable SV3 PWM
  servoEnable(4, 1);        //Enable SV4 PWM
  servoEnable(5, 1);        //Enable SV3 PWM
  servoEnable(6, 1);        //Enable SV4 PWM

  Serial.begin(115200);     //Initialize UART
}

void loop()
{
  getCommand(); //コマンドを受け取ってピッコロボの動きを決める
  selectMotion(); //ピッコロボを動かす
}
