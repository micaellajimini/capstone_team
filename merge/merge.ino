#include "arduinoFFT.h"
const int trigPin = 2;  //D4
const int echoPin = 0;  //D3
////////vibrate sensor
const int analogInPin = A0;
char buffer[50];
int soundSensor = 0;
float voltSensor = 0.0;
////////
int sensor = 13; // D7
/////////////////////sound sensor

arduinoFFT FFT = arduinoFFT(); /* Create FFT object */
/*
These values can be changed in order to evaluate the functions
*/
const uint16_t samples = 128; //This value MUST ALWAYS be a power of 2
double signalFrequency = 1000;
double samplingFrequency = 44000;
uint8_t amplitude = 100;
/*
These are the input and output vectors
Input vectors receive computed results from FFT
*/
double vReal[samples];
double vImag[samples];
#define SCL_INDEX 0x00
#define SCL_TIME 0x01
#define SCL_FREQUENCY 0x02
#define Theta 6.2831 //2*Pi


//////////////////////
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(sensor, INPUT);
  Serial.begin(9600); // Starts the serial communication
}
void PrintVector(double *vData, uint8_t bufferSize, uint8_t scaleType)
{
  for (uint16_t i = 0; i < bufferSize; i++)
  {
    uint8_t val_temp = map(vData[i],0,1000,0,255);
    Serial.print(i);
	Serial.print(" ");
    Serial.println(val_temp);
  }
	Serial.println("");
}
void loop() {
  long duration, distance = -1;
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  //음파속도 = 340m/s, 29us에 1cm, 왕복(2)
  distance = duration / 29 / 2;
    
  // Prints the distance on the Serial Monitor
  
  delay(2000);
  ///////////////////////////////////////
  /*PIR SENSOR*/
  long state = digitalRead(sensor);
  int Limit=10000;
  //////////////////////////////////////
  //vibrate sensor
  soundSensor = analogRead(analogInPin);
  Serial.print("Analog = " );
  Serial.print(soundSensor);
  Serial.print("\n");
  /////////////////////////////////////
  if ( state != HIGH ){//no man
    Serial.print(distance);
    Serial.println("cm");
    Serial.print(state);
    Serial.println("----------------------");
    delay(2000);
  }
  else{// there is a man
    for (uint8_t i = 0; i < samples; i++)
    {
        vReal[i] = analogRead(A0);
        delayMicroseconds(100);
        vImag[i] = 0;
    }
    FFT.Windowing(vReal, samples, FFT_WIN_TYP_HAMMING, FFT_FORWARD);  /* Weigh data */
    FFT.Compute(vReal, vImag, samples, FFT_FORWARD); /* Compute FFT */
    FFT.ComplexToMagnitude(vReal, vImag, samples); /* Compute magnitudes */

    float gap = vReal[1]-vReal[0];
    float tmp_flag = 100;//temp value
    if (gap <0){
        gap*=-1
    }
    if (gap > tmp_flag){//애기 감지
        print("There is a Baby in the car")
        PrintVector(vReal, (samples >> 1), SCL_FREQUENCY);
    }
    else{
        PrintVector(vReal, (samples >> 1), SCL_FREQUENCY);
    }


      Serial.println("Motion Detected");
      delay(2000);
  }  
}

