	.arch msp430g2553
	#include "switches.h"
	
	.global button_one
button_one:
	mov.b &red_on, r12	;red_on into r12
	and.b &green_on, r12	;red && green
	cmp.b #1, r12
	jnz cg			;jump if 1
	mov.b #0, &red_on	;red off
	mov.b #0, &green_on	;green off
	pop r0
cg:				;checking green
	cmp.b #1, &green_on
	jnz sg			;jump if 1
	mov.b #1, &red_on	;red on
	mov.b #0, &green_on	;green off
	pop r0
sg:				;seting green
	mov.b #1, &green_on	;green on
	pop r0
