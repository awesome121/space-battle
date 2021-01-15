/** @file   component_update.c
    @author Cory Pelham Changxing Gong
    @date   11 Oct 2020
    @brief  Applies updates for Space Battle game.

*/
#include "components_update.h"
#include "system.h"
#include "ir_uart.h"
#include "navswitch.h"
#include "led.h"
#include "button.h"
#include "game.h"
#include <math.h>





/**
 * Add new bullets in the incoming bullets array if detect infrared signal
 */
void add_incoming_bullets(int position) {
    for (int i = 0; i < MAX_NUM_BULLETS; i++){
        if (INCOMING_BULLETS[i] == 0) {
            INCOMING_BULLETS[i] = position;
            break;
        }
    }
}


/**
 * Update the bullets position (outgoing and incoming bullets) by looping through the arrays
 *
*/
void bullets_update(void) {
    int ship_position = OUTGOING_BULLETS[0];
    for (int i = 1; i < MAX_NUM_BULLETS; i++) {
        if (OUTGOING_BULLETS[i] != 0) { // 0 means not a valid element
            if (OUTGOING_BULLETS[i] % 5  == 1) {
                // send infrared signal
                ir_uart_putc(8-ceil(((float) OUTGOING_BULLETS[i])/5));
                OUTGOING_BULLETS[i] = 0;
            } else {
                OUTGOING_BULLETS[i] -= 1;
            }
        }

        if (INCOMING_BULLETS[i] != 0) { // 0 means not a valid element
            if (INCOMING_BULLETS[i] == ship_position) {
                //send infrared signal (the other player scores 1 point)
                ir_uart_putc(8);
                INCOMING_BULLETS[i] = 0;
            } else if (INCOMING_BULLETS[i] % 5 == 0) {
                INCOMING_BULLETS[i] = 0;
            } else {
                INCOMING_BULLETS[i] += 1;
            }
        }
    }
}


/**
 * Update the battle ship position
 */
void ship_update(void) {
    if (navswitch_release_event_p(NAVSWITCH_NORTH)) {
        if (OUTGOING_BULLETS[0] > 5) {
            OUTGOING_BULLETS[0] -= 5;
            INCOMING_BULLETS[0] -= 5;
        }
    }
    if (navswitch_release_event_p(NAVSWITCH_SOUTH)) {
        if (OUTGOING_BULLETS[0] <= 30) {
            OUTGOING_BULLETS[0] += 5;
            INCOMING_BULLETS[0] += 5;
        }
    }
    if (navswitch_release_event_p(NAVSWITCH_WEST)) {
        if ((OUTGOING_BULLETS[0]) % 5 != 1) {
            OUTGOING_BULLETS[0] -= 1;
            INCOMING_BULLETS[0] -= 1;
        }
    }
    if (navswitch_release_event_p(NAVSWITCH_EAST)) {
        if ((OUTGOING_BULLETS[0]) % 5 != 0) {
            OUTGOING_BULLETS[0] += 1;
            INCOMING_BULLETS[0] += 1;
        }
    }
}


/**
 * Update battle ship position (if the position is changed)
 * Update incoming bullets position
 * Update outgoing bullets position
 */
void components_update(void) {
    bullets_update();
    navswitch_update();
    ship_update();
    button_update();
    led_set(LED1, 0);

}


/**
 * Add new bullets in the outgoing bullets array if navswitch is pushed
 */
void add_outgoing_bullets(void) {
    for (int i=1; i<MAX_NUM_BULLETS; i++) {
        if (OUTGOING_BULLETS[i] == 0) {
            OUTGOING_BULLETS[i] = OUTGOING_BULLETS[0];
            break;
        }
    }
}

/**
 * Clean up outgoing and incoming bullets, set them to 0
 */
void clean_bullets(void) {
    for (int i=1; i<MAX_NUM_BULLETS; i++) {
        OUTGOING_BULLETS[i] = 0;
        INCOMING_BULLETS[i] = 0;
    }
}



