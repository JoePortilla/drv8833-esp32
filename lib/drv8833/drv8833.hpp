/**
 * \file drv8833.hpp
 * \brief Archivo de cabecera para el driver de motores drv8833
 * \author Joseph Santiago Portilla. Ing. Electrónico - @JoePortilla
 */

#ifndef DRV8833_HPP
#define DRV8833_HPP

/**
 * \brief Clase para instanciar un motor. Incluye funciones
 * que permiten su movimiento, configurar sus pines y los ajustes del PWM.
 */
class Motor
{
public:
    /**
     * \brief Constructor inicial.
     */
    Motor();

    /**
     * \brief Función para configurar los pines de conexión del motor y el PWM.
     * \param pinIN1: GPIO al que se conecta el pin IN1 del motor.
     * \param pinIN2: GPIO al que se conecta el pin IN2 del motor.
     * \param chPWM: Canal del PWM a utilizar con el motor.
     * \param freqPWM: Frecuencia del PWM. (ESP32: De 10 Hz a 40 MHz)
     * \param resPWM: Resolución del PWM. (ESP32: De 1 bit a 16 bits)
     */
    void setup(uint8_t pinIN1, uint8_t pinIN2, uint8_t chPWM, uint32_t freqPWM, uint8_t resPWM);

    /**
     * \brief Función para mover el motor hacia adelante.
     * \param pPWM: Porcentaje de PWM  a aplicar al motor [0, 100] %.
     */
    void forward(uint8_t pPWM);

    /**
     * \brief Función para mover el motor hacia atras.
     * \param pPWM: Porcentaje de PWM  a aplicar al motor [0, 100] %.
     */
    void reverse(uint8_t pPWM);

    /**
     * \brief Función para detener el motor.
     * \param NA: Sin parámetros.
     */
    void stop();

private:
    uint8_t _pinIN1;   // GPIO al que se conecta el pin IN1 del motor.
    uint8_t _pinIN2;   // GPIO al que se conecta el pin IN2 del motor.
    uint8_t _chPWM;    // Canal del PWM a utilizar con el motor.
    uint32_t _freqPWM; // Frecuencia del PWM. (ESP32: De 10 Hz a 40 MHz)
    uint8_t _resPWM;   // Resolución del PWM. (ESP32: De 1 bit a 16 bits)
};

#endif
