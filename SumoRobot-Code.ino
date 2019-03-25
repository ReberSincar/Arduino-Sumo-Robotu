int IN1 =5;
int IN2 =6;
int IN3 = 7;
int IN4 =8;
int inputPin = 2;
int val = 0;
 
void setup()
{
Serial.begin(9600);
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);
pinMode(inputPin, INPUT);
 
}
 
void loop(){
  val = digitalRead(inputPin);
  Serial.println(val);
  if (val == 0) 
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }
   
  else if (val == 1) 
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
}
