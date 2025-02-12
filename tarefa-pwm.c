#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

// Constantes atualizadas
#define SERVO_PIN 22
#define PWM_FREQ 50
#define CLK_DIV 100.0f     // Novo divisor de clock
#define WRAP_VALUE 24999   // (125.000.000Hz / (100 * 50Hz)) - 1 = 24999

// Função de conversão ajustada
uint32_t us_to_level(uint32_t us) {
    // Cada unidade = (20ms / 25000) = 0.8µs
    return (uint32_t)(us * 1.25f); // 1µs = 1.25 unidades
}

int main() {
    set_sys_clock_khz(125000, true);  // Define o clock para 125 MHz
    stdio_init_all();

    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
    uint channel = pwm_gpio_to_channel(SERVO_PIN);

    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, CLK_DIV);
    pwm_config_set_wrap(&config, WRAP_VALUE);
    pwm_init(slice_num, &config, true);

    // Posições convertidas corretamente:
    sleep_ms(200);
    pwm_set_chan_level(slice_num, channel, us_to_level(2400)); // 2400µs → 3000
    sleep_ms(5000);
        
    pwm_set_chan_level(slice_num, channel, us_to_level(1470)); // 1470µs → 1838
    sleep_ms(5000);
        
    pwm_set_chan_level(slice_num, channel, us_to_level(500));  // 500µs → 625
    sleep_ms(5000);

    int32_t i = 500;

    // Transição suave de 0° a 180°
    uint32_t start_level = us_to_level(500);  // 625
    uint32_t end_level = us_to_level(2400);   // 3000

    while(1){
      for (uint32_t i = start_level; i <= end_level; i+=5) {
        pwm_set_chan_level(slice_num, channel, i);
        sleep_ms(10);  // Reduz o delay para maior suavidade
      }
      sleep_ms(500);
      for (uint32_t i = end_level; i >= start_level; i-=5) {
        pwm_set_chan_level(slice_num, channel, i);
        sleep_ms(10);  // Reduz o delay para maior suavidade
      }
      sleep_ms(500);
    }
    
    return 0;
}
