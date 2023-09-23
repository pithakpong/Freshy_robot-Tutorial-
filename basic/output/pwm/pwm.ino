#define pin 15
#define Channel 0
#define resolution 8
#define freq 5000
void setup() {
  // put your setup code here, to run once:
  ledcSetup(Channel,freq,resolution);
  ledcAttachPin(pin,Channel);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int dutyCycle = 0;dutyCycle <= 255; dutyCycle++)
  {
    ledcWrite(Channel,dutyCycle);
    delay(15);
  }
  for (int dutyCycle = 255;dutyCycle >= 0; dutyCycle--)
  {
    ledcWrite(Channel,dutyCycle);
    delay(15);
  }
}
