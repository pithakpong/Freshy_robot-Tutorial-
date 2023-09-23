#define enpin 25
#define in1pin 26
#define in2pin 27
#define pwmRead 15
#define resolution 8
#define Channel 0
#define freq 5000
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(enpin,OUTPUT); //INPUT // INPUT_PULLUP
  pinMode(in1pin,OUTPUT);
  pinMode(in2pin,OUTPUT);
  ledcSetup(Channel,freq,resolution);
  ledcAttachPin(enpin,Channel);
}

void loop() {
  // put your main code here, to run repeatedly:
  int Read = map(analogRead(pwmRead),0,4095,0,255);
  Serial.println(Read);
  digitalWrite(in1pin,HIGH);
  digitalWrite(in2pin,LOW);
  ledcWrite(Channel,Read);
}
