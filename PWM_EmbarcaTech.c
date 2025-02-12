#include <stdio.h> 
#include "pico/stdlib.h" 
#include "hardware/pwm.h" // biblioteca para controlar o hardware de PWM

#define MOTOR 22 
#define LED 12

#define FREQUENCIA  50 // frequência do PWM
#define DIVISER  125 // divisor do clock para o PWM
#define DC_SUAVE  5 //  ciclo ativo de ±5µs
#define DELAY 10    // atraso de ajuste

// ciclo de servomotor
uint16_t dc_0 = 500; // 0°
uint16_t dc_90 = 1470;  // 90°
uint16_t dc_180 = 2400;  // 180°

const uint16_t WRAP = 20000; // periodo/wrap
uint slice;


//função que configura o módulo PWM
void pwm_setup()
{
    gpio_set_function(LED, GPIO_FUNC_PWM); //habilitar o pino GPIO como PWM

    uint slice = pwm_gpio_to_slice_num(LED); //obter o canal PWM da GPIO

    pwm_set_clkdiv(slice, DIVISER); //define o divisor de clock do PWM

    pwm_set_wrap(slice, WRAP); //definir o valor de wrap

    pwm_set_gpio_level(LED, 100); //definir o cico de trabalho (duty cycle) do pwm

    pwm_set_enabled(slice, true); //habilita o pwm no slice correspondente
}


//função principal
int main()
{
    stdio_init_all(); //inicializa o sistema padrão de I/O
    
    pwm_setup(); //configura o PWM

    uint up_down = 1; //variável para controlar se o nível do LED aumenta ou diminui

    //loop principal
    while (true) {

        printf("Ciclo ativo:%d\n", led_level);//imprimir ciclo ativo do PWM - valor máximo é 2000
        
        pwm_set_gpio_level(LED, led_level); //define o nível atual do PWM (duty cycle)

        sleep_ms(1000); // Atraso de 1 segundo

        if (up_down) 
        {
            led_level += LED_STEP; // Incrementa o nível do LED
            if (led_level >= WRAP)
                up_down = 0; // Muda direção para diminuir quando atingir o período máximo
        }
        else
        {
            led_level -= LED_STEP; // Decrementa o nível do LED
            if (led_level <= LED_STEP)
                up_down = 1; // Muda direção para aumentar quando atingir o mínimo
        }

    }
}
