/** @file   game_initialise.h
    @author Cory Pelham Changxing Gong
    @date   11 Oct 2020
    @brief  Provides status check functions for Space Battle game
*/

#include "game_status_check.h"

/**
 *  Return 1 if NAVSWITCH_PUSH
 *  else return 0
 *
 */
int check_game_status(void) {
    navswitch_update();
    if (navswitch_release_event_p(NAVSWITCH_PUSH)) {
        return 1;
    } else {
        return 0;
    }
}




/**
 * Check for infrared signal(bullet signal, target hit signal, end game signal)
 * check for button pushes if S1 button is pushed, the game ends
 */
void event_check(void) {
    char input = 0;
    if (ir_uart_read_ready_p()){
        input = ir_uart_getc();
        if (input == 8){ // blue led on
            led_set(LED1, 1);
            SCORE += 1;
        }
        else if (input == 9){ //Stop game
            GAME_OVER = 1;
        } else if (input >= 1 && input <= 7){
            add_incoming_bullets(input * 5 - 4);
        }

    }
    if ((PIND&(1<<7))==(1<<7)){ //Push button to end game
        GAME_OVER = 1;
        ir_uart_putc(9);
    }
}



