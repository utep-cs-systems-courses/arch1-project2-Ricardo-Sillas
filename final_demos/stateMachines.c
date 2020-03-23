#include <msp430.h>
#include "switches.h"
#include "led.h"

//int as[] = {2703,1804,2145,0,2145,2408,2703,0,2703,2025,2145,0,2145,2408,0,2408,2703,0,2703,1804,2145,0,2145,2408,2703,0,2703,3214,3608,0,2703,0,2703,1804,2145,0,2145,2408,0,2408,2703,0,2703,2025,2145,0,2145,2408,0,2408,2703,0,2703,1804,2145,0,2145,2408,2703,0,2703,2408,3214};    // Frequency to play
int as[] = {2703,1804,2145,2145,2408,2703,2703,2025,2145,2145,2408,2408,2703,2703,1804,2145,2145,2408,2703,2703,3214,3608,0,2703,2703,1804,2145,2145,2408,2408,2703,2703,2025,2145,2145,2408,2408,2703,2703,1804,2145,2145,2408,2703,2703,2408,3214};

//int tempo[] = {124,62,62,1,124,62,62,1,62,124,62,1,62,62,1,62,124,1,62,62,62,1,124,62,62,1,62,124,186,124,62,1,62,62,62,1,62,62,1,62,62,1,62,124,62,1,62,62,1,62,62,1,62,124,62,1,62,124,62,1,62,124,186};    // How long to play frequency
int tempo[] = {124,62,62,124,62,62,62,124,62,62,62,62,124,62,62,62,124,62,62,62,124,186,124,62,62,62,62,62,62,62,62,62,124,62,62,62,62,62,62,124,62,62,124,62,62,124,186};

int num = 0;

char toggle_red() {           // Toggle red
  static char state = 0;
  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
}

char toggle_green() {	           // Toggle green
  static char state = 0;

  switch (state) {
  case 0:
    green_on = 1;
    state = 1;
    break;
  case 1:
    green_on = 0;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
}

void state_advance() {
  char changed = 0; 
  if(!switch_state_down_four) {            // If other buttons besides four down, resets song and time array
    num = 0;
    buzzer_set_period(0);
  }
  if(switch_state_down_three) {            // If third button down, dims light
    if(dim == 'b') {
      toggle_red();
      toggle_green();
      changed = 1;
    }
    else if(dim == 'r') {
      changed = toggle_red();
    }
    else if(dim == 'g') {
      changed = toggle_green();
    }
  }
  if(switch_state_down_two) {             // If second button down, toggles lights accordingly
    static enum {R=0, G=1} color = R;
    if(color == G) {
      changed = toggle_green();
      color = R;
    }
    else if(color == R) {
      changed = toggle_red();
      color = G;
    }
  }
  led_update();
  if(switch_state_down_four) {            // If fourth button down, plays song
    buzzer_set_period(as[num]);
    num++;
  }
}
