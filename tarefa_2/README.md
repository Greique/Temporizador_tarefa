Controle de LEDs com Botão
Este projeto controla três LEDs (azul, verde e vermelho) com um botão, utilizando o microcontrolador RP2040 (Raspberry Pi Pico). Quando o botão é pressionado, os LEDs acendem simultaneamente e, após 3 segundos, desligam-se um por um em sequência.

Funcionalidade
Sequência de LEDs: Ao pressionar o botão, os LEDs acendem e são desligados após 3 segundos em sequência (azul, verde, vermelho).
Debounce: Evita múltiplos acionamentos do botão durante a sequência.
Temporização: O desligamento dos LEDs é feito com temporização usando alarmes.
Componentes
LEDs: Azul (GPIO 11), Verde (GPIO 13), Vermelho (GPIO 12)
Botão: Conectado ao GPIO 5 com pull-up interno
Como Usar
Conecte os LEDs e o botão aos pinos GPIO conforme indicado.
Compile e faça o upload do código no Raspberry Pi Pico.
Pressione o botão para iniciar a sequência de LEDs.
