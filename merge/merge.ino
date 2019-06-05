const int trigPin = 2;  //D4
const int echoPin = 0;  //D3
////////vibrate sensor
const int analogInPin = A0;
char buffer[50];
int soundSensor = 0;
float voltSensor = 0.0;
////////
int sensor = 13; // D7

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(sensor, INPUT);
  Serial.begin(9600); // Starts the serial communication
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
  if (Limit < distance || state != HIGH ){//no man
    Serial.print(distance);
    Serial.println("cm");
    Serial.print(state);
    Serial.println("----------------------");
    delay(2000);
  }
  else{
      Serial.println("Motion Detected");
      delay(2000);
  }  
}
