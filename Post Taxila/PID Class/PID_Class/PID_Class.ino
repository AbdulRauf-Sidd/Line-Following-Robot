/* This code creates a class called PID which has its own attributes and methods for a PID controlled line following robot. It Works for a maximum of
8 Sensors and uses a mathamatical formula to scale the analog readings from each sensor between the range 0 - 500.
*/ 
class PID {
  public:
    int rightMinSpeed;          //right motor minimum speed
    int leftMinSpeed;                            //left motor minimum speed
    int rightMaxSpeed;                           //right motor max speed
    int leftMaxSpeed;                            //left motor max speed
    int numSensors;                              //number of sensors used. should be beteen 2 - 8 
    int samplesPerSensor;                        //number of readings taken per each sensor
    unsigned int minreading;                     //attribute to store the initial minimum value of each sensor   
    unsigned int maxreading;                     //attribute to store the initial maximum value of each sensor
    unsigned int minvalues[8];                   //array to store the mimumum values recorded over time for each sensor 
    unsigned int maxvalues[8];                   //array to store the maximum values recorded over time for each sensor
    unsigned int rawReadings[8];                 //array to store the raw readings taken from each sensor
    unsigned int calibrated_readings[8];         //array to store the calibrated readings of each sensor (a value between 0 - 500)

    //Constructor to initialize attributes.
    PID (int rightmin, int leftmin, int rightmax, int leftmax, int numsens, int samples) { 
      rightMinSpeed = rightmin;
      leftMinSpeed = leftmin;
      rightMaxSpeed = rightmax;
      leftMaxSpeed = leftmax;
      numSensors = numsens;
      samplesPerSensor = samples;
      minreading = 1000;
      maxreading = 0;
      for (int i = 0; i < numSensors; i++) {
        minvalues[i] = minreading;
        maxvalues[i] = maxreading;
      }
    }

    //stores raw readings taken from each sensor into rawReadings array.
    void read() {
      unsigned int full[8] = {analogRead(A0), analogRead(A1), analogRead(A2), analogRead(A3), analogRead(A4), analogRead(A5), analogRead(A6), analogRead(A7)};
      int skip = (8 - numSensors)/2;          //if number of sensors used < 8, then will skip the starting and ending sensors.
      for (int i = skip; i < 8 - skip; i++) {
        rawReadings[i] = full[i];
      }
    }

    //stores minimum and maximum values over a period of time into respective arrays.
    void calibrate() {
      read();
      for (int i = 0; i < numSensors; i++) {
        if (rawReadings[i] < minvalues[i]) {
          minvalues[i] = rawReadings[i];
        }
        if (rawReadings[i] > maxvalues[i]) {
          maxvalues[i] = rawReadings[i];
        }
      }
    }


    //
    void read_calibrated() {
      read();
      int difference;
      int percentage;
      int scaledValue;
      for (int i = 0; i < numSensors; i++) {
        if (rawReadings[i] < minvalues[i]) {
          calibrated_readings[i] = 0;
        }
        else if (rawReadings[i] > maxvalues[i]) {
          calibrated_readings[i] = 500;
        }
        else{
          difference = maxvalues[i] - minvalues[i];
          percentage = (rawReadings[i]/difference) * 100;
          scaledValue = (percentage/100) * 500;
          calibrated_readings[i] = scaledValue;
        }
      }
    }

    int find_position() {
      int numerator;
      int denominator;
      int currentPosition;
      for (int i = 0; i < numSensors; i++) {
        numerator = numerator + (i*(calibrated_readings[i]));
        denominator = denominator + calibrated_readings[i];
      }
      currentPosition = numerator/denominator;
      return currentPosition;
    }

    void read_debug() {
      Serial.begin(9600);
      for (int i = 0; i < 256; i++) {
        read();
        for (int u = 0; i < numSensors; u++) {
          Serial.print(rawReadings[u]);
          Serial.print("   ");
        }
        Serial.println();
        delay(1000);
      }
    }

    void calibrate_debug() {
      Serial.begin(9600);
      for (int i = 0; i < 256; i ++) {
        calibrate();
        Serial.print("Min Values:  ");
        for (int u = 0; u < numSensors; u++) {
          Serial.print(minvalues[u]);
          Serial.print("  ");
        }
        Serial.println();
        Serial.print("Max Values:  ");
        for (int o = 0; o < numSensors; o++) {
          Serial.print(maxvalues[o]);
          Serial.print("  ");
        }
        Serial.println();
        Serial.print("Raw Readings:  ");
        for (int p = 0; p < numSensors; p++) {
          Serial.print(rawReadings[p]);
          Serial.print("  ");
        }
        Serial.println();
        delay(50);
      }
    }

    void read_calibrated_debug() {
      Serial.begin(9600);
      for (int i = 0; i < 256; i++) {
        read_calibrated();
        Serial.print("Raw Readings:  ");
        for (int u = 0; u < numSensors; u++) {
          Serial.print(rawReadings[u]);
          Serial.print("  ");
        }
        Serial.println();
        Serial.print("Calibrated Readings:  ");
        for (int o = 0; o < numSensors; o++) {
          Serial.print(calibrated_readings[o]);
          Serial.print("  ");
        }
        Serial.println();
        delay(50);
      }
    }

    void position_debug() {
      Serial.begin(9600);
      for (int i = 0; i < 256; i++) {
        read_calibrated();
        for (int u = 0; u < numSensors; u++) {
          Serial.print(calibrated_readings[u]);
          Serial.print("  ");
        }
        Serial.print(find_position());
        Serial.println();
      }
    }
};
void setup() {
  PID object1(12, 2, 3, 4, 6, 1);
  object1.read_debug();
};

void loop() {
 int i =5;
}