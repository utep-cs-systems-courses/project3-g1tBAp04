//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "../lcdLib/lcdutils.h"
#include "../lcdLib/lcddraw.h"

short redrawscreen =1;

int main(void) {
  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  led_init();
  switch_init();
  buzzer_init();
  shapedraw(COLOR_WHITE);
  buzzer_set_period(0);
  enableWDTInterrupts();/* enable periodic interrupt */

  or_sr(0x18);		/* CPU off, GIE on */
}

void wdt_c_handler(){}
