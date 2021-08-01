/** @file   component_display.c
    @author Cory Pelham Changxing Gong
    @date   11 Oct 2020
    @brief  Provides display functions for Space Battle game

*/

#include "components_display.h"



/**
 * display the battle ship
 * display the incoming bullets
 * display the outgoing bullets
 */
void components_display(void) {
    for (int i = 1; i<MAX_NUM_BULLETS; i++) {
        display_point(OUTGOING_BULLETS[i]);
        pacer_wait();
        display_point(OUTGOING_BULLETS[0]);
        pacer_wait();
        display_point(INCOMING_BULLETS[i]);
        pacer_wait();
    }
}



/** Display a point in terms of postion
 * turn off all the LEDs first before displaying it
 */
void display_point(int position) {
    float point = 0;
    point = position;
    LED_init();
    if (ceil(point/5) == 1) {
        pio_output_low(LEDMAT_ROW1_PIO);
        if ((position % 5) == 1) {
            pio_output_low(LEDMAT_COL1_PIO);
        } else if ((position % 5) == 2){
            pio_output_low(LEDMAT_COL2_PIO);
        } else if ((position % 5) == 3) {
            pio_output_low(LEDMAT_COL3_PIO);
        } else if ((position % 5) == 4){
            pio_output_low(LEDMAT_COL4_PIO);
        } else if ((position % 5) == 0){
            pio_output_low(LEDMAT_COL5_PIO);
        }
    } else if (ceil(point/5) == 2) {
        pio_output_low(LEDMAT_ROW2_PIO);
        if ((position % 5) == 1) {
            pio_output_low(LEDMAT_COL1_PIO);
        } else if ((position % 5) == 2){
            pio_output_low(LEDMAT_COL2_PIO);
        } else if ((position % 5) == 3) {
            pio_output_low(LEDMAT_COL3_PIO);
        } else if ((position % 5) == 4){
            pio_output_low(LEDMAT_COL4_PIO);
        } else if ((position % 5) == 0){
            pio_output_low(LEDMAT_COL5_PIO);
        }
    } else if (ceil(point/5) == 3) {
        pio_output_low(LEDMAT_ROW3_PIO);
        if ((position % 5) == 1) {
            pio_output_low(LEDMAT_COL1_PIO);
        } else if ((position % 5) == 2){
            pio_output_low(LEDMAT_COL2_PIO);
        } else if ((position % 5) == 3) {
            pio_output_low(LEDMAT_COL3_PIO);
        } else if ((position % 5) == 4){
            pio_output_low(LEDMAT_COL4_PIO);
        } else if ((position % 5) == 0){
            pio_output_low(LEDMAT_COL5_PIO);
        }
    } else if (ceil(point/5) == 4) {
        pio_output_low(LEDMAT_ROW4_PIO);
        if ((position % 5) == 1) {
            pio_output_low(LEDMAT_COL1_PIO);
        } else if ((position % 5) == 2){
            pio_output_low(LEDMAT_COL2_PIO);
        } else if ((position % 5) == 3) {
            pio_output_low(LEDMAT_COL3_PIO);
        } else if ((position % 5) == 4){
            pio_output_low(LEDMAT_COL4_PIO);
        } else if ((position % 5) == 0){
            pio_output_low(LEDMAT_COL5_PIO);
        }
    } else if (ceil(point/5) == 5) {
        pio_output_low(LEDMAT_ROW5_PIO);
        if ((position % 5) == 1) {
            pio_output_low(LEDMAT_COL1_PIO);
        } else if ((position % 5) == 2){
            pio_output_low(LEDMAT_COL2_PIO);
        } else if ((position % 5) == 3) {
            pio_output_low(LEDMAT_COL3_PIO);
        } else if ((position % 5) == 4){
            pio_output_low(LEDMAT_COL4_PIO);
        } else if ((position % 5) == 0){
            pio_output_low(LEDMAT_COL5_PIO);
        }
    } else if (ceil(point/5) == 6) {
        pio_output_low(LEDMAT_ROW6_PIO);
        if ((position % 5) == 1) {
            pio_output_low(LEDMAT_COL1_PIO);
        } else if ((position % 5) == 2){
            pio_output_low(LEDMAT_COL2_PIO);
        } else if ((position % 5) == 3) {
            pio_output_low(LEDMAT_COL3_PIO);
        } else if ((position % 5) == 4){
            pio_output_low(LEDMAT_COL4_PIO);
        } else if ((position % 5) == 0){
            pio_output_low(LEDMAT_COL5_PIO);
        }
    } else if (ceil(point/5) == 7) {
        pio_output_low(LEDMAT_ROW7_PIO);
        if ((position % 5) == 1) {
            pio_output_low(LEDMAT_COL1_PIO);
        } else if ((position % 5) == 2){
            pio_output_low(LEDMAT_COL2_PIO);
        } else if ((position % 5) == 3) {
            pio_output_low(LEDMAT_COL3_PIO);
        } else if ((position % 5) == 4){
            pio_output_low(LEDMAT_COL4_PIO);
        } else if ((position % 5) == 0){
            pio_output_low(LEDMAT_COL5_PIO);
        }
    }

}


/**
 * Display the score earned by this player
 */
void display_result(void) {
    char str[3];
    str[0] = ((SCORE / 10) % 10) + '0';
    str[1] = (SCORE % 10) + '0';
    str[2] = 0;
    tinygl_clear();
    tinygl_init (100);
    tinygl_font_set (&font3x5_1);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_STEP);
    tinygl_text_dir_set (TINYGL_TEXT_DIR_ROTATE);
    tinygl_text(str);
    while (!navswitch_release_event_p(NAVSWITCH_PUSH)){
        pacer_wait ();
        navswitch_update();
        tinygl_update ();
    }
}


/**
 * Display the greeting message before game starts
 *
 */
void display_greet_message(void) {
    tinygl_font_set(&font3x5_1);
    tinygl_text_speed_set(TEXT_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    tinygl_text_dir_set (TINYGL_TEXT_DIR_ROTATE);
    tinygl_text("SPACE BATTLE! PUSH TO START!\0");
}


