#define Kp_wf 50 // experiment to determine this, start by something small that just makes your bot follow the line at a slow speed 80
#define Kd_wf 90 // experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd) 50
#define rightMaxSpeed_wf 245 // max speed of the robot
#define leftMaxSpeed_wf 255 // max speed of the robot
#define rightBaseSpeed_wf 130 // this is the speed at which the motors should spin when the robot is perfectly on the line
#define leftBaseSpeed_wf 140 // this is the speed at which the motors should spin when the robot is perfectly on the line
#define NUM_SENSORS_wf 1   // number of sensors used
#define TIMEOUT_wf       2500  // waits for 2500 us for sensor outputs to go low
#define EMITTER_PIN_wf  2     // emitter is controlled by digital pin 2
#define set_point_wf 5
#define rightMotor1_wf 2
#define rightMotor2_wf 4
#define rightMotorPWM_wf 3
#define leftMotor1_wf 5
#define leftMotor2_wf 7
#define leftMotorPWM_wf 6

#define Kp 70 // experiment to determine this, start by something small that just makes your bot follow the line at a slow speed 80
#define Kd 120 // experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd) 50
#define rightMaxSpeed 245 // max speed of the robot
#define leftMaxSpeed 255 // max speed of the robot
#define rightBaseSpeed 140 // this is the speed at which the motors should spin when the robot is perfectly on the line
#define leftBaseSpeed 150// this is the speed at which the motors should spin when the robot is perfectly on the line
#define NUM_SENSORS  3     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 us for sensor outputs to go low
#define EMITTER_PIN   2     // emitter is controlled by digital pin 2
#define set_point 0
#define rightMotor1 2
#define rightMotor2 4
#define rightMotorPWM 3
#define leftMotor1 5
#define leftMotor2 7
#define leftMotorPWM 6

#define ir2 A2
#define ir3 A3
#define ir4 A4



#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
//#define motorPower 8
 
double SonarF;
double SonarR;
 float getDistance(int trig, int echo){ 
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  pinMode(echo, INPUT);
  return pulseIn(echo, HIGH, 30000) / 58.0;
}


void setup()
{
 Serial.begin(9600);
  pinMode(rightMotor1_wf, OUTPUT);
  pinMode(rightMotor2_wf, OUTPUT);
  pinMode(rightMotorPWM_wf, OUTPUT);
  pinMode(leftMotor1_wf, OUTPUT);
  pinMode(leftMotor2_wf, OUTPUT);
  pinMode(leftMotorPWM_wf, OUTPUT);
 
    SonarR = getDistance(8, 9);
    SonarR = getDistance(12, 13);
//  pinMode(motorPower, OUTPUT);


  Serial.begin(9600);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(rightMotorPWM, OUTPUT);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(leftMotorPWM, OUTPUT);
    pinMode(A0+2,INPUT);
    pinMode(A0+3,INPUT);
    pinMode(A0+4,INPUT);
double ir2;
double ir3;
double ir4;
//  pinMode(motorPower, OUTPUT);
  
 
  } 
int lastError_wf = 0;
int lastError = 0;

