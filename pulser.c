#define F_CPU 1200000UL
#include <avr/io.h>
#include <avr/sleep.h>

int main( void )
{
   TCCR0A = _BV( COM0A0 ) + _BV( WGM01 );
                              // Toggle OC0A on Compare Match
                              // CTC Mode

   TCCR0B   = 0x05;           // 1200000/1024 => 1172/sec
   OCR0A    = 117;            // 10 interrupts/sec

   DDRB  = 0x07;

   while(1)
   {
      // All processing is handle by the Timer
      // Nothing to do here so just sleep

      set_sleep_mode( SLEEP_MODE_IDLE );
      sleep_mode();
   }
}
