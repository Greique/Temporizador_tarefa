#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definindo os pinos dos LEDs
#define LED_VERMELHO 11
#define LED_AMARELO 12
#define LED_VERDE 13

// Estado do semáforo
enum estado_semaforo {
    VERMELHO,
    AMARELO,
    VERDE
};

enum estado_semaforo estado_atual = VERMELHO;

// Função callback que será chamada pelo temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    // Desliga todos os LEDs
    gpio_put(LED_VERMELHO, 0);
    gpio_put(LED_AMARELO, 0);
    gpio_put(LED_VERDE, 0);

    // Altera o estado do semáforo
    switch (estado_atual) {
        case VERMELHO:
            gpio_put(LED_VERMELHO, 1);  // Acende o LED vermelho
            estado_atual = AMARELO;
            break;
        case AMARELO:
            gpio_put(LED_AMARELO, 1);  // Acende o LED amarelo
            estado_atual = VERDE;
            break;
        case VERDE:
            gpio_put(LED_VERDE, 1);  // Acende o LED verde
            estado_atual = VERMELHO;
            break;
    }

    return true;  // Retorna true para que o temporizador continue repetindo
}

int main() {
    // Inicializa os pinos GPIO
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(LED_AMARELO);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    // Configura o temporizador para repetir a cada 3 segundos (3000ms)
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop principal
    while (true) {
        // Imprime mensagem a cada segundo
        printf("Semáforo funcionando. Estado atual: ");
        switch (estado_atual) {
            case VERMELHO:
                printf("Vermelho\n");
                break;
            case AMARELO:
                printf("Amarelo\n");
                break;
            case VERDE:
                printf("Verde\n");
                break;
        }

        // Atraso de 1 segundo para impressão
        sleep_ms(1000);
    }

    return 0;
}
