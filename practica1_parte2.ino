/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Parte 2 - Práctica 1
   Dev: Profe. Alejandro Lopez Navas
   Fecha: 9 de julio. 
*/
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define IN1  12
#define IN2  11
#define IN3  10
#define IN4  9
#define adc A0
#define Obstacles 3
#define hall 4
#define direccion_lcd 0x27
#define filas 2
#define columnas 16
#define tiempo delay(1000);

LiquidCrystal_I2C lcdSicajan(direccion_lcd, columnas, filas); 

int contador = 0;

bool state_sensor1;   

bool state_sensor2;

unsigned int valor_adc_pot;

unsigned char velocidad;

int paso [8][4] =
{
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};
 
void setup()
{
  Serial.begin(9600);
  lcdSicajan.init();
  lcdSicajan.backlight();
  lcdSicajan.setCursor(0, 0);
  lcdSicajan.print("Contador de rev.");
  lcdSicajan.setCursor(0, 1);
  lcdSicajan.print("No. de rev:0");
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(adc, INPUT);         
  pinMode(Obstacles, INPUT);
  pinMode(hall, INPUT); 
  if(state_sensor1 == HIGH){
    lcdSicajan.clear();
      lcdSicajan.setCursor(0, 0);
      lcdSicajan.print("Contador de rev.");
      lcdSicajan.setCursor(0, 1);
      lcdSicajan.print("No. de rev: ");
      lcdSicajan.print(0);
  }
}

void loop()
{ 
  state_sensor1 = digitalRead(Obstacles);
  state_sensor2 = digitalRead(hall);   
  valor_adc_pot = analogRead(adc);		
  velocidad = map(valor_adc_pot,0,1023,0,10);    
  Serial.print("El valor leido por el ADC es de: ");
  Serial.println(valor_adc_pot); 

  if(state_sensor1 == LOW){
    for (int i = 0; i < 8; i++)
    {
      digitalWrite(IN1, paso[i][0]);
      digitalWrite(IN2, paso[i][1]);
      digitalWrite(IN3, paso[i][2]);
      digitalWrite(IN4, paso[i][3]);
      delay(velocidad);
    }
    if(state_sensor2 == LOW){
      if(velocidad > 255 || velocidad <508){
      lcdSicajan.clear();
      lcdSicajan.setCursor(0, 0);
      lcdSicajan.print("Contador de rev.");
      lcdSicajan.setCursor(0, 1);
      lcdSicajan.print("No. de rev: ");
      lcdSicajan.print("5RPM");
      
      }
      if(velocidad > 509 || velocidad <764){      
      lcdSicajan.setCursor(0, 0);
      lcdSicajan.print("Contador de rev.");
      lcdSicajan.setCursor(0, 1);
      lcdSicajan.print("No. de rev: ");
      lcdSicajan.print("4RPM");
      
      }
      if(velocidad > 765 || velocidad < 996){
      lcdSicajan.clear();
      lcdSicajan.setCursor(0, 0);
      lcdSicajan.print("Contador de rev.");
      lcdSicajan.setCursor(0, 1);
      lcdSicajan.print("No. de rev: ");
      lcdSicajan.print("2RPM");
      
      }
    }
    else{
      lcdSicajan.clear();
      lcdSicajan.setCursor(0, 0);
      lcdSicajan.print("Contador de rev.");
      lcdSicajan.setCursor(0, 1);
      lcdSicajan.print("No. de rev:");
      lcdSicajan.print(0);

    }
  }
}