void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorData = analogRead(A0);
  sensorData = sensorData * 0.48;
  Serial.print("Temperature is ");
  Serial.print(sensorData);
  Serial.println("*C");
  delay(1000);
}
