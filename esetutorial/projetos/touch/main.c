#define LED_VERMELHO   (1<<18)   // 1 para saída.
#define LED_VERDE     (1<<19)
#define ENTRADA        (1<<1)
#define PIN_ENTRADA     (0<<1) // 0 para entrada.

void TSS1_fCallBack0(TSS_CONTROL_ID u8ControlId)
{
  (void)u8ControlId; /* avoid warning */
  /*LED1_Put(TSS1_cKey0.Position<=20);
  LED2_Put(TSS1_cKey0.Position>20 && TSS1_cKey0.Position<=40);
  LED3_Put(TSS1_cKey0.Position>40 && TSS1_cKey0.Position<=64);*/

  // Habilitar o Clock dos Ports que serão utilizados (PORTB E PORTE).
  SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTE_MASK;


  // Configura o PinMux dos Ports como GPIO.
  //PORTE_PCR1 = PORT_PCR_MUX(1) | PORT_PCR_PE_MASK;
  PORTB_PCR18 = PORT_PCR_MUX(1);
   PORTB_PCR19 = PORT_PCR_MUX(1);


   // Configuração da Direção dos Ports.
   //GPIOE_PDDR &= PIN_ENTRADA;
   GPIOB_PDDR |= LED_VERMELHO | LED_VERDE;

   //Configure();
  //for(;;)
  //{
  	//TSS_Task();
    // Tecla está pressionada?
    if(TSS1_cKey0.Position<=32)
    {
       // Não, liga o LED Vermeho e desliga o Verde.
       GPIOB_PSOR |= LED_VERDE;     // Desliga LED Verde.
       GPIOB_PCOR |= LED_VERMELHO;     // Liga LED Vermelho.
    }
    else
    {
       // Sim, liga o LED Verde e desliga o Vermelho.
       GPIOB_PSOR |= LED_VERMELHO;     // Desliga LED Vermelho.
       GPIOB_PCOR |= LED_VERDE;     // Liga LED Verde.
    }
  //}
}
