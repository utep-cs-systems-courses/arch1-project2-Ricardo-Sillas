#include <msp430.h>
#include "switches.h"
#include "led.h"

char switch_state_down_one, switch_state_down_two, switch_state_down_three, switch_state_down_four, switch_state_changed; /* All switches */

static char switch_update_interrupt_sense() {
  char p1val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p1val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p1val | ~SWITCHES);	/* if switch down, sense up */
  return p1val;
}

void switch_init() {			/* setup switch */
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE = SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void switch_interrupt_handler() {
  char p1val = switch_update_interrupt_sense();
  switch_state_down_one = (p1val & SW1) ? 0 : 1;
  switch_state_down_two = (p1val & SW2) ? 0 : 1;
  switch_state_down_three = (p1val & SW3) ? 0 : 1;
  switch_state_down_four = (p1val & SW4) ? 0 : 1;
  led_update();
  switch_state_changed = 1;
}
