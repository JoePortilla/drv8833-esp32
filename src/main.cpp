/**
 * \file main.hpp
 * \brief Ejemplo para realizar los movimientos básicos de un motor utilizando el driver DRV8833
 * \author Joseph Santiago Portilla. Ing. Electrónico - @JoePortilla
 */

#include <Arduino.h>
#include "drv8833.hpp"

// Pines
const uint8_t motorPinIN1 = 13;
const uint8_t motorPinIN2 = 17;
// Canales PWM
const uint8_t motorPWM = 0; // Canal PWM 0
// Ajustes PWM
const uint32_t freqPWM = 10000; // Frecuencia del PWM = 10KHz
const uint8_t resPWM = 8;       // Resolución de 8 bits = 256 valores posibles [0, 255]

// Creación de un objeto de la clase Motor
Motor motor;

void setup()
{
  // Ajustes iniciales del motor
  motor.setup(motorPinIN1, motorPinIN2, motorPWM, freqPWM, resPWM);
}

void loop()
{
  // Mover el motor hacia adelante al 80% del PWM
  motor.forward(80);
  delay(2000);

  // Detener el motor
  motor.stop();
  delay(20);

  // Mover el motor hacia atras al 60% del PWM
  motor.reverse(60);
  delay(2000);

  // Detener el motor
  motor.stop();
  delay(1000);
}