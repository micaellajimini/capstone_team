#include "arduinoFFT.h"

arduinoFFT FFT = arduinoFFT();

const uint16_t samples = 64;
double signalFrequency = 1000;
double samplingFrequency = 5000;
uint8_t amplitude = 100;
const int analogInPin = A0;

char buffer[50];
int soundSensor = 0;
float voltSensor = 0.0;

void setup(){
    Serial.begin(115200);
    
}
void loop(){
    soundSensor = analogRead(analogInPin);
    voltSensor = (soundSensor * 5.0) / 1023.0;
    Serial.print("Analog = ");
    Serial.print(soundSensor);
    Serial.print("  Volt = ");
    Serial.println(voltSensor);
    delay(500);
}

void PrintVector(double *vData, uint8_t bufferSize, uint8_t scaleType)
{
  for (uint16_t i = 0; i < bufferSize; i++)
  {
    double abscissa;
    /* Print abscissa value */
    switch (scaleType)
    {
      case SCL_INDEX:
        abscissa = (i * 1.0);
        break;
      case SCL_TIME:
        abscissa = ((i * 1.0) / samplingFrequency);
        break;
      case SCL_FREQUENCY:
        abscissa = ((i * 1.0 * samplingFrequency) / samples);
        break;
    }
    Serial.print(abscissa, 6);
    Serial.print(" ");
    Serial.print(vData[i], 4);
    Serial.println();
  }
  Serial.println();
}

