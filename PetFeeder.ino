#include <Servo.h>
 
#define SERVO_PIN 3 // Porta servo (Digital 3 PWM)
#define POT_PIN A3 // Porta potenciomentro
#define VIN_POT_PIN 2 // Vin potenciometro (Arduino Micro)

Servo s; // Servo

int deposito = 0; // Deposito atual
int nDepositos = 9; // Numero de depositos
int angulo = 20; // Angulo de rotacao do servo por deposito

// Tempo com base no potenciomentro
int pot; // Valor do potenciometro
float intervalomax = 1.0; // Intervalo maximo em horas
float intervalomaxms = intervalomax * 3600.0 * 1000.0;

// Aternativa para potenciometro
float intervalo = 1.0; // Tempo em horas 
float intervaloms = 3600.0 * 1000.0 * intervalo;

int pos; // Posição atual servo
int posfinal; // Posicao final do Servo no intervalo

void setup ()
{
  Serial.begin(9600);
  
  s.write(0);
  s.attach(SERVO_PIN);
  
  pinMode(VIN_POT_PIN,OUTPUT);
  digitalWrite(VIN_POT_PIN,HIGH);
  
  pinMode(POT_PIN,INPUT);
  pot = analogRead(POT_PIN);
  
  delay(2000);
}
 
void loop()
{
  pos = 0;
  s.write(pos);

  for (deposito = 1; deposito <= nDepositos; deposito++) {
//    intervaloms = intervalomaxms * pot / 1024.0;
    delay(intervaloms);
    
    posfinal = deposito * angulo;
    for(; pos < posfinal; pos++)
    {
      s.write(pos);
      delay(15);
    } 
  }

  delay(2000);
  digitalWrite(2,LOW);
  s.detach();
}
