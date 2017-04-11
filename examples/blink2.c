
#include <MKL25Z4.H>

const uint32_t led_mask = 1UL << 1;

void delay(int n) {
 int i;
 for(i = 0; i < n; i++) ;
}

int main (void) 
{
   SIM->SCGC5 |= (1UL << 12); /* Enable Clock to Port D */
	 PORTD->PCR[1] = (1UL << 8); /* Pin PTD1 is GPIO */
   FPTD->PDOR = led_mask; /* switch Blue LED off */
   FPTD->PDDR = led_mask; /* enable PTD1 as Output */

   while(1)
   {
          FPTD->PCOR = led_mask;; // make the pin output low
          delay(5000000);
          FPTD->PDOR = led_mask; // make the pin output high
          delay(5000000);
   }
}
