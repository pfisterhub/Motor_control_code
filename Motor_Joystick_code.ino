

int ena=8;
int in1=9;
int in2=10;

int enb=7;
int in3=5;
int in4=6;

int vrx = A0;
int vry = A1;
int xVal;
int yVal;
int button = 2;
int x_speed;


void setup() {
  pinMode(button,INPUT);

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(ena,OUTPUT);

  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(enb,OUTPUT);

  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  
  Serial.begin(9600);
}

void loop() {

  xVal=analogRead(vrx);
  delay(100);
  yVal=analogRead(vry);
  //b=digitalRead(button);

  if ((xVal>=490)&&(xVal<=530)){
    digitalWrite(ena,0);
  }
  if (xVal>530){
    x_speed=map(xVal,550,1023,0,255);
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(ena,x_speed);
  }
  if (xVal<490){
    x_speed=map(xVal,470,0,0,255);
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(ena,x_speed);
  }

}
