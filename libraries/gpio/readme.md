# GPIO library - functions

- gpio_direction

A função “gpio_direction” é destinada para inicialização dos GPIOs. Essa, por sua vez, recebe diversos parâmetros, que são eles:
número do “PORT”;
número do pino (Bit);
configuração do pino: entrada ou saída (INPUT ou OUTPUT) e Pull Resistor (habilitado ou desabilitado).
 

- gpio_set

A função “gpio_set” foi desenvolvida para o acionamento dos GPIOs, inicializados no modo de saída (OUTPUT). Os parâmetros que essa função recebe são:
o número do “PORT”;
o número do pino (bit) e;
valor que deseja enviar para a saída (0 ou  1).

- gpio_toggle

A função “gpio_toggle” tem como objetivo inverter valor do GPIO. Essa função recebe dois parâmetros:
o número do "PORT" e;
o número do pino (bit).

- gpio_read

Para ler o valor dos GPIOs foi criada a função “gpio_read”, uma vez que o pino foi inicializado como entrada (INPUT). Essa função recebe dois parâmetros, são eles:
o número do "PORT" e;
o número pino.
