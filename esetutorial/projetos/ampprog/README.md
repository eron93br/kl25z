# Amplificador programável

Este projeto é consiste em um amplificador operacional com ganho programável para projetos na área de instrumentação e
controle. 

- O MCP4131 (potênciometro digital)

![alt tag](http://www.learningaboutelectronics.com/images/MCP4131-digital-potentiometer-pinout.png)

  O circuito consiste em um C.I. com 08 pinos que se comunica com qualquer MCU via protocolo SPI.
 É necessário o envio de dois bytes, um para o endereçamento (função escrever 0x00) e outro com
 a escala necesária para setar a resistência programável.
 
 
