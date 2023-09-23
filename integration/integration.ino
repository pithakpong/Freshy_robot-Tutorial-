#define ledRedpin 5
#define ledGreenpin 18
#define ledYellowpin 19
#define buttonpin 15
int state = 0;
bool start_red = true;
bool start_green = true;
bool start_yellow = true;
uint32_t Time = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(ledRedpin,OUTPUT);
  pinMode(ledGreenpin,OUTPUT);
  pinMode(ledYellowpin,OUTPUT);
  pinMode(buttonpin,INPUT);
}
void idle()
{
  digitalWrite(ledRedpin,LOW);
  digitalWrite(ledGreenpin,LOW);
  digitalWrite(ledYellowpin,LOW);
  if(digitalRead(buttonpin))
    state = 1;
  else
    state = 0;
}
void taskled_red()
{
  if (start_red)
   {
      Time = millis();
      start_red = false;
   }
   if (millis() - Time < 3000)
   {
      digitalWrite(ledRedpin,HIGH);
      digitalWrite(ledGreenpin,LOW);
      digitalWrite(ledYellowpin,LOW);
   }
  else 
    {
      start_red = true;
      state = 2;
    }
}
void taskled_green()
{
  if (start_green)
   {
      Time = millis();
      start_green = false;
   }
   if (millis() - Time < 3000)
   {
      digitalWrite(ledRedpin,LOW);
      digitalWrite(ledGreenpin,HIGH);
      digitalWrite(ledYellowpin,LOW);
   }
  else 
    {
      start_green = true;
      state = 3;
    }
}
void taskled_yellow()
{
  if (start_yellow)
   {
      Time = millis();
      start_yellow = false;
   }
   if (millis() - Time < 3000)
   {
      digitalWrite(ledRedpin,LOW);
      digitalWrite(ledGreenpin,LOW);
      digitalWrite(ledYellowpin,HIGH);
   }
  else 
    {
      start_yellow = true;
      state = 0;
    }
}
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(state);
  switch (state) 
  {
    case 0 : 
      idle();
    break;
    case 1 :
      taskled_red();
    break;

    case 2 : 
      taskled_green();
    break;

    case 3 : 
      taskled_yellow();
    break;
  }
}
