#include "MKL25Z4.h"
#include "spi.h"

void delay(uint32_t t);

uint8_t ch;

/// ------------------ PROJETO AMPLIFICADOR PROGRAMÁVEL ------------------------------
///                           Escalas usadas
/// 0x10 - 12.69k
/// 0x20 - 25k
/// 0x30 - 37.27k
/// 0x40 - 50k
/// ----------------------------------------------------------------------------------


int main(void)
{
	// Incializa PTD1 - LED AZUL
	SIM_SCGC5  |= SIM_SCGC5_PORTD_MASK;
	PORT_PCR_REG(PORTD_BASE_PTR,1) = PORT_PCR_MUX(1);
	GPIOD_PDDR |= (1 << 1);

	// Inicializa PTE4 - Pino CS
	SIM_SCGC5  |= SIM_SCGC5_PORTE_MASK;
	PORT_PCR_REG(PORTE_BASE_PTR,4) = PORT_PCR_MUX(1);
	GPIOE_PDDR |= (1 << 4);

	// Set pino CS = 1
	GPIOE_PSOR |= (1 << 4);

	// Inicaliza SPI 1 - Alternativa de Pino 0
	// PTE2 - SPI1_SCK
	// PTE0 - SPI1_MOSI
	// PTE3 - SPI1_MISO
	// Clock = 165 KHz - Prescale = 3 - Divisor = 4
	spi_init(SPI_1,ALT_0,PRESCALE_2,DIVISOR_2,CS_MAN);

    for (unsigned char mago=0;;mago++)
    {
    	// Intervalo de tempo
    	delay(5);
    	// CS = 0 - Inicia a comunicação com o MCP4131
    	GPIOE_PDOR &=~ (1 << 4);
    	// Aguarda perido antes de eviar os dados para o MCP4131
    	// Envia comando de Escrita para o MCP4131
    	spi_send(SPI_1,0x00);
    	spi_send(SPI_1,0x30);
    	// Envia dado  para configurar o valor do potenciometro
    	// Aguarda um perido de tempo para encerrar a comunicação com o MCP4131
    	// CS = 1 - Encerra a comunicação com o MCP4131
    	GPIOE_PSOR |= (1 << 4);
    	GPIOD_PTOR = (1 << 1);
    }

    return 0;
}

void delay(uint32_t t)
{
	uint32_t i = 0;

	for(i=0;i<=t;i++)
	{
		__asm("nop");
	}
}
