# Código de Controle de Semáforo
Este código simula o funcionamento de um semáforo utilizando os LEDs nas cores vermelho, amarelo e verde, controlados por um microcontrolador Raspberry Pi Pico. A mudança de estado dos LEDs ocorre a cada 3 segundos, com uma troca cíclica entre os estados de "Vermelho", "Amarelo" e "Verde".

Requisitos
Raspberry Pi Pico (ou qualquer dispositivo baseado no microcontrolador RP2040)
LEDs (Vermelho, Amarelo e Verde) conectados aos pinos GPIO do Raspberry Pi Pico
Configuração do ambiente de desenvolvimento com o Pico SDK
Configuração do Hardware
Conecte os LEDs nas seguintes portas GPIO:
LED Vermelho: GPIO 11
LED Amarelo: GPIO 12
LED Verde: GPIO 13
Utilize resistores de limitação de corrente para cada LED, conectando-os adequadamente aos pinos do microcontrolador.
Explicação do Código
Enumeração de Estados (estado_semaforo): Definimos os estados do semáforo: VERMELHO, AMARELO e VERDE.

Temporizador Repetido: A função repeating_timer_callback é configurada para ser chamada a cada 3 segundos. A cada chamada, ela desliga todos os LEDs e acende o LED correspondente ao estado atual do semáforo, alternando entre os estados de forma cíclica.

Função Principal: No loop principal, o código imprime o estado atual do semáforo no terminal a cada 1 segundo, ajudando a acompanhar o funcionamento do semáforo.

Como Usar
Conecte o Raspberry Pi Pico ao computador e faça a programação utilizando o ambiente de desenvolvimento que suporta o Pico SDK (como o VS Code com a extensão Pico).
como por exemplo o wokwi.
Compile e envie o código para o Raspberry Pi Pico.
Após a execução, os LEDs começarão a piscar conforme o ciclo do semáforo.
