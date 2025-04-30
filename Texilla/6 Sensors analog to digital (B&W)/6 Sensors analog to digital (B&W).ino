// for a WHITE LINE; white = 1, black = 0 
// EnA = Left motor
// Due to motor faults, Left motor rpm < right motor rpm 

#define in1 6
#define in2 7
#define in3 9
#define in4 8
#define enA 5
#define enB 10
#define white 1
#define black 0


 int frd_speed = 130;
 int basespeed = 140;
 int difference = 16;

 int softhigh = basespeed + 60;
 int mediumhigh = basespeed + 80;
 int hardhigh = basespeed + 110;
 int softlow = basespeed -60;
 int mediumlow = basespeed -80;
 int hardlow = basespeed + 110;
 int allwhite = 190;
 
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
      pinMode(A2, INPUT);
      pinMode(A3, INPUT); 
      pinMode(A4, INPUT);
      pinMode(A5, INPUT);
}

void loop() {

  //Serial.begin(9600);
  int HL_SENSOR = digitalRead(A0);
  int ML_SENSOR = digitalRead(A1);
  int SL_SENSOR = digitalRead(A2);
  int SR_SENSOR = digitalRead(A3);
  int MR_SENSOR = digitalRead(A4);
  int HR_SENSOR = digitalRead(A5);
  //unsigned int values[6];
  //unsigned int values[6] = {HL_SENSOR, ML_SENSOR, SL_SENSOR, SR_SENSOR, MR_SENSOR, HR_SENSOR};
  //debug();
  //unsigned int digit = analogtodigital(values);
  //debug2(digit);
  //Serial.println(digitalRead(A1));

if (HL_SENSOR == black) {
  lastdir = -1;
}
if (HR_SENSOR == black) {
  lastdir = 1;
}
if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==white && SR_SENSOR==white && MR_SENSOR==white && HR_SENSOR==white) { //1
    lastdirection(); //FORWARD
    //forward();
}

  else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==white && SR_SENSOR==white && MR_SENSOR==white && HR_SENSOR==black) { //2
    hardright(); 
 }

  else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==white && SR_SENSOR==white && MR_SENSOR==black && HR_SENSOR==white) { //3
    mediumright(); 
}

  else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==white && SR_SENSOR==white && MR_SENSOR==black && HR_SENSOR==black) { //1
    hardright(); 
}

  else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==white && SR_SENSOR==black && MR_SENSOR==white && HR_SENSOR==white) { //1
    softright(); 
}

  else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==white && SR_SENSOR==black && MR_SENSOR==white && HR_SENSOR==black) { //6
    hardright(); 
}

  else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==white && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==white) { //7
    softright(); 
}

  else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==white && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==black) { //8
    hardright(); 
}

  else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==black && SR_SENSOR==white && MR_SENSOR==white && HR_SENSOR==white) { //9
    softleft(); 
}
  else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==black && SR_SENSOR==white && MR_SENSOR==white && HR_SENSOR==black) { //10
    hardright();
}
  else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==black && SR_SENSOR==white && MR_SENSOR==black && HR_SENSOR==white) { //11
    softright();
}
  else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==black && SR_SENSOR==white && MR_SENSOR==black && HR_SENSOR==black) { //12
    hardright();
}
  else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==white && HR_SENSOR==white) { //13
    forward();
}
 else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==white && HR_SENSOR==black) { //14
    hardright();
}
 else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==white) { //15
    softright();
}
 else if(HL_SENSOR==white && ML_SENSOR==white && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==black) { //16
    hardright();
}
 else if(HL_SENSOR==white && ML_SENSOR==black && SL_SENSOR==white && SR_SENSOR==white && MR_SENSOR==white && HR_SENSOR==white) { //17
    mediumleft();
}
 else if(HL_SENSOR==white && ML_SENSOR==black && SL_SENSOR==white && SR_SENSOR==black && MR_SENSOR==white && HR_SENSOR==white) { //18
    softleft();
}
 else if(HL_SENSOR==white && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==white && MR_SENSOR==white && HR_SENSOR==white) { //19
    softleft();
}
 else if(HL_SENSOR==white && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==white && MR_SENSOR==white && HR_SENSOR==black) { //20
    hardright();
}
 else if(HL_SENSOR==white && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==white && MR_SENSOR==black && HR_SENSOR==black) { //21
    hardright();
}
 else if(HL_SENSOR==white && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==white && HR_SENSOR==white) { //22
    softleft();
}
 else if(HL_SENSOR==white && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==white && HR_SENSOR==black) { //23
    hardright();
}
 else if(HL_SENSOR==white && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==white) { //24
    forward();
    //boost();
}
 else if(HL_SENSOR==white && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==black) { //25
    mediumright();
    //boost();
}
 else if(HL_SENSOR==black && ML_SENSOR==white && SL_SENSOR==white && SR_SENSOR==white && MR_SENSOR==white && HR_SENSOR==white) { //26
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==white && SL_SENSOR==white && SR_SENSOR==white && MR_SENSOR==white && HR_SENSOR==black) { //27
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==white && SL_SENSOR==white && SR_SENSOR==white && MR_SENSOR==black && HR_SENSOR==black) { //28
    hardright();
}
 else if(HL_SENSOR==black && ML_SENSOR==white && SL_SENSOR==white && SR_SENSOR==black && MR_SENSOR==white && HR_SENSOR==white) { //29
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==white && SL_SENSOR==white && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==white) { //30
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==white && SL_SENSOR==white && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==black) { //31
    hardright();
}
 else if(HL_SENSOR==black && ML_SENSOR==white && SL_SENSOR==black && SR_SENSOR==white && MR_SENSOR==white && HR_SENSOR==white) { //32
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==white && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==white && HR_SENSOR==white) { //33
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==white && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==white) { //34
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==white && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==black) { //35
    hardleft();
    //hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==black && SL_SENSOR==white && SR_SENSOR==white && MR_SENSOR==white && HR_SENSOR==white) { //36
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==black && SL_SENSOR==white && SR_SENSOR==white && MR_SENSOR==white && HR_SENSOR==black) { //37
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==black && SL_SENSOR==white && SR_SENSOR==black && MR_SENSOR==white && HR_SENSOR==white) { //38
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==black && SL_SENSOR==white && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==white) { //39
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==black && SL_SENSOR==white && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==black) { //40
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==white && MR_SENSOR==white && HR_SENSOR==white) { //41
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==white && MR_SENSOR==white && HR_SENSOR==black) { //42
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==white && MR_SENSOR==black && HR_SENSOR==black) { //43
    fiveB();
}
 else if(HL_SENSOR==black && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==white && HR_SENSOR==white) { //44
    hardleft();
}
 else if(HL_SENSOR==black && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==white && HR_SENSOR==black) { //45
    fiveB();
}
 else if(HL_SENSOR==black && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==white) { //46
    fiveB();
}
 else if(HL_SENSOR==black && ML_SENSOR==black && SL_SENSOR==black && SR_SENSOR==black && MR_SENSOR==black && HR_SENSOR==black) { //47
    fiveB();
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
            analogWrite(enB, 255 - difference);
}
void lastdirection()
{
  if (lastdir == -1)
  {
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);

            analogWrite(enA, allwhite + difference);
            analogWrite(enB, allwhite);
            lastdir = -1;
  }

    else 
    { 
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);

            analogWrite(enA, allwhite + difference);
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

            analogWrite(enA, softhigh + difference);
            analogWrite(enB, softlow);
           // lastdir = 1;
}

