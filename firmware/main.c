
#include <iotiny13a.h>

// Port bits definition. Option 1 (no external multiplexer)
// PB0 (CIA_SEL1n) -  Input
// PB1 (CIA_SEL0n) -  Input
// PB2 (HDR_SEL1n) -  Output
// PB3 (HDR_SEL0n) -  Output
// PB4 (LED)       -  Output
// PB5 (RESETn)    -  Input

// PORTB bits
#define CIA_SEL1n       (1 << 0)
#define CIA_SEL0n       (1 << 1)
#define HDR_SEL1n       (1 << 2)
#define HDR_SEL0n       (1 << 4)
#define LED             (1 << 3)
#define RESETn          (1 << 5)

unsigned char swap_enable = 0; // Swap disabled at power-up
unsigned char swap_changed = 0; 
unsigned int blink_cnt = 0;
unsigned char PORTB_BUFFER;
unsigned long reset_timeout_counter = 0;
unsigned long reset_down_counter = 0;
unsigned char reset_counter = 0;




int main(void)
{
  // Enable pull-ups configuration
  MCUCR &= ~(1<<PUD);
  
  // Port setup. Option 1 (no external multiplexer)
  PORTB_BUFFER = CIA_SEL1n | CIA_SEL0n | HDR_SEL1n | HDR_SEL0n | RESETn;
  PORTB = PORTB_BUFFER;
  DDRB =  HDR_SEL1n | HDR_SEL0n | LED;
  
  
  
  
  while(1)
  {
	  /*
	  if(++blink_cnt >= 1000)
	  {
		  if(PORTB_BUFFER & LED) PORTB_BUFFER &= ~LED;
		   else PORTB_BUFFER |= LED;
		  blink_cnt = 0;
	  }
*/
	// RESET monitoring
	if((PINB & RESETn) == 0)
	{
		//RESET is LOW
		if(reset_down_counter < 50000) reset_down_counter++;
		else
		{
			  if(swap_changed == 0)
			  {
				  swap_enable ^= 0xFF;
				  swap_changed = 1;
			  }
		  
		}
		reset_timeout_counter = 0;
	}
	 else
	 {
		 // RESET is HIGH
 		if(reset_down_counter >= 50000) // Long reset detected - swap drives 
		 { 
//			 swap_enable ^= 0xFF;
		 }
		  else 
		   if(reset_down_counter > 1000) // Debouncing time 5ms
		   {
			   reset_counter++;
			   if(reset_counter == 3)
			   {
				   reset_counter = 0;
				   swap_enable ^= 0xFF;
			   }
		   }

		 reset_down_counter = 0;
		 swap_changed = 0;
	 }
	  
	if(reset_timeout_counter < 3000000) 
	{
		reset_timeout_counter++;
	}
	 else
	 {
 		reset_counter = 0;
 		reset_down_counter = 0;
	 }
	  
	  if(swap_enable)
	  {
		  PORTB_BUFFER |= LED;
		  // SEL0
		  if((PINB & CIA_SEL0n) == CIA_SEL0n) PORTB_BUFFER |= HDR_SEL1n;
		  else PORTB_BUFFER &= ~HDR_SEL1n;
		  // SEL1
		  if((PINB & CIA_SEL1n) == CIA_SEL1n) PORTB_BUFFER |= HDR_SEL0n;
		  else PORTB_BUFFER &= ~HDR_SEL0n;
	  }
	  else
	  {
		   PORTB_BUFFER &= ~LED;
		  // SEL0
		  if((PINB & CIA_SEL0n) == CIA_SEL0n) PORTB_BUFFER |= HDR_SEL0n;
		  else PORTB_BUFFER &= ~HDR_SEL0n;
		  // SEL1
		  if((PINB & CIA_SEL1n) == CIA_SEL1n) PORTB_BUFFER |= HDR_SEL1n;
		  else PORTB_BUFFER &= ~HDR_SEL1n;

	  }
	  
	  // Write output bits at once
	  PORTB = PORTB_BUFFER;
  }
}