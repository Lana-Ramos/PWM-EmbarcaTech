#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h" // biblioteca para controlar o hardware de PWM

#define MOTOR 22
#define LED 12

#define FREQUENCIA  50 // frequência do PWM
#define DIVISER  125 // divisor do clock para o PWM
#define DC_SUAVE  5 // ciclo ativo de ±5µs
#define DELAY 10    // atraso de ajuste

// ciclo de servomotor
uint16_t dc_0 = 500; // 0°
uint16_t dc_90 = 1470;  // 90°
uint16_t dc_180 = 2400;  // 180°

const uint16_t WRAP = 20000; // periodo/wrap
uint slice;

// Função que configura o módulo PWM para o servomotor
void pwm_setup_motor() {
    gpio_set_function(MOTOR, GPIO_FUNC_PWM); //habilitar o pino GPIO como PWM
    uint slice_motor = pwm_gpio_to_slice_num(MOTOR); //obter o canal PWM da GPIO

    pwm_set_clkdiv(slice_motor, DIVISER); //define o divisor de clock do PWM
    pwm_set_wrap(slice_motor, WRAP); //definir o valor de wrap
    pwm_set_enabled(slice_motor, true); //habilita o pwm no slice correspondente
}

// Função que configura o módulo PWM para o LED
void pwm_setup_led() {
    gpio_set_function(LED, GPIO_FUNC_PWM); //habilitar o pino GPIO como PWM
    uint slice_led = pwm_gpio_to_slice_num(LED); //obter o canal PWM da GPIO

    pwm_set_clkdiv(slice_led, DIVISER); //define o divisor de clock do PWM
    pwm_set_wrap(slice_led, WRAP); //definir o valor de wrap
    pwm_set_enabled(slice_led, true); //habilita o pwm no slice correspondente
}

// Função que converte o valor em microsegundos para o nível de PWM
uint16_t convert_us_to_pwm_level(uint16_t us) {
    return (us * WRAP) / 20000;  // microsegundos para nível PWM
}

void movimento_inicial() {
    // Configurar as posições iniciais do servo e LED
    printf("Posição 180°\n");
    pwm_set_gpio_level(MOTOR, convert_us_to_pwm_level(dc_180)); // posição 180°
    pwm_set_gpio_level(LED, convert_us_to_pwm_level(dc_180));  // Ajusta o LED de acordo
    sleep_ms(5000);  // Aguardar 5 segundos na posição 180°
    
    printf("Posição 90°\n");
    pwm_set_gpio_level(MOTOR, convert_us_to_pwm_level(dc_90)); // posição 90°
    pwm_set_gpio_level(LED, convert_us_to_pwm_level(dc_90));  // Ajusta o LED de acordo
    sleep_ms(5000);  // Aguardar 5 segundos na posição 90°

    printf("Posição 0°\n");
    pwm_set_gpio_level(MOTOR, convert_us_to_pwm_level(dc_0));  // posição 0°
    pwm_set_gpio_level(LED, convert_us_to_pwm_level(dc_0));  // Ajusta o LED de acordo
    sleep_ms(5000);  // Aguardar 5 segundos na posição 0°
}

// Função principal
int main() {
    stdio_init_all(); // inicializa o sistema padrão de I/O

    pwm_setup_motor(); // configura o PWM para o servomotor
    pwm_setup_led();   // configura o PWM para o LED

    // Movimentos iniciais
    movimento_inicial();

    // Loop principal para movimentação suave entre os ângulos
    while (true) {
        printf("Movendo para 180°\n");
        for (uint16_t pos = dc_0; pos <= dc_180; pos += DC_SUAVE) {
            pwm_set_gpio_level(MOTOR, convert_us_to_pwm_level(pos));  // Define a posição do servomotor
            pwm_set_gpio_level(LED, convert_us_to_pwm_level(pos));    // Ajusta a intensidade do LED
            sleep_ms(DELAY);  // Atraso de 10ms entre os ajustes
        }

        printf("Movendo para 90°\n");
        for (uint16_t pos = dc_180; pos >= dc_90; pos -= DC_SUAVE) {
            pwm_set_gpio_level(MOTOR, convert_us_to_pwm_level(pos));  // Define a posição do servomotor
            pwm_set_gpio_level(LED, convert_us_to_pwm_level(pos));    // Ajusta a intensidade do LED
            sleep_ms(DELAY);  // Atraso de 10ms entre os ajustes
        }

        printf("Movendo para 0°\n");
        for (uint16_t pos = dc_90; pos >= dc_0; pos -= DC_SUAVE) {
            pwm_set_gpio_level(MOTOR, convert_us_to_pwm_level(pos));  // Define a posição do servomotor
            pwm_set_gpio_level(LED, convert_us_to_pwm_level(pos));    // Ajusta a intensidade do LED
            sleep_ms(DELAY);  // Atraso de 10ms entre os ajustes
        }
    }
}
