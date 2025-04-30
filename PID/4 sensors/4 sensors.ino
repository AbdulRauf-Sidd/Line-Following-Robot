//ena = right motor

#include <DRV8835MotorShield.h>
#include <QTRSensors.h> //Pololu QTR Sensor Library. First you must download and install QTRSensors library
  
#define pha 6
#define phb 7
#define ena 10
#define enb 11 
#define KP 0.1 //experiment to determine this, start by something small that just makes your bot follow the line at a slow speed
#define KD 0.5 //experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd) 
#define M1_minumum_speed 130  //minimum speed of the Motor1
#define M2_minumum_speed 130  //minimum speed of the Motor2
#define M1_maximum_speed 450 //max. speed of the Motor1
#define M2_maximum_speed 350 //max. speed of the Motor2
//#define MIDDLE_SENSOR 2       //number of middle sensor used
#define NUM_SENSORS 6    //number of sensors used
#define NUM_SAMPLES_PER_SENSOR 4        
#define TIMEOUT 2500          //waits for 2500 us for sensor outputs to go low
#define EMITTER_PIN 2         //emitterPin is the Arduino digital pin that controls whether the IR LEDs are on or off. Emitter is controlled by digital pin 2
#define DEBUG 0
#define whiteline 1

//sensors 0 through 5 are connected to analog inputs 0 through 5, respectively
QTRSensorsAnalog qtra((unsigned char[]) {1, 2, 3, 4, 5, 6}, NUM_SENSORS,  NUM_SAMPLES_PER_SENSOR, EMITTER_PIN);

DRV8835MotorShield driver(phb,enb,pha,ena);
  
unsigned int sensorValues[NUM_SENSORS];
unsigned char readMode = QTR_EMITTERS_ON;
  
void setup()
{
//pinMode(2, OUTPUT)
//digitalWrite(2, HIGH);
//digitalWrite(13, HIGH);

delay(1500);
manual_calibration();
set_motors(0,0);
//Serial.begin(9600);
}
  
int lastError = 0;
int last_proportional = 0;
//int integral = 0;
  
void loop()
{
unsigned int sensors[6];
int position = qtra.readLine(sensorValues, QTR_EMITTERS_ON, whiteline); //get calibrated readings along with the line position, refer to the QTR Sensors Arduino Library for more details on line position.
int error = position - 3350;
//Serial.print(position);
//Serial.println();
//delay(200);
  
int motorSpeed = KP * error + KD * (error - lastError);
lastError = error;
  
int leftMotorSpeed = M1_minumum_speed + motorSpeed;
int rightMotorSpeed = M2_minumum_speed - motorSpeed;
  
// set motor speeds using the two motor speed variables above
set_motors(leftMotorSpeed, rightMotorSpeed);
}
  
void set_motors(int motor1speed, int motor2speed)
{
if (motor1speed > M1_maximum_speed ) motor1speed = M1_maximum_speed;
if (motor2speed > M2_maximum_speed ) motor2speed = M2_maximum_speed;
//if (motor1speed < 0) motor1speed = 0; 
//if (motor2speed < 0) motor2speed = 0; 
driver.setSpeeds(motor1speed, -(motor2speed));
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