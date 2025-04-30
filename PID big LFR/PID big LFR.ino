// 0 = white
// EnA = Left motor

#define in1 6
#define in2 7
#define in3 9
#define in4 8
#define enA 5
#define enB 10
#define KP 0.1
#define KD 0.5

 int frd_speed = 150;
 int basespeed = 190;
 int softhigh = basespeed + 50;
 int mediumhigh = basespeed + 55;
 int hardhigh = basespeed;
 int softlow = basespeed -50;
 int mediumlow = basespeed -55;
 int hardlow = basespeed;
 int allwhite = 225;
 
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
}

void loop() {

  //debug();
  int HL_SENSOR = digitalRead(A0);
  int ML_SENSOR = digitalRead(A1);
  int SL_SENSOR = digitalRead(A2);
  int SR_SENSOR = digitalRead(A3);
  int MR_SENSOR = digitalRead(A4);
  int HR_SENSOR = digitalRead(A5);
  int sensor_readings[6] = {HL_SENSOR, ML_SENSOR, SL_SENSOR, SR_SENSOR, MR_SENSOR, HR_SENSOR};
  int position = findposition(sensor_readings);
  error = position - 2000;
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


void softright()
{
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);

            analogWrite(enA, softhigh);
            analogWrite(enB, softlow);
           // lastdir = 1;
}

void mediumright()
{
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);

            analogWrite(enA, mediumhigh);
            analogWrite(enB, mediumlow);
            //lastdir = 1;
}

void hardright()
{
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);

            analogWrite(enA, hardhigh);
            analogWrite(enB, hardlow);
            lastdir = 1;
}

void softleft()
{
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);

            analogWrite(enA, softlow);
            analogWrite(enB, softhigh);
            //lastdir = -1;
}

void mediumleft()
{
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);

            analogWrite(enA, mediumlow);
            analogWrite(enB, mediumhigh);
            //lastdir = -1;
}

void hardleft()
{
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);
            lastdir = -1;

            analogWrite(enA, hardlow);
            analogWrite(enB, hardhigh);
}

void forward()
{
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);

                analogWrite(enA, frd_speed);
                analogWrite(enB, frd_speed);
}

void backward()
{
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);

                analogWrite(enA, M1_Speed);
                analogWrite(enB, M2_Speed);
}

void right()
{
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);

                analogWrite(enA, LeftRotationSpeed);
                analogWrite(enB, RightRotationSpeed);
}

void left()
{
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);

                analogWrite(enA, LeftRotationSpeed);
                analogWrite(enB, RightRotationSpeed);
}

void Stop()
{
            digitalWrite(in1, LOW);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4, LOW);
}

int findposition(int arg[])
{
  int position = 0;
  for (int i = 0; i < 6; i++)
  {
    position = position + (i*arg[i]);
  }
  position = position/6;
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

  Serial.begin(9600);
  for (int i = 0; i < 255; i++) {
    int sensor_readings[6] = {digitalRead(A0), digitalRead(A1), digitalRead(A2),digitalRead(A3), digitalRead(A4), digitalRead(A5)};
    for (int i=0; i < 6; i++) {
      Serial.print(sensor_readings[i]);
      Serial.print(' ');
  }
  Serial.print(findposition(sensor_readings));
}
}