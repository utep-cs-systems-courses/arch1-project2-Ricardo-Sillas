#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buttonOne.h"

unsigned char red_on = 0, green_on = 0, led_changed = 0, dim = 'n';

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};


void led_init() {
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}

void led_update() {
  if(switch_state_changed) {
    if(switch_state_down_one) {                // Calls assembly file, does binary
      button_one();
    }
    else if(switch_state_down_two) {           // Pressing second button resets lights
      red_on = 0;
      green_on = 0;
    }
    else if(switch_state_down_three) {         // Dims light from first button, sends letters accordingly:
      if(red_on && green_on) {
	dim = 'b';                             // b for both
      }
      else if(red_on) {
	dim = 'r';                             // r for red
      }
      else if(green_on) {
	dim = 'g';                             // g for green
      }
      else {
	dim = 'n';                             // n for none
      }
    }
  }
  char ledFlags = redVal[red_on] | greenVal[green_on];
    
  P1OUT &= (0xff - LEDS) | ledFlags; // clear bit for off leds
  P1OUT |= ledFlags;		     // set bit for on leds
  switch_state_changed = 0;
}
