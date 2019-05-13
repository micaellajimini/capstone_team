// defines pins numbers
const int trigPin = 2;  //D4
const int echoPin = 0;  //D3

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
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
  Serial.print(distance);
  Serial.println("cm");
  delay(2000);
}
