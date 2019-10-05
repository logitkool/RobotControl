#include <Arduino.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <FS.h>
#include <WiFiClient.h>
#include <vs-rc202.h>
#include "wifi-config.h"

#define GO 0
#define LEFT 1
#define RIGHT 2
#define BACK 3
#define STOP 4

#define SUPER_LEFT 5
#define SUPER_RIGHT 6
#define LEFT_HAND 7
#define RIGHT_HAND 8
#define LEFT_SHAKE_HEAD 9
#define RIGHT_SHAKE_HEAD 10

#define HAND 12

#define POWEROFF 11

#define go_set go, 8
#define back_set back, 8
#define left_set left, 5
#define right_set right, 5
#define super_left_set super_left, 5
#define super_right_set super_right, 5
#define left_hand_set left_hand, 2
#define right_hand_set right_hand, 2
#define hand_set hand, 2
#define left_shak_set left_shake, 2
#define right_shake_set right_shake, 2


ESP8266WebServer server(80);

int home_position[1][11] = {
  {800, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

int go[][11] = {{500, 0, 0, 800, 0, 0, 0, 0, 0, 0, 0},
  {300, -500, -500, 800, 0, 0, 0, 0, 0, 0, 0},
  {300, -500, -500, 0, 0, 0, 0, 0, 0, 0, 0},
  {300, -500, -500, -800, 0, 0, 0, 0, 0, 0, 0},
  {400, 500, 500, -800, 0, 0, 0, 0, 0, 0, 0},
  {300, 500, 500, 0, 0, 0, 0, 0, 0, 0, 0},
  {300, 0, 0, 800, 0, 0, 0, 0, 0, 0, 0},
  {800, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int left[5][11] = {
  {300, 0, 0, -600, 0, 0, 0, 0, 0, 0, 0},
  {300, 300, 0, -600, 0, 0, 0, 0, 0, 0, 0},
  {500, 300, 0, 600, 0, 0, 0, 0, 0, 0, 0},
  {300, 0, 0, 600, 0, 0, 0, 0, 0, 0, 0},
  {300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};
int right[5][11] = {
  {300, 0, 0, 800, 0, 0, 0, 0, 0, 0, 0},
  {300, 0, -300, 800, 0, 0, 0, 0, 0, 0, 0},
  {600, 0, -300, -800, 0, 0, 0, 0, 0, 0, 0},
  {300, 0, 0, -800, 0, 0, 0, 0, 0, 0, 0},
  {300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

int back[9][11] = {{500, 0, 0, -800, 0, 0, 0, 0, 0, 0, 0},
  {300, -600, -600, -800, 0, 0, 0, 0, 0, 0, 0},
  {300, -600, -600, 0, 0, 0, 0, 0, 0, 0, 0},
  {300, -600, -600, 800, 0, 0, 0, 0, 0, 0, 0},

  {400, 600, 600, 800, 0, 0, 0, 0, 0, 0, 0},

  {300, 600, 600, 0, 0, 0, 0, 0, 0, 0, 0},
  {300, 0, 0, -800, 0, 0, 0, 0, 0, 0, 0},
  {800, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
int left_shake[2][11] = {
  {800, 0, 0, 0, -1500, 0, 0, 0, 0, 0, 0},
  {800, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};
int right_shake[2][11] = {
  {800, 0, 0, 0, 1500, 0, 0, 0, 0, 0, 0},
  {800, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};
//--------TODO-------------
int right_hand[2][11] = {
  {800, 0, 0, 0, 0, 1300, 0, 0, 0, 0, 0},
  {800, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
int left_hand[2][11] = {
  {800, 0, 0, 0, 0, 0, -1300, 0, 0, 0, 0},
  {800, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int hand[2][11] = {{800, 0, 0, 0, 0, 1300, -1300, 0, 0, 0, 0},
  {800, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
//--------------------------

int super_right[5][11] = {
  {300, 0, 0, 600, 0, 0, 0, 0, 0, 0, 0},
  {300, 0, -450, 600, 0, 0, 0, 0, 0, 0, 0},
  {500, 0, -450, -600, 0, 0, 0, 0, 0, 0, 0},
  {300, 0, 0, -600, 0, 0, 0, 0, 0, 0, 0},
  {300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};
int super_left[5][11] = {
  {300, 0, 0, -600, 0, 0, 0, 0, 0, 0, 0},
  {300, 450, 0, -600, 0, 0, 0, 0, 0, 0, 0},
  {500, 450, 0, 600, 0, 0, 0, 0, 0, 0, 0},
  {300, 0, 0, 600, 0, 0, 0, 0, 0, 0, 0},
  {300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

void selectMotion() {
  switch (getMotionNumber()) {
    case GO:
      playMotionOnce(go_set);
      break;
    case LEFT:
      playMotionOnce(left_set);
      break;
    case RIGHT:
      playMotionOnce(right_set);
      break;
    case BACK:
      playMotionOnce(back_set);
      break;
    case STOP:
      stopServo();
      delay(200);
      playMotionOnce(home_position, 1);
      break;
    case SUPER_LEFT:
      playMotionOnce(super_left_set);
      break;
    case SUPER_RIGHT:
      playMotionOnce(super_right_set);
      break;
    case RIGHT_HAND:
      playMotionOnce(right_hand_set);
      break;
    case LEFT_HAND:
      playMotionOnce(left_hand_set);
      break;
    case HAND:
      playMotionOnce(hand_set);
      break;
    case RIGHT_SHAKE_HEAD:
      playMotionOnce(right_shake_set);
      break;
    case LEFT_SHAKE_HEAD:
      playMotionOnce(left_shak_set);
      break;
  }
}

// Send UI page
void handleRoot() { server.send(200, "text/html", "Stand_by"); }

void Go() {
  setMotionNumber(GO);
  Serial.println("Go");
  server.send(200, "text/html", "Go");
}

void Left() {
  setMotionNumber(LEFT);
  Serial.println("Left");
  server.send(200, "text/html", "Left");
}

void Right() {
  setMotionNumber(RIGHT);
  Serial.println("Right");
  server.send(200, "text/html", "Right");
}

void Back() {
  setMotionNumber(BACK);
  Serial.println("Back");
  server.send(200, "text/html", "Back");
}

void Stop() {
  setMotionNumber(STOP);
  Serial.println("Stop");
  server.send(200, "text/html", "Stop");
}

void PowerOff() {
  Serial.println("--------OFF--------");
  server.send(200, "text/html", "POWEROFF");
  powerOff();
}

void Super_left() {
  setMotionNumber(SUPER_LEFT);
  server.send(200, "text/html", "super_left");
}
void Super_right() {
  setMotionNumber(SUPER_RIGHT);
  server.send(200, "text/html", "super_right");
}
void Left_hand() {
  setMotionNumber(LEFT_HAND);
  server.send(200, "text/html", "left_hand");
}
void Right_hand() {
  setMotionNumber(RIGHT_HAND);
  server.send(200, "text/html", "right_hand");
}
void Hand() {
  setMotionNumber(HAND);
  server.send(200, "text/html", "hand");
}
void Left_shake() {
  setMotionNumber(LEFT_SHAKE_HEAD);
  server.send(200, "text/html", "left_shake");
}
void Right_shake() {
  setMotionNumber(RIGHT_SHAKE_HEAD);
  server.send(200, "text/html", "right_shake");
}
void Led_on(){
  setLedBrightnessDirect(9,1000);   //Turn on LED
  setLedBrightnessDirect(10,1000);
}

void Sens() {

  int sens_data[3];

  // Sensor data from lpc
  int data1 = readSens(1);
  int data2 = readSens(2);
  int data3 = readSens(3);

  // Sonic sensor data
  double dist = getDist();

  // Power supply voltage
  int power = readPow();

  // Convert numeric to string
  String st_data1 = String(data1);
  String st_data2 = String(data2);
  String st_data3 = String(data3);
  String st_data4 = String(dist);
  String st_data5 = String(power);

  String res = String(st_data1 + "," + st_data2 + "," + st_data3 + "," +
      st_data4 + "," + st_data5);
  server.send(200, "text/html", res);
}

void setup() {

  // debug
  Serial.begin(115200);
  delay(500);

  // Init robot lib
  initLib();
  delay(10);

  // SV1 - 4 servo mode
  servoEnable(1, 1); // Enable SV1 PWM
  servoEnable(2, 1); // Enable SV2 PWM
  servoEnable(3, 1); // Enable SV3 PWM
  servoEnable(4, 1); // Enable SV4 PWM
  servoEnable(5, 1); // Enable SV4 PWM
  servoEnable(6, 1); // Enable SV4 PWM

  // SV9 and SV10 LED mode
  servoEnable(9, 1);  // Enable SV9 PWM
  servoEnable(10, 1); // Enable SV10 PWM
  setLedMode(9, 1);   // Set SV9 LED mode
  setLedMode(10, 1);  // Set SV10 LED mode

  // Offset
  setServoOffset(1, -139);
  setServoOffset(2, 0);
  setServoOffset(3, -200);
  setServoOffset(4, 0);
  WiFi.config(IPAddress(192, 168, 11, 250), IPAddress(192, 168, 11, 1),
      IPAddress(255, 255, 255, 0));
  // Connect to AP
  WiFi.begin(ssid, password);
  WiFi.mode(WIFI_STA);
  Serial.println("Connecting to Access Point");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WiFi.SSID());
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Set function
  server.on("/", handleRoot);
  server.on("/go/", Go);
  server.on("/left/", Left);
  server.on("/right/", Right);
  server.on("/back/", Back);
  server.on("/stop/", Stop);
  server.on("/super_left/", Super_left);
  server.on("/super_right/", Super_right);
  server.on("/left_hand/", Left_hand);
  server.on("/right_hand/", Right_hand);
  server.on("/hand/", Hand);
  server.on("/left_shake/", Left_shake);
  server.on("/right_shake/", Right_shake);
  server.on("/poweroff/", PowerOff);
  server.on("/led/", Led_on);
  server.on("/sens/", Sens);

  // Start server
  server.begin();
}

void loop() {

  server.handleClient();
  // Play motion
  selectMotion();
}
