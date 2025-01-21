#define x A0 //joystick x düzlemi
#define y A1 //joystick y düzlemi

int samo1a=2; //sağ motor 1.giriş a +5v-0v
int samo1b=3; //sağ motor 1.giriş b +5v-0v

int samo2a=4; //sağ motor 2.giriş a +5v-0v
int samo2b=5; //sağ motor 2.giriş b +5v-0v

int somo1a=7; //sol motor 1.giriş a +5v-0v
int somo1b=8; //sol motor 1.giriş b +5v-0v

int somo2a=12; //sol motor 2.giriş a +5v-0v  
int somo2b=13; //sol motor 2. giriş b +5v-0v 

int amoa=6; //arka motor, iki teker için de
int amob=9; //arka motor, iki teker için de
int amoc=10; //arka motor, iki teker için de
int amod=11; //arka motor, iki teker için de

float k = 0;
float t = 0;

int vx=0;
int vy=0;

void setup() {

  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);

  pinMode(x,INPUT);
  pinMode(y,INPUT);

  Serial.begin(9600);

}

void loop() {

  vx=analogRead(x); //x değerini joystick den oku ve vx'e ata
  vy=analogRead(y); //y değerini joystick den oku ve vy'ye ata

  k=map(vx,0,1023,0,255); //1023 değerini 255'e dönüştür
  t=map(vy,0,1023,0,255); //1023 değerini 255'e dönüştür

  if (t<132.5) { //durma durumu, gaz yok, tüm tekerler dur
    analogWrite(amoa,0);
    analogWrite(amob,0);
    analogWrite(amoc,0);
    analogWrite(amod,0);

    digitalWrite(samo1a,LOW);
    digitalWrite(samo1b,LOW);
    digitalWrite(samo2a,LOW);
    digitalWrite(samo2b,LOW);

    digitalWrite(somo1a,LOW);
    digitalWrite(somo1b,LOW);
    digitalWrite(somo2a,LOW);
    digitalWrite(somo2b,LOW);

    delay(10);

  }

  else { //hareket halinde

    analogWrite(amoa,t);
    analogWrite(amob,t);
    analogWrite(amoc,t);
    analogWrite(amod,t);

    delay(10);

  }
    if (k>147.5) { //sağa dönme durumu. Sağ motorlar terse akım ver, direnç oluştur

     digitalWrite(samo1a,LOW);
     digitalWrite(samo1b,LOW);
     digitalWrite(samo2a,HIGH);
     digitalWrite(samo2b,HIGH);

     digitalWrite(somo1a,HIGH);
     digitalWrite(somo1b,HIGH);
     digitalWrite(somo2a,LOW);
     digitalWrite(somo2b,LOW);
  
      delay(10);

    }
    else if (k<110) { //sola dönme durumu. Sol motorlar terse akım ver, direnç oluştur

      digitalWrite(samo1a,HIGH);
      digitalWrite(samo1b,HIGH);
      digitalWrite(samo2a,LOW);
      digitalWrite(samo2b,LOW);

      digitalWrite(somo1a,LOW);
      digitalWrite(somo1b,LOW);
      digitalWrite(somo2a,HIGH);
      digitalWrite(somo2b,HIGH);

        delay(10);

   }
    else { //düz gitme durumu. Tüm motorlar ileri!!

      digitalWrite(samo1a,HIGH);
      digitalWrite(samo1b,HIGH);
      digitalWrite(samo2a,LOW);
      digitalWrite(samo2b,LOW);

      digitalWrite(somo1a,HIGH);
      digitalWrite(somo1b,HIGH);
      digitalWrite(somo2a,LOW);
      digitalWrite(somo2b,LOW);

       delay(10);
    } 
    //Yaz efendi Yaaazzzz!!!
  Serial.print("x= ");
  Serial.print(k);
  Serial.print("y= ");
  Serial.println(t);


}
