
#include <MKL25Z4.H>

// delay function
void delay(int n) 
{
 int i;
 for(i = 0; i < n; i++) ;
}

int main (void) 
{
   SIM->SCGC5 |= 0x0400;     // habilita clock na Port B
   PORTB->PCR[18] = 0x0100; //  PTB18 como GPIO (saida)
   FPTB->PDOR = 0x40000;    // switch Red/Green LED off
   FPTB->PDDR = 0x40000;    // define PTB18 as Output
   while(1)
   {
          FPTB->PCOR = 0x40000; // make the pin output low
          delay(5000000);
          FPTB->PSOR = 0x40000; // make the pin output high
          delay(5000000);
   }
}
