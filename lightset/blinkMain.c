//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "../lcdLib/lcdutils.h"
#include "../lcdLib/lcddraw.h"

short redrawScreen =1;

void wdt_c_handler()
{
  static int secs = 0;

  secs ++;
  if (secs >= 25){
    secs = 0;
    redrawScreen = 1;
  }
}

int main(void) {
  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  led_init();
  lcd_init();
  switch_init();
  buzzer_init();
  shapedraw(COLOR_GREEN);
  buzzer_set_period(0);
  enableWDTInterrupts();/* enable periodic interrupt */

  or_sr(0x8);		/* enable interrupts*/


P1DIR |= LEDS;
P1OUT |= LEDS;


while(1){
  if(redrawScreen){
    redrawScreen =0;
    and_sr(~8);
    clearScreen(COLOR_WHITE);
    shapedraw(colorin);
    or_sr(8);
  }
  P1OUT &= ~LEDS;
  or_sr(0x10);
  P1OUT |= LEDS;
 }
}
