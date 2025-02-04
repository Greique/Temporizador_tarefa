#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

// Definição dos pinos
#define LED_VERDE  13
#define LED_VERMELHO 12
#define LED_AZUL   11
#define BOTAO      5

// Variáveis de controle
volatile bool pode_pressionar = true;
volatile int estado_leds = 0;

// Prototipação das funções
bool apagar_led1(alarm_id_t id, void *user_data);
bool apagar_led2(alarm_id_t id, void *user_data);
bool apagar_led3(alarm_id_t id, void *user_data);
void pressionar_botao(uint gpio, uint32_t eventos);

int main() {
    stdio_init_all();

    // Configuração dos LEDs como saída
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);

    // Configuração do botão como entrada com pull-up interno
    gpio_init(BOTAO);
    gpio_set_dir(BOTAO, GPIO_IN);
    gpio_pull_up(BOTAO);

    // Configuração da interrupção do botão
    gpio_set_irq_enabled_with_callback(BOTAO, GPIO_IRQ_EDGE_FALL, true, &pressionar_botao);

    while (1) {
        sleep_ms(100);  // Pequeno atraso para evitar loop excessivo
    }

    return 0;
}

// Callback para apagar o primeiro LED (Azul)
bool apagar_led1(alarm_id_t id, void *user_data) {
    gpio_put(LED_AZUL, 0);
    add_alarm_in_ms(3000, apagar_led2, NULL, false);
    return false; // Executa apenas uma vez
}

// Callback para apagar o segundo LED (Verde)
bool apagar_led2(alarm_id_t id, void *user_data) {
    gpio_put(LED_VERMELHO, 0);
    add_alarm_in_ms(3000, apagar_led3, NULL, false);
    return false;
}

// Callback para apagar o terceiro LED (Vermelho) e liberar o botão
bool apagar_led3(alarm_id_t id, void *user_data) {
    gpio_put(LED_VERDE, 0);
    pode_pressionar = true; // Libera o botão para nova ativação
    return false;
}

// Callback de interrupção para detectar o botão pressionado
void pressionar_botao(uint gpio, uint32_t eventos) {
    if (!pode_pressionar) return; // Bloqueia múltiplos acionamentos durante a sequência

    pode_pressionar = false; // Bloqueia novas ativações até os LEDs apagarem

    // Acende todos os LEDs
    gpio_put(LED_AZUL, 1);
    gpio_put(LED_VERDE, 1);
    gpio_put(LED_VERMELHO, 1);

    // Inicia a sequência de desligamento
    add_alarm_in_ms(3000, apagar_led1, NULL, false);
}
