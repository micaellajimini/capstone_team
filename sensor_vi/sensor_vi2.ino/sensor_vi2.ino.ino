const int analogInPin = A0;
char buffer[50];
int soundSensor = 0;
float voltSensor = 0.0;
void setup()
{
Serial.begin(115200);
}
void loop()
{
  soundSensor = analogRead(analogInPin);
  Serial.print("Analog = " );
  Serial.print(soundSensor);
  Serial.print("\n");
  delay(500);

}
