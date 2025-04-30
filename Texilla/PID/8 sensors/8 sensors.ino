//ena = right motor

#include <DRV8835MotorShield.h>
#include <QTRSensors.h> //Pololu QTR Sensor Library. First you must download and install QTRSensors library

#define whiteline 0 // when line is white; whiteline = 1 
#define pha 6
#define phb 7
#define ena 10
#define enb 11 
#define KP 0.05 //experiment to determine this, start by something small that just makes your bot follow the line at a slow speed
#define KD 0.1 //experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd) 
#define M1_minumum_speed 70  //minimum speed of the Motor1
#define M2_minumum_speed 70  //minimum speed of the Motor2
#define M1_maximum_speed 200 //max. speed of the Motor1
#define M2_maximum_speed 200 //max. speed of the Motor2
//#define MIDDLE_SENSOR 2       //number of middle sensor used
#define NUM_SENSORS 8      //number of sensors used
#define NUM_SAMPLES_PER_SENSOR 4        
//#define TIMEOUT 2500          //waits for 2500 us for sensor outputs to go low
#define EMITTER_PIN 2         //emitterPin is the Arduino digital pin that controls whether the IR LEDs are on or off. Emitter is controlled by digital pin 2
#define DEBUG 0

//sensors 0 through 5 are connected to analog inputs 0 through 5, respectively
QTRSensorsAnalog qtra((unsigned char[]) {0, 1, 2, 3, 4, 5, 6, 7}, NUM_SENSORS,  NUM_SAMPLES_PER_SENSOR, EMITTER_PIN);

DRV8835MotorShield driver(phb,enb,pha,ena);
  
unsigned int sensorValues[NUM_SENSORS];
  
void setup()
{

delay(1500);
//auto_calib();
manual_calibration();
delay(500);
set_motors(0,0);
Serial.begin(9600);
}
  

int lastError = 0;
int last_proportional = 0;
int integral = 0;
  
void loop()
{
unsigned int sensors[8];
int position = qtra.readLine(sensorValues, QTR_EMITTERS_ON,1); //get calibrated readings along with the line position, refer to the QTR Sensors Arduino Library for more details on line position.
int error = position - 3550;
Serial.print(sensorValues[0]);
Serial.print("   ");
Serial.print(sensorValues[3]);
Serial.print("   ");
//Serial.print(position);
Serial.println();

//if (position == 0) {
//    set_motors(-150, 150);
 // }
 //   else if (position == 7000) {
 //   set_motors(150, -150);
 //   }
if ((sensorValues[0] < 700) && (sensorValues[7] > 700)) {
    delay(30);
    set_motors(-150, 150);
    
  }
else if ((sensorValues[7] < 700) && (sensorValues[0] > 700)) {
    delay(30);
    set_motors(150, -150);
  }

else {
  int motorSpeed = KP * error + KD * (error - lastError);
  lastError = error;
  
  int leftMotorSpeed = M1_minumum_speed + motorSpeed;
  int rightMotorSpeed = M2_minumum_speed - motorSpeed;
  
  // set motor speeds using the two motor speed variables above
  set_motors(leftMotorSpeed, rightMotorSpeed);
}}
  
void set_motors(int motor1speed, int motor2speed)
{
if (motor1speed > M1_maximum_speed ) motor1speed = M1_maximum_speed;
if (motor2speed > M2_maximum_speed ) motor2speed = M2_maximum_speed;
//if (motor1speed < 0) motor1speed = 0; 
//if (motor2speed < 0) motor2speed = 0; 
driver.setSpeeds(motor1speed, motor2speed);
}

//calibrate for sometime by sliding the sensors across the line, or you may use auto-calibration instead
void manual_calibration() {
  
int i;
for (i = 0; i < 100; i++) 
{
qtra.calibrate(QTR_EMITTERS_ON);
delay(20);
}
  
if (DEBUG) {
Serial.begin(9600);
for (int i = 0; i < NUM_SENSORS; i++)
{
Serial.print(qtra.calibratedMinimumOn[i]);
Serial.print(' ');
}
Serial.println();
  
for (int i = 0; i < NUM_SENSORS; i++)
{
Serial.print(qtra.calibratedMaximumOn[i]);
Serial.print(' ');
}
Serial.println();
Serial.println();
}
}

void auto_calib() {
  int count = 0;
  unsigned int sens[NUM_SENSORS];
  for (int i=0; i<1500; i++) {
    set_motors(75, -75);
    delay(10);
    qtra.read(sens);
    qtra.calibrate(QTR_EMITTERS_ON);
    if (sens[2] > 750 && sens[3] > 750) {
      count += 1;
    }
    if (count == 1) {
      delay(500);
      break;
    }
    //else if (count == 3) {
    //  set_motors(0, 0);
    //  delay(500);
    //  break;
    //}
  }
  for (int u = 0; u < 1500; u++) {
    set_motors(-75, 75);
    delay(10);
    qtra.read(sens);
    qtra.calibrate(QTR_EMITTERS_ON);
    if (sens[2] > 750 && sens[3] > 750) {
      count += 1;
    }
    if (count == 2) {
      set_motors(0, 0);
      //delay(500);
      break;
    }
  }
}