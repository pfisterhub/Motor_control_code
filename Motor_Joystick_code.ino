//with this code, you can control 2 motors

//motor driver pins connection
int ena=8;
int in1=9;
int in2=10;

int enb=7;
int in3=5;
int in4=6;

//joystick analog pins connections
int vrx = A0;
int vry = A1;
int xVal;
int yVal;
int button = 2;
int x_speed;


void setup() {
  //we define motor driver outputs
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
  //serial begin in case we would want to read data
  Serial.begin(9600);
}

void loop() {
  
  xVal=analogRead(vrx);
  delay(100);
  yVal=analogRead(vry);
  
  //if we dont move the joystick, motors dont run
  if ((xVal>=490)&&(xVal<=530)){
    digitalWrite(ena,0);
  }
  
  //bigger or smaller values make motor run, from 0 to 255 progressively
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
