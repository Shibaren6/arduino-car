//tamamlanMAdı
#define x A0
#define y A1

int samoa=2;
int samob=3;
int samoc=4;
int samod=5;
int somoa=6;
int somob=7;
int somoc=8;
int somod=9;

int amota=10;
int amotb=11;
int amotc=12;
int amotd=13;

float vx=0;
float vy=0;

float k=0;
float t=0;

float u=0;

void setup() {

pinMode(samoa,OUTPUT);
pinMode(samob,OUTPUT);
pinMode(samoc,OUTPUT);
pinMode(samod,OUTPUT);

pinMode(somoa,OUTPUT);
pinMode(somob,OUTPUT);
pinMode(somoc,OUTPUT);
pinMode(somod,OUTPUT);

pinMode(amota,OUTPUT);
pinMode(amotb,OUTPUT);
pinMode(amotc,OUTPUT);
pinMode(amotd,OUTPUT);

pinMode(x,INPUT);
pinMode(y,INPUT);

Serial.begin(9600);

}


void loop() {

vx=analogRead(x);
vy=analogRead(y);

k=map(vx,0,1023,0,255);//vx*255/1023*127.5/123.39;
t=map(vy,0,1023,0,255);//vy*255/1023*127.5/128.82;


if (t<130){

  digitalWrite(amota,LOW);
  digitalWrite(amotb,LOW);
  digitalWrite(amotc,LOW);
  digitalWrite(amotd,LOW);

  digitalWrite(samoa,LOW);
  digitalWrite(samoc,LOW);
  digitalWrite(somoa,LOW);
  digitalWrite(somoc,LOW);
  digitalWrite(samob,LOW);
  digitalWrite(samod,LOW);
  digitalWrite(somob,LOW);
  digitalWrite(somod,LOW);

  if (k>102.5 || k<152.5){

  digitalWrite(samoa,HIGH);
  digitalWrite(samoc,LOW);
  digitalWrite(somoa,HIGH);
  digitalWrite(somoc,LOW);
  digitalWrite(samob,HIGH);
  digitalWrite(samod,LOW);
  digitalWrite(somob,HIGH);
  digitalWrite(somod,LOW);

  delay(10);


}

else if (k<102.5){

  digitalWrite(samoa,LOW);
  digitalWrite(samoc,HIGH);
  digitalWrite(somoa,HIGH);
  digitalWrite(somoc,LOW); 
  digitalWrite(samob,LOW);
  digitalWrite(samod,HIGH);
  digitalWrite(somob,HIGH);
  digitalWrite(somod,LOW); 

  delay(10);

}

else if (k>152.5){

  digitalWrite(samoa,HIGH);
  digitalWrite(samoc,LOW); 
  digitalWrite(somoa,LOW); 
  digitalWrite(somoc,HIGH); 
  digitalWrite(samob,HIGH);
  digitalWrite(samod,LOW); 
  digitalWrite(somob,LOW); 
  digitalWrite(somod,HIGH); 

  delay(10);

}

  delay(10);

}

else if (t>130) {

  analogWrite(amota,t);
  analogWrite(amotb,t);
  analogWrite(amotd,t);
  analogWrite(amotc,t);

  digitalWrite(samoa,HIGH);
  digitalWrite(samoc,HIGH);
  digitalWrite(somoa,HIGH);
  digitalWrite(somoc,HIGH);
  digitalWrite(samob,HIGH);
  digitalWrite(samod,HIGH);
  digitalWrite(somob,HIGH);
  digitalWrite(somod,HIGH);

  delay(10);

if (k>102.5 || k<152.5){

  digitalWrite(samoa,HIGH);
  digitalWrite(samoc,LOW);
  digitalWrite(somoa,HIGH);
  digitalWrite(somoc,LOW);
  digitalWrite(samob,HIGH);
  digitalWrite(samod,LOW);
  digitalWrite(somob,HIGH);
  digitalWrite(somod,LOW);

  delay(10);


}

else if (k<102.5){

  digitalWrite(samoa,LOW);
  digitalWrite(samoc,HIGH);
  digitalWrite(somoa,HIGH);
  digitalWrite(somoc,LOW); 
  digitalWrite(samob,LOW);
  digitalWrite(samod,HIGH);
  digitalWrite(somob,HIGH);
  digitalWrite(somod,LOW); 


  delay(10);


}

else if (k>152.5){

  digitalWrite(samoa,HIGH);
  digitalWrite(samoc,LOW); 
  digitalWrite(somoa,LOW); 
  digitalWrite(somoc,HIGH); 
  digitalWrite(samob,HIGH);
  digitalWrite(samod,LOW); 
  digitalWrite(somob,LOW); 
  digitalWrite(somod,HIGH); 

  delay(10);

}

Serial.print("x= ");
Serial.print(k);

Serial.print(", y= ");
Serial.println(t);

delay(100);
}
}
//tamamlanMAdı
