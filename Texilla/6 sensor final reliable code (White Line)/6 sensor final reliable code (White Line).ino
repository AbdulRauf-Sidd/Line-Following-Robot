// 0 = white
// EnA = Left motor

#define in1 6
#define in2 7
#define in3 9
#define in4 8
#define enA 5
#define enB 10
#define white 0
#define black 1


 int frd_speed = 200;
 int basespeed = 200;
 int softhigh = basespeed + 45;
 int mediumhigh = basespeed + 55;
 int hardhigh = basespeed;
 int softlow = basespeed -40;
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

if (HL_SENSOR == black) {
  lastdir = -1;
}
if (HR_SENSOR == black) {
  lastdir = 1;
}
if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==white && SR_SENSOR==white && MR_SENSOR==white && HR_SENSOR==white) {
    lastdirection(); //FORWARD
}

  else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==white && SR_SENSOR==white && MR_SENSOR==white && HR_SENSOR==black) {
    hardright(); 
 }

  else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==white && SR_SENSOR==white && MR_SENSOR==black && HR_SENSOR==white) {
    mediumright(); 
}

  else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==white && SR_SENSOR==white && MR_SENSOR==black && HR_SENSOR==black) {
    hardright(); 
}

  else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==white && SR_SENSOR==black && MR_SENSOR==white && HR_SENSOR==white) {
    softright(); 
}

  else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==white && SR_SENSOR==black && MR_SENSOR==white && HR_SENSOR==black) {
    hardright(); 
}

  else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==white && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==white) {
    softright(); 
}

  else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==white && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==black) {
    hardright(); 
}

  else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==black && SR_SENSOR==white && MR_SENSOR==white && HR_SENSOR==white) {
    softleft(); 
}
  else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==black && SR_SENSOR==white && MR_SENSOR==white && HR_SENSOR==black) {
    hardright();
}
  else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==black && SR_SENSOR==white && MR_SENSOR==black && HR_SENSOR==white) {
    mediumleft();
}
  else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==black && SR_SENSOR==white && MR_SENSOR==black && HR_SENSOR==black) {
    hardright();
}
  else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==white && HR_SENSOR==white) {
    forward();
}
 else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==white && HR_SENSOR==black) {
    hardright();
}
 else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==white) {
    mediumleft();
}
 else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==black) {
    hardright();
}
 else if(HL_SENSOR==white && ML_SENSOR==black && SL_SENSOR==white && SR_SENSOR==white && MR_SENSOR==white && HR_SENSOR==white) {
    mediumleft();
}
 else if(HL_SENSOR==white && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==white && MR_SENSOR==white && HR_SENSOR==white) {
    softleft();
}
 else if(HL_SENSOR==white && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==white && MR_SENSOR==white && HR_SENSOR==black) {
    hardright();
}
 else if(HL_SENSOR==white && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==white && MR_SENSOR==black && HR_SENSOR==black) {
    hardright();
}
 else if(HL_SENSOR==white && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==white && HR_SENSOR==white) {
    softleft();
}
 else if(HL_SENSOR==white && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==white && HR_SENSOR==black) {
    hardright();
}
 else if(HL_SENSOR==white && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==white) {
    forward();
    //boost();
}
 else if(HL_SENSOR==white && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==black) {
    hardright();
    //boost();
}
 else if(HL_SENSOR==black && ML_SENSOR==white && SL_SENSOR==white && SR_SENSOR==white && MR_SENSOR==white && HR_SENSOR==white) {
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==white && SL_SENSOR==white && SR_SENSOR==white && MR_SENSOR==white && HR_SENSOR==black) {
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==white && SL_SENSOR==white && SR_SENSOR==white && MR_SENSOR==black && HR_SENSOR==black) {
    hardright();
}
 else if(HL_SENSOR==black && ML_SENSOR==white && SL_SENSOR==white && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==white) {
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==white && SL_SENSOR==white && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==black) {
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==white && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==white && HR_SENSOR==white) {
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==white && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==white) {
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==white && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==black) {
    fiveB();
    //hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==black && SL_SENSOR==white && SR_SENSOR==white && MR_SENSOR==white && HR_SENSOR==white) {
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==black && SL_SENSOR==white && SR_SENSOR==white && MR_SENSOR==white && HR_SENSOR==black) {
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==black && SL_SENSOR==white && SR_SENSOR==white && MR_SENSOR==black && HR_SENSOR==white) {
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==black && SL_SENSOR==white && SR_SENSOR==white && MR_SENSOR==black && HR_SENSOR==black) {
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==black && SL_SENSOR==white && SR_SENSOR==black && MR_SENSOR==white && HR_SENSOR==white) {
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==black && SL_SENSOR==white && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==white) {
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==black && SL_SENSOR==white && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==black) {
    fiveB();
}
 else if(HL_SENSOR==black && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==white && MR_SENSOR==white && HR_SENSOR==white) {
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==white && MR_SENSOR==white && HR_SENSOR==black) {
    hardright();
}
 else if(HL_SENSOR==black && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==white && MR_SENSOR==black && HR_SENSOR==black) {
    hardright();
}
 else if(HL_SENSOR==black && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==white && HR_SENSOR==white) {
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==white && HR_SENSOR==black) {
    hardright();
}
 else if(HL_SENSOR==black && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==white) {
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==black) {
    boost();
}
 else {
    forward();
}

}

void fiveB()
{
  forward();
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
            //lastdir = 1;
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
            //lastdir = -1;

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

unsigned int analogtodigital(unsigned int arg[]) {
  unsigned int digital[6];
  for (int i=0; i < 6; i++) {
    if (arg[i] > 250) {
      digital[i] = 1;
    }
    else {
      digital[i] = 0;
    }
  }
  return digital;
}

void debug(unsigned int arg[]) {
  for (int u=0; u < 255; u++) {
    for (int i=0; i < 6; i++) {
        Serial.print(arg[i]);
        Serial.print(" ");
  }
  Serial.println();
  delay(200);
  }
}

void Stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}