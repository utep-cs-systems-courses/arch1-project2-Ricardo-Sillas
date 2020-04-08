	.arch msp430g2553

	.data
color:
	.word 0

	.text

jt:
	.word option1
	.word default
	.global the_switch

the_switch:
	cmp #2, &color
	jc default
	mov &color, r12		;Move options into r12
	add r12, r12		;r12 * 2
	mov jt(r12), r0

option1:
	call #toggle_red	;toggle red
	mov #1, &color		;Setting to option2
	jmp out			;go to out

default:
	call #toggle_green	;toggle green
	mov #0, &color		;color option1
	jmp out			;go to out

out:
	pop r0			;returning
