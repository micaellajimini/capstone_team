int Status = 12;
int sensor = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(Status, OUTPUT);
}

void loop()
{
  long state = digitalRead(sensor);
  if(state == HIGH)
  {
    digitalWrite(Status, HIGH);
    Serial.println("Motion detected!");
    delay(1000);
    }
  else
  {
    digitalWrite(Status, LOW);
    Serial.println("Motion absent!");
    delay(1000);
  }
}
