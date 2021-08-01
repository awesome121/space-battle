/** @file   game_initialise.c
    @author Cory Pelham Changxing Gong
    @date   11 Oct 2020
    @brief  initialise the game
*/

#include "game_initialise.h"

/**
 * Initialise all the LED lights: turn off all of them
 *
 */

void LED_init(void) {
    pio_config_set(LEDMAT_ROW1_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW2_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW3_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW4_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW5_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW6_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW7_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_COL1_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_COL2_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_COL3_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_COL4_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_COL5_PIO, PIO_OUTPUT_HIGH);

}


/**
 * Set the battle ship position
 * The battle ship should be in the middle of last column
 *
 */

void set_ship_position(void) {
    OUTGOING_BULLETS[0] = INITIAL_SHIP_POSITION;
    INCOMING_BULLETS[0] = INITIAL_SHIP_POSITION;
}



/**
 * Initialise all the components we need in the game
 *
 */
void game_init(void){
    system_init();
    led_init ();
    button_init();
    navswitch_init();
    ir_uart_init();
    pacer_init(PACER_RATE);
    tinygl_init(PACER_RATE);
    set_ship_position();
    SCORE = 0;
    GAME_OVER = 0;
}










