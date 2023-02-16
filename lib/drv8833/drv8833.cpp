/**
 * \file drv8833.cpp
 * \brief Archivo de implementación para el driver de motores drv8833
 * \author Joseph Santiago Portilla. Ing. Electrónico - @JoePortilla
 */

#include <Arduino.h>
#include "drv8833.hpp"

Motor::Motor() {}

void Motor::setup(uint8_t pinIN1, uint8_t pinIN2, uint8_t chPWM, uint32_t freqPWM, uint8_t resPWM)
{
    // Ajuste de variables
    _pinIN1 = pinIN1;
    _pinIN2 = pinIN2;
    _chPWM = chPWM;
    _freqPWM = freqPWM;
    _resPWM = resPWM;

    // Configuración de pines.
    pinMode(_pinIN1, OUTPUT); // Configuración de pinIN1 como salida.
    pinMode(_pinIN2, OUTPUT); // Configuración de pinIN2 como salida.

    // Ajuste de PWM.
    ledcSetup(_chPWM, _freqPWM, _resPWM); // Se configura la frecuencia y la resolución del canal PWM.
}

void Motor::forward(uint8_t pPWM)
{
    // Separación del canal PWM del pin IN2.
    ledcDetachPin(_pinIN2);
    // Escritura de un valor digital bajo en el pin IN2.
    digitalWrite(_pinIN2, 0);
    // Se conecta el canal PWM al pin IN1.
    ledcAttachPin(_pinIN1, _chPWM);
    // Calculo del ciclo de trabajo del PWM en función del porcentaje deseado y la resolución configurada.
    uint16_t pwmDutyCycle;
    pwmDutyCycle = round(pow(2, _resPWM) * (pPWM / 100.0));
    // Escritura del ciclo de trabajo al canal del PWM.
    ledcWrite(_chPWM, pwmDutyCycle);
}

void Motor::reverse(uint8_t pPWM)
{
    // Separación del canal PWM del pin IN1.
    ledcDetachPin(_pinIN1);
    // Escritura de un valor digital bajo en el pin IN1.
    digitalWrite(_pinIN1, 0);
    // Se conecta el canal PWM al pin IN2.
    ledcAttachPin(_pinIN2, _chPWM);
    // Calculo del ciclo de trabajo del PWM en función del porcentaje deseado y la resolución configurada.
    uint16_t pwmDutyCycle;
    pwmDutyCycle = round(pow(2, _resPWM) * (pPWM / 100.0));
    // Escritura del ciclo de trabajo al canal del PWM.
    ledcWrite(_chPWM, pwmDutyCycle);
}

void Motor::stop()
{
    // Separación del canal PWM del pin IN1.
    ledcDetachPin(_pinIN1);
    // Separación del canal PWM del pin IN2.
    ledcDetachPin(_pinIN2);
    // Escritura de un valor digital bajo en el pin IN1.
    digitalWrite(_pinIN1, 0);
    // Escritura de un valor digital bajo en el pin IN2.
    digitalWrite(_pinIN2, 0);
}
