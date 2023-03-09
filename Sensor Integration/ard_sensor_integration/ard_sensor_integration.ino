void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor_data = analogRead(A0);

  sensor_data = sensor_data * 0.48;

  Serial.print("Temperature is");
  Serial.print(sensor_data);
  Serial.print("*C");
  Serial.println();
  delay(1000);
}