void mediumright()
{
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);

            analogWrite(enA, mediumhigh + difference);
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

            analogWrite(enA, softlow + difference);
            analogWrite(enB, softhigh);
            //lastdir = -1;
}

void mediumleft()
{
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);

            analogWrite(enA, mediumlow + difference);
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

                analogWrite(enA, frd_speed + difference);
                analogWrite(enB, frd_speed);
}

//void backward()
//{
//            digitalWrite(in1, LOW);
//            digitalWrite(in2, HIGH);
//            digitalWrite(in3, LOW);
//            digitalWrite(in4, HIGH);
//
//                analogWrite(enA, M1_Speed);
//                analogWrite(enB, M2_Speed);
//}



//unsigned int analogtodigital(unsigned int arg[]) {
//  unsigned int digital[6];
//  for (int i=0; i < 6; i++) {
//    if (arg[i] >= 95) {
//      digital[i] = 1;
//    }
//    else {
//      digital[i] = 1;
//    }
//  }
//  return digital;
//}

//void debug() {
//    int HL_SENSOR = digitalRead(A0);
//  int ML_SENSOR = digitalRead(A1);
//  int SL_SENSOR = digitalRead(A2);
//  int SR_SENSOR = digitalRead(A3);
//  int MR_SENSOR = digitalRead(A4);
//  int HR_SENSOR = digitalRead(A5);
//  unsigned int values[6] = {HL_SENSOR, ML_SENSOR, SL_SENSOR, SR_SENSOR, MR_SENSOR, HR_SENSOR};
//  for (int u=0; u < 255; u++) {
//      int HL_SENSOR = digitalRead(A0);
//  int ML_SENSOR = digitalRead(A1);
//  int SL_SENSOR = digitalRead(A2);
//  int SR_SENSOR = digitalRead(A3);
//  int MR_SENSOR = digitalRead(A4);
//  int HR_SENSOR = digitalRead(A5);
//  unsigned int values[6] = {HL_SENSOR, ML_SENSOR, SL_SENSOR, SR_SENSOR, MR_SENSOR, HR_SENSOR};
//    for (int i=0; i < 6; i++) {
//        Serial.print(values[i]);
//        Serial.print(" ");
//  }
//  Serial.println();
//  delay(200);
//  }
//}

//void debug2(unsigned int arg[]) {
//    for (int i=0; i < 6; i++) {
//        Serial.print(arg[i]);
//        Serial.print(" ");
//  }
//  Serial.println();
//  delay(200);
//}

void Stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}