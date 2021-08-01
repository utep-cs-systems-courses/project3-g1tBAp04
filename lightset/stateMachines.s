#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"

	.arch msp430g2553
	.p2align 1,0

	.text
	.global blink_button_advance
	.global state
	.extern move_shape_Left
	.extern move_shape_Down
	.extern move_shape_Up
	.extern move_shape_Right
	.extern clearScreen
	.extern COLOR_BLUE
	.extern COLOR_BLACK

	.data
	.extern colorin
	
state:
	.word 0

jt:
	.word case_1
	.word case_2
	.wprd case_3
	.word case_4


blink_button_advance:
	mov &state, r12
	add r12,r12 		;prep for words
	mov jt(r12), r0 	;set jump to reg

case_1:
	mov #15, r12
	mov &COLOR_BLUE, &colorin
	call #move_shape_Left
	jmp end


case_2:
	mov #15, r12
	mov &COLOR_BLUE, &colorin
	call #move_shape_Down
	jmp end

	
case_3:
	mov #15, r12
	mov &COLOR_BLUE, &colorin
	call #move_shape_Up
	jmp end


	
case_4:
	mov #15, r12
	mov &COLOR_BLUE, &colorin
	call #move_shape_Right
	jmp end

end:
	pop r0			
	
