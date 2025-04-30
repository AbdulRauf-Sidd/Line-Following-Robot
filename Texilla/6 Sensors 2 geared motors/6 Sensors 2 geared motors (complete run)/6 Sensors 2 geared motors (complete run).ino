// 0 = white
// EnA = Left motor

#define in1 6
#define in2 7
#define in3 9
#define in4 8
#define enA 5
#define enB 10


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

  int HL_SENSOR = digitalRead(A0);
  int ML_SENSOR = digitalRead(A1);
  int SL_SENSOR = digitalRead(A2);
  int SR_SENSOR = digitalRead(A3);
  int MR_SENSOR = digitalRead(A4);
  int HR_SENSOR = digitalRead(A5);
  //Serial.begin(9600);
  //Serial.println(digitalRead(A1));

if(HL_SENSOR==0 && ML_SENSOR==0 && SL_SENSOR==0 && SR_SENSOR==0 && MR_SENSOR==0 && HR_SENSOR==0) {
    lastdirection(); //FORWARD
}

  else if(HL_SENSOR==0 && ML_SENSOR==0 && SL_SENSOR==0 && SR_SENSOR==0 && MR_SENSOR==0 && HR_SENSOR==1) {
    hardright(); 
 }

  else if(HL_SENSOR==0 && ML_SENSOR==0 && SL_SENSOR==0 && SR_SENSOR==0 && MR_SENSOR==1 && HR_SENSOR==0) {
    mediumright(); 
}

  else if(HL_SENSOR==0 && ML_SENSOR==0 && SL_SENSOR==0 && SR_SENSOR==0 && MR_SENSOR==1 && HR_SENSOR==1) {
    hardright(); 
}

  else if(HL_SENSOR==0 && ML_SENSOR==0 && SL_SENSOR==0 && SR_SENSOR==1 && MR_SENSOR==0 && HR_SENSOR==0) {
    softright(); 
}

  else if(HL_SENSOR==0 && ML_SENSOR==0 && SL_SENSOR==0 && SR_SENSOR==1 && MR_SENSOR==0 && HR_SENSOR==1) {
    hardright(); 
}

  else if(HL_SENSOR==0 && ML_SENSOR==0 && SL_SENSOR==0 && SR_SENSOR==1 && MR_SENSOR==1 && HR_SENSOR==0) {
    softright(); 
}

  else if(HL_SENSOR==0 && ML_SENSOR==0 && SL_SENSOR==0 && SR_SENSOR==1 && MR_SENSOR==1 && HR_SENSOR==1) {
    hardright(); 
}

  else if(HL_SENSOR==0 && ML_SENSOR==0 && SL_SENSOR==1 && SR_SENSOR==0 && MR_SENSOR==0 && HR_SENSOR==0) {
    softleft(); 
}
  else if(HL_SENSOR==0 && ML_SENSOR==0 && SL_SENSOR==1 && SR_SENSOR==0 && MR_SENSOR==0 && HR_SENSOR==1) {
    hardright();
}
  else if(HL_SENSOR==0 && ML_SENSOR==0 && SL_SENSOR==1 && SR_SENSOR==0 && MR_SENSOR==1 && HR_SENSOR==0) {
    mediumleft();
}
  else if(HL_SENSOR==0 && ML_SENSOR==0 && SL_SENSOR==1 && SR_SENSOR==0 && MR_SENSOR==1 && HR_SENSOR==1) {
    hardright();
}
  else if(HL_SENSOR==0 && ML_SENSOR==0 && SL_SENSOR==1 && SR_SENSOR==1 && MR_SENSOR==0 && HR_SENSOR==0) {
    forward();
}
 else if(HL_SENSOR==0 && ML_SENSOR==0 && SL_SENSOR==1 && SR_SENSOR==1 && MR_SENSOR==0 && HR_SENSOR==1) {
    hardright();
}
 else if(HL_SENSOR==0 && ML_SENSOR==0 && SL_SENSOR==1 && SR_SENSOR==1 && MR_SENSOR==1 && HR_SENSOR==0) {
    mediumleft();
}
 else if(HL_SENSOR==0 && ML_SENSOR==0 && SL_SENSOR==1 && SR_SENSOR==1 && MR_SENSOR==1 && HR_SENSOR==1) {
    hardright();
}
 else if(HL_SENSOR==0 && ML_SENSOR==1 && SL_SENSOR==0 && SR_SENSOR==0 && MR_SENSOR==0 && HR_SENSOR==0) {
    mediumleft();
}
 else if(HL_SENSOR==0 && ML_SENSOR==1 && SL_SENSOR==1 && SR_SENSOR==0 && MR_SENSOR==0 && HR_SENSOR==0) {
    softleft();
}
 else if(HL_SENSOR==0 && ML_SENSOR==1 && SL_SENSOR==1 && SR_SENSOR==0 && MR_SENSOR==0 && HR_SENSOR==1) {
    hardright();
}
 else if(HL_SENSOR==0 && ML_SENSOR==1 && SL_SENSOR==1 && SR_SENSOR==0 && MR_SENSOR==1 && HR_SENSOR==1) {
    hardright();
}
 else if(HL_SENSOR==0 && ML_SENSOR==1 && SL_SENSOR==1 && SR_SENSOR==1 && MR_SENSOR==0 && HR_SENSOR==0) {
    softleft();
}
 else if(HL_SENSOR==0 && ML_SENSOR==1 && SL_SENSOR==1 && SR_SENSOR==1 && MR_SENSOR==0 && HR_SENSOR==1) {
    hardright();
}
 else if(HL_SENSOR==0 && ML_SENSOR==1 && SL_SENSOR==1 && SR_SENSOR==1 && MR_SENSOR==1 && HR_SENSOR==0) {
    //boost();
}
 else if(HL_SENSOR==0 && ML_SENSOR==1 && SL_SENSOR==1 && SR_SENSOR==1 && MR_SENSOR==1 && HR_SENSOR==1) {
    //boost();
}
 else if(HL_SENSOR==1 && ML_SENSOR==0 && SL_SENSOR==0 && SR_SENSOR==0 && MR_SENSOR==0 && HR_SENSOR==0) {
    hardleft();
}
 else if(HL_SENSOR==1 && ML_SENSOR==0 && SL_SENSOR==0 && SR_SENSOR==0 && MR_SENSOR==0 && HR_SENSOR==1) {
    hardleft();
}
 else if(HL_SENSOR==1 && ML_SENSOR==0 && SL_SENSOR==0 && SR_SENSOR==0 && MR_SENSOR==1 && HR_SENSOR==1) {
    hardright();
}
 else if(HL_SENSOR==1 && ML_SENSOR==0 && SL_SENSOR==0 && SR_SENSOR==1 && MR_SENSOR==1 && HR_SENSOR==0) {
    hardleft();
}
 else if(HL_SENSOR==1 && ML_SENSOR==0 && SL_SENSOR==0 && SR_SENSOR==1 && MR_SENSOR==1 && HR_SENSOR==1) {
    hardleft();
}
 else if(HL_SENSOR==1 && ML_SENSOR==0 && SL_SENSOR==1 && SR_SENSOR==1 && MR_SENSOR==0 && HR_SENSOR==0) {
    hardleft();
}
 else if(HL_SENSOR==1 && ML_SENSOR==0 && SL_SENSOR==1 && SR_SENSOR==1 && MR_SENSOR==1 && HR_SENSOR==0) {
    hardleft();
}
 else if(HL_SENSOR==1 && ML_SENSOR==0 && SL_SENSOR==1 && SR_SENSOR==1 && MR_SENSOR==1 && HR_SENSOR==1) {
    hardleft();
}
 else if(HL_SENSOR==1 && ML_SENSOR==1 && SL_SENSOR==0 && SR_SENSOR==0 && MR_SENSOR==0 && HR_SENSOR==0) {
    hardleft();
}
 else if(HL_SENSOR==1 && ML_SENSOR==1 && SL_SENSOR==0 && SR_SENSOR==0 && MR_SENSOR==0 && HR_SENSOR==1) {
    hardleft();
}
 else if(HL_SENSOR==1 && ML_SENSOR==1 && SL_SENSOR==0 && SR_SENSOR==0 && MR_SENSOR==1 && HR_SENSOR==0) {
    hardleft();
}
 else if(HL_SENSOR==1 && ML_SENSOR==1 && SL_SENSOR==0 && SR_SENSOR==0 && MR_SENSOR==1 && HR_SENSOR==1) {
    hardleft();
}
 else if(HL_SENSOR==1 && ML_SENSOR==1 && SL_SENSOR==0 && SR_SENSOR==1 && MR_SENSOR==0 && HR_SENSOR==0) {
    hardleft();
}
 else if(HL_SENSOR==1 && ML_SENSOR==1 && SL_SENSOR==0 && SR_SENSOR==1 && MR_SENSOR==1 && HR_SENSOR==0) {
    hardleft();
}
 else if(HL_SENSOR==1 && ML_SENSOR==1 && SL_SENSOR==0 && SR_SENSOR==1 && MR_SENSOR==1 && HR_SENSOR==1) {
    hardleft();
}
 else if(HL_SENSOR==1 && ML_SENSOR==1 && SL_SENSOR==1 && SR_SENSOR==0 && MR_SENSOR==0 && HR_SENSOR==0) {
    hardleft();
}
 else if(HL_SENSOR==1 && ML_SENSOR==1 && SL_SENSOR==1 && SR_SENSOR==0 && MR_SENSOR==0 && HR_SENSOR==1) {
    hardright();
}
 else if(HL_SENSOR==1 && ML_SENSOR==1 && SL_SENSOR==1 && SR_SENSOR==0 && MR_SENSOR==1 && HR_SENSOR==1) {
    hardright();
}
 else if(HL_SENSOR==1 && ML_SENSOR==1 && SL_SENSOR==1 && SR_SENSOR==1 && MR_SENSOR==0 && HR_SENSOR==0) {
    hardleft();
}
 else if(HL_SENSOR==1 && ML_SENSOR==1 && SL_SENSOR==1 && SR_SENSOR==1 && MR_SENSOR==0 && HR_SENSOR==1) {
    hardright();
}
 else if(HL_SENSOR==1 && ML_SENSOR==1 && SL_SENSOR==1 && SR_SENSOR==1 && MR_SENSOR==1 && HR_SENSOR==0) {
    hardleft();
}
 else if(HL_SENSOR==1 && ML_SENSOR==1 && SL_SENSOR==1 && SR_SENSOR==1 && MR_SENSOR==1 && HR_SENSOR==1) {
    //boost();
}
 else {
    forward();
}

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