#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"

char interruptTime;
char button_four;

void blink_button_advance() //functions normal light  
{
  shapedraw(COLOR_BLUE);
   char changed = 0;

   if(state == 1){
     buzzer_set_period(2551);
     move_shape_Left(20);
   }


  //half dim
  else if(state == 2){
    buzzer_set_period(3822);
    move_shape_Down(20);
    }
  
   //full dim
  else if (state == 3){
    buzzer_set_period(3822);
    move_shape_Up(20);
  }
   //Order
  else if(state == 4){
     buzzer_set_period(5063);
     move_shape_Right(20);
  }

   buzzer_set_period(0);
   shapedraw(COLOR_BLUE);
}

// led on/off

void turn_on_red(){
  red_on =1;
  led_changed = 1;
  led_update();
}


void turn_off_red(){
  red_on =0;
  led_changed = 1;
  led_update();
}
 void turn_on_green(){
  green_on =1;
  led_changed = 1;
  led_update();
}

void turn_off_green(){
  green_on =0;
  led_changed = 1;
  led_update();
}

