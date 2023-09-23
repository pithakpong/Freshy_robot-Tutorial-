#define pinanalog 15
#define pindigital 2
void setup() {
  Serial.begin(115200);
  pinMode(pinanalog,INPUT);
  pinMode(pindigital,INPUT);
}

void loop() {
  int analogValue = analogRead(pinanalog);
  int digitalValue = digitalRead(pindigital);

  Serial.print("Analog: ");
  Serial.print(analogValue);
  
  Serial.print("  Digital: ");
  Serial.println(digitalValue);
}
