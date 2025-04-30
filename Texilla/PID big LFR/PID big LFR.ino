// 0 = white
// EnA = Left motor

#define in1 6
#define in2 7
#define in3 9
#define in4 8
#define enA 5
#define enB 10
#define KP 0.11
#define KD 0.5

 int frd_speed = 150;
 int basespeed = 200;
 int softhigh = basespeed + 50;
 int mediumhigh = basespeed + 55;
 int hardhigh = basespeed;
 int softlow = basespeed -50;
 int mediumlow = basespeed -55;
 int hardlow = basespeed;
 int allwhite = 225;
 int scale = -200;
 
 int M1_Speed = 255; // speed of motor 1
 int M2_Speed = 255; // speed of motor 2
 int LeftRotationSpeed = 250;  // Left Rotation Speed
 int RightRotationSpeed = 250; // Right Rotation Speed
 int lastdir = 0;
 int error = 0;
 int lasterror = 0;


 void setup() {

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);

    pinMode(enA,OUTPUT);
    pinMode(enB,OUTPUT);

      pinMode(A0, INPUT);
      pinMode(A1, INPUT);
      pinMode(A2, INPUT); // initialize Left sensor as an input
      pinMode(A3, INPUT); // initialize Right sensor as an input
      pinMode(A4, INPUT);
      pinMode(A5, INPUT);
      Serial.begin(9600);
}
 
void loop() {

  debug();
  int HL_SENSOR = analogRead(A0);
  int ML_SENSOR = analogRead(A1);
  int SL_SENSOR = analogRead(A2);
  int SR_SENSOR = analogRead(A3);
  int MR_SENSOR = analogRead(A4);
  int HR_SENSOR = analogRead(A5);
  int sensor_readings[6] = {(HL_SENSOR*2) - scale, (ML_SENSOR*2)-scale, (SL_SENSOR*2)-scale, (SR_SENSOR*2)-scale, (MR_SENSOR*2)-scale, (HR_SENSOR*2)-scale};
 // int calibrated_readings = sensor_calibrate(sensor_readings);

  unsigned int position = findposition(sensor_readings);
  error = position - 2500;
  lasterror = error;
  int motorspeed = (KP * error) + KD * (error - lasterror);
  int leftspeed = basespeed + motorspeed;
  int rightspeed = basespeed - motorspeed;
  setleft(leftspeed);
  setright(rightspeed);
}


void boost()
{
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);

            analogWrite(enA, 255);
            analogWrite(enB, 255);
}
void lastdirection()
{
  delay(5000);
  if (lastdir == -1)
  {
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);

            analogWrite(enA, allwhite);
            analogWrite(enB, allwhite);
            lastdir = -1;
  }

    else 
    { 
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);

            analogWrite(enA, allwhite);
            analogWrite(enB, allwhite);
            lastdir = 1; 
    }
}

void Stop()
{
            digitalWrite(in1, LOW);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4, LOW);
}


//unsigned long long findposition(int arg[]) {
 // int location = 0;
 // int sum = 0;
 // int a0 = 0*1000*arg[0];
 // int i1 = arg[1] ;
 // unsigned long long a1 = 1000*arg[1];
 // int a2 = 2*1000*arg[2];
 // int a3 = 3*1000*arg[3];
 // int a4 = 4*1000*arg[4];
 // int a5 = 5*1000*arg[5];
 // location = a1;
 // return abs(a1);
//}
int findposition(int arg[])
{
 int sum = 0;
  int position = 0;
  for (int i = 0; i < 6; i++)
  {
    position = position + arg[i];
    position = position * 1000;
    sum = sum + arg[i];
  }
  
 position = position/sum;
 return position;
}

void setleft(int speed)
{
  if (speed < 0) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, abs(speed));
  }
  else {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, abs(speed));
  }
}

void setright(int speed)
{
  if (speed < 0) {
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, abs(speed));
  }
  else {
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, abs(speed));
  }
}

void debug() {

  for (int i = 0; i < 255; i++) {
    
    int sensor_readings[6] = {(digitalRead(A0)),(digitalRead(A1)),digitalRead(A2),digitalRead(A3),digitalRead(A4),digitalRead(A5)};
    //int calibrated_readings = sensor_calibrate(sensor_readings);
    for (int i=0; i < 6; i++) {
      Serial.print(sensor_readings[i]);
      Serial.print(' ');
      
  }
  //int hello = findposition(sensor_readings);
  //Serial.print(hello);
  Serial.println();
  delay(400);
}
}

int sensor_calibrate(int arg[]) {
  for (int i = 0; i < 6; i++) {
    arg[i] = (arg[i]*2) -120;
  }
  return arg;
}