void loop()
{
  
  double SonarR_test = read_sensor_wf ();
  //double SonarF_test = read_sensor_wf ();
  
  if((SonarR_test<10))
  {
    
    Serial.println("obstacle");
    unsigned int sensors[2];
    
  int current_position_wf = read_sensor_wf(); // get calibrated readings along with the line position, refer to the QTR Sensors Arduino Library for more details on line position.
   
  int error_wf = set_point_wf-current_position_wf;

  double motorSpeed_wf = Kp * error_wf + Kd * (error_wf - lastError_wf)*0.0001;
  lastError_wf = error_wf;

  //Serial.print("motorSpeed");Serial.print("=");Serial.println(motorSpeed);

  double rightMotorSpeed_wf = rightBaseSpeed_wf + motorSpeed_wf;
  double leftMotorSpeed_wf = leftBaseSpeed_wf - motorSpeed_wf;
 
    if (rightMotorSpeed_wf > rightMaxSpeed_wf ) rightMotorSpeed_wf = rightMaxSpeed_wf; // prevent the motor from going beyond max speed
  if (leftMotorSpeed_wf > leftMaxSpeed_wf ) leftMotorSpeed_wf = leftMaxSpeed_wf; // prevent the motor from going beyond max speed
  if (rightMotorSpeed_wf < 0) rightMotorSpeed_wf = 0; // keep the motor speed positive
  if (leftMotorSpeed_wf < 0) leftMotorSpeed_wf = 0; // keep the motor speed positive
  
   {
//  digitalWrite(motorPower, HIGH); // move forward with appropriate speeds
  digitalWrite(rightMotor1_wf, HIGH);
  digitalWrite(rightMotor2_wf, LOW);
  analogWrite(rightMotorPWM_wf, rightMotorSpeed_wf);
//  digitalWrite(motorPower, HIGH);
  digitalWrite(leftMotor1_wf, HIGH);
  digitalWrite(leftMotor2_wf, LOW);
  analogWrite(leftMotorPWM_wf, leftMotorSpeed_wf);
}
  }
  else
  {
    unsigned int sensors[3];
  int current_position = read_ir(); // get calibrated readings along with the line position, refer to the QTR Sensors Arduino Library for more details on line position.
  int error = set_point-current_position;

  double motorSpeed = Kp * error + Kd * (error - lastError)*0.0001;
  lastError = error;

  //Serial.print("motorSpeed");Serial.print("=");Serial.println(motorSpeed);

  double rightMotorSpeed = rightBaseSpeed + motorSpeed;
  double leftMotorSpeed = leftBaseSpeed - motorSpeed;
  
    if (rightMotorSpeed > rightMaxSpeed ) rightMotorSpeed = rightMaxSpeed; // prevent the motor from going beyond max speed
  if (leftMotorSpeed > leftMaxSpeed ) leftMotorSpeed = leftMaxSpeed; // prevent the motor from going beyond max speed
  if (rightMotorSpeed < 0) rightMotorSpeed = 0; // keep the motor speed positive
  if (leftMotorSpeed < 0) leftMotorSpeed = 0; // keep the motor speed positive
  
   {
//  digitalWrite(motorPower, HIGH); // move forward with appropriate speeds
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  analogWrite(rightMotorPWM, rightMotorSpeed);
//  digitalWrite(motorPower, HIGH);
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  analogWrite(leftMotorPWM, leftMotorSpeed);
}
    
  }
}
 
int read_ir()
{
 
  int ir2_map;
  int ir3_map;
  int ir4_map;
double    ir2 = analogRead(A0+2);
double    ir3 = analogRead(A0+3);
double    ir4 = analogRead(A0+4);

  //Serial.print("ir2");Serial.print("=");Serial.println(ir2);
   //Serial.print("ir3");Serial.print("=");Serial.println(ir3);
    //Serial.print("ir4");Serial.print("=");Serial.println(ir4);


 

if(ir2>812)
   ir2_map = 1;
else
   ir2_map = 0;
if(ir3>712)
   ir3_map = 1;
else
   ir3_map = 0;
if(ir4>685)
   ir4_map = 1;
else
   ir4_map = 0;

  //Serial.print("return");Serial.print("=");Serial.println((ir5_map*-2)+(ir4_map*-1)+(ir3_map*0)+(ir2_map*1)+(ir1_map*2));
    return ((ir4_map*-1)+(ir3_map*0)+(ir2_map*1));

 
}
 
int read_sensor_wf ()
{
  int SonarR_map;
  int SonarF_map;
double    SonarR = getDistance(8,9);
double    SonarF = getDistance(12,13);
//Serial.print("SonarR"); Serial.print("="); Serial.println(SonarR);
//Serial.print("SonarF"); Serial.print("="); Serial.println(SonarF);

if ( SonarR<10)
   SonarR_map=1;
else
   SonarR_map=0;
if (SonarF<20)   
   SonarF_map=1;
else
   SonarF_map=0; 
  

 /* Serial.print("ir2");Serial.print("=");Serial.println(ir2);
   Serial.print("ir3");Serial.print("=");Serial.println(ir3);
    Serial.print("ir4");Serial.print("=");Serial.println(ir4);
    delay(1000);
  */


  //Serial.print("return");Serial.print("=");Serial.println((ir5_map*-2)+(ir4_map*-1)+(ir3_map*0)+(ir2_map*1)+(ir1_map*2));
     // Serial.println((ir4_map*-1)+(ir3_map*0)+(ir2_map))
    return ((SonarR*1)); 

}




