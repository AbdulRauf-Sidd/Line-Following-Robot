// 0 = white
// EnA = Left motor

#define in1 6
#define in2 7
#define in3 9
#define in4 8
#define enA 5
#define enB 10

void setup() {
  // Setup pins as input/output
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);

    pinMode(enA,OUTPUT); //Left Motor
    pinMode(enB,OUTPUT); //Right Motor

      pinMode(A0, INPUT); //Left Most Sensor
      pinMode(A1, INPUT);
      pinMode(A2, INPUT); 
      pinMode(A3, INPUT); 
      pinMode(A4, INPUT);
      pinMode(A5, INPUT); //Right Most Sensor
}



void loop() {
  // put your main code here, to run repeatedly:

}

unsigned int len(unsigned int array[]) {
  unsigned int size;
  size = (sizeof(array)/sizeof(unsigned int));
  return size;
}

void read_sensors(unsigned int array[]) {
  int size = len(array);
  int skip = (8 - size)/2;
  unsigned int fullreadings[8] = {analogRead(A0), analogRead(A1), analogRead(A2), analogRead(A3), analogRead(A4), analogRead(A5), analogRead(A6), analogRead(A7)};
  for (int i=skip; i < (8-skip); i++) {
    array[i] = fullreadings[i];
  }
}

void sensor_calibrate() {
  
}
