#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include <stdio.h>

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  
  if(switch_state_down_two) {          // For second button, pattern speed
    if(++blink_count == 125) {
      state_advance();
      blink_count = 0;
    }
  }
  
  if(switch_state_down_three) {        // For third button, makes it dim
    if(++blink_count == 1) {
      state_advance();
      blink_count = 0;
    }
  }
  
  if(switch_state_down_four) {         // For fourth button, uses tempo array for speed
    if(num % 2 == 0) {
      if(++blink_count == tempo[num/2+1]) {     // Playing that frequency for certain amount of time
	state_advance();
	blink_count = 0;
      }
    }
    else {               // Having little pauses between frequencies.
      if(++blink_count == 5) {
	state_advance();
	blink_count = 0;
      }
    }
  }
}
