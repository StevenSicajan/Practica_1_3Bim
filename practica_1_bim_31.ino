/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Práctica 1 - Parte 1
   Dev: Profe. Alejandro Lopez Navas
   Fecha: 20 de junio
   
*/
#include <Adafruit_NeoPixel.h>
#define a 5
#define b 6
#define c 7
#define d 8
#define e 9
#define f 10
#define g 11
#define tiempo delay(500);
#define tiempo2 delay(700);
#define Cantidad_Leds 12
#define pin_Led A0

enum colores
{
   rojo, 
   verde,
};

#define trigger A4
#define echo A5

long sensor;
long distancia;

int personas = 0;

Adafruit_NeoPixel anillo(Cantidad_Leds,pin_Led, NEO_GRB + NEO_KHZ800);

void setColor(int color);


void setup(){
  Serial.begin(9600);
   anillo.begin();
  setColor(verde);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(trigger, LOW);
}

void loop(){
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  sensor = pulseIn(echo, HIGH);
  tiempo
  distancia = sensor/59;
  Serial.print("La distancia es de: ");
  Serial.print(distancia);
  Serial.print("cm");
  Serial.println();
  
  if(distancia > 5 && distancia <= 9){
  personas = personas+1;
  
     
    if(personas == 1){
      setColor(verde);
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      Serial.print("Aforo: ");
      Serial.print(personas);
      Serial.print(" persona(s)");
      Serial.println();
    }
    if(personas == 2){
      setColor(verde);
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(g, HIGH);
      Serial.print("Aforo: ");
      Serial.print(personas);
      Serial.print(" persona(s)");
      Serial.println();
    }
    if(personas == 3){
      setColor(verde);
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, LOW);
      digitalWrite(g, HIGH);
      Serial.print("Aforo: ");
      Serial.print(personas);
      Serial.print(" persona(s)");
      Serial.println();
    }
    if(personas == 4){
      setColor(verde);
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      Serial.print("Aforo: ");
      Serial.print(personas);
      Serial.print(" persona(s)");
      Serial.println();
    }
    if(personas == 5){
      setColor(verde);
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      Serial.print("Aforo: ");
      Serial.print(personas);
      Serial.print(" persona(s)");
      Serial.println();
    }
    if(personas == 6){
      setColor(verde);
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      Serial.print("Aforo: ");
      Serial.print(personas);
      Serial.print(" persona(s)");
      Serial.println();
    }
    if(personas == 7){
      setColor(verde);
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      Serial.print("Aforo: ");
      Serial.print(personas);
      Serial.print(" persona(s)");
      Serial.println();
    }
    if(personas == 8){
      setColor(verde);
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      Serial.print("Aforo: ");
      Serial.print(personas);
      Serial.print(" persona(s)");
      Serial.println();
    }
    if(personas == 9){
      setColor(verde);
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      Serial.print("Aforo: ");
      Serial.print(personas);
      Serial.print(" persona(s)");
      Serial.println();
    }
    if(personas > 9){
      setColor(rojo);
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, HIGH);
      Serial.print("Aforo lleno");
      Serial.println();
    }
    tiempo2
  }

}

void setColor(int color)
{
  switch(color)
  {
    case(rojo):
    {
        for(int i =0; i<25; i++)
        {
          anillo.setPixelColor(i,anillo.Color(255,0,0));
          anillo.show();  //muestro el color en el led
        } 
      break;
    }
    
    case(verde):
    {
        for(int i =0; i<25; i++)
        {
          anillo.setPixelColor(i,anillo.Color(124,252,0));
          anillo.show();  //muestro el color en el led
        }
      break;
    }
  
  }
}
