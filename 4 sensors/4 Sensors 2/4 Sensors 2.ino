// for a WHITE LINE; white = 1, black = 0 
// EnA = Left motor
// Due to motor faults, Left motor rpm < right motor rpm 

#define in1 8 //6
#define in2 9 //7
#define in3 6 //8
#define in4 7 //9
#define enA 10 //5
#define enB 5 //10
#define white 0
#define black 1


 int frd_speed = 100;
 int basespeed = 100;
 int difference = 16;

 int softhigh = basespeed + 20;
 int mediumhigh = basespeed + 80;
 int hardhigh = basespeed + 40;
 int softlow = basespeed -20;
 int mediumlow = basespeed -80;
 int hardlow = basespeed + 40;
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
      Serial.begin(9600);
      //debug();
}

void loop() {

  //Serial.begin(9600);
  int HL_SENSOR = digitalRead(A0);
  int SL_SENSOR = digitalRead(A1);
  int SR_SENSOR = digitalRead(A2);
  int HR_SENSOR = digitalRead(A3);
  //unsigned int values[6];
  //unsigned int values[6] = {HL_SENSOR, ML_SENSOR, SL_SENSOR, SR_SENSOR, MR_SENSOR, HR_SENSOR};
  //debug();
  //unsigned int digit = analogtodigital(values);
  //debug2(digit);
  //Serial.println(digitalRead(A1));

 if (HL_SENSOR == white && SL_SENSOR == white && SR_SENSOR == white && HR_SENSOR == white) {
    lastdirection();
  }

  else if(HL_SENSOR == white && SL_SENSOR == white && SR_SENSOR == white && HR_SENSOR == black) {
    hardright();
    lastdir = 1;
  }

  else if(HL_SENSOR == white && SL_SENSOR == white && SR_SENSOR == black && HR_SENSOR == white) {
    softright();
  }

  else if(HL_SENSOR == white && SL_SENSOR == white && SR_SENSOR == black && HR_SENSOR == black) {
    hardright();
    lastdir = 1;
  }

  else if(HL_SENSOR == white && SL_SENSOR == black && SR_SENSOR == white && HR_SENSOR == white) {
    softleft();
  }

  else if(HL_SENSOR == white && SL_SENSOR == black && SR_SENSOR == white && HR_SENSOR == black) {
    hardright();
    lastdir = 1;
  }

  else if(HL_SENSOR == white && SL_SENSOR == black && SR_SENSOR == black && HR_SENSOR == white) {
    forward();
  }

  else if(HL_SENSOR == white && SL_SENSOR == black && SR_SENSOR == black && HR_SENSOR == black) {
    hardright();
    lastdir = 1;
  }

  else if(HL_SENSOR == black && SL_SENSOR == white && SR_SENSOR == white && HR_SENSOR == white) {
    hardleft();
    lastdir = -1;
  }

  else if(HL_SENSOR == black && SL_SENSOR == white && SR_SENSOR == white && HR_SENSOR == black) {
    hardleft();
    lastdir = -1;
  }

  else if(HL_SENSOR == black && SL_SENSOR == white && SR_SENSOR == black && HR_SENSOR == white) {
    hardleft();
    lastdir = -1;
  }

  else if(HL_SENSOR == black && SL_SENSOR == white && SR_SENSOR == black && HR_SENSOR == black) {
    hardright();
    lastdir = -1;
  }

  else if(HL_SENSOR == black && SL_SENSOR == black && SR_SENSOR == white && HR_SENSOR == white) {
    hardleft();
    lastdir = -1;
  }

  else if(HL_SENSOR == black && SL_SENSOR == black && SR_SENSOR == white && HR_SENSOR == black) {
    hardleft();
    lastdir = -1;
  }

  else if(HL_SENSOR == black && SL_SENSOR == black && SR_SENSOR == black && HR_SENSOR == white) {
    hardleft();
    lastdir = -1;
  }

  else if(HL_SENSOR == black && SL_SENSOR == black && SR_SENSOR == black && HR_SENSOR == black) {
    hardleft();
    lastdir = -1;
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

void debug() {
  for (int i=0; i < 256; i++) {
    Serial.print("NEW: ");
    Serial.print(digitalRead(A0));
    Serial.print(" ");
    Serial.print(digitalRead(A1));
    Serial.print(" ");
    Serial.print(digitalRead(A2));
    Serial.print(" ");
    Serial.print(digitalRead(A3));
    Serial.print(" ");
    Serial.println();
    delay(400);
}
}