/** @file   component_display.h
    @author Cory Pelham Changxing Gong
    @date   11 Oct 2020
    @brief  component display header file

*/
#ifndef COMPONENTS_DISPLAY_H
#define COMPONENTS_DISPLAY_H

#include "system.h"
#include "pio.h"
#include "pacer.h"
#include "navswitch.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "../fonts/font3x5_1.h"
#include "game_initialise.h"
#include "led.h"
#include "button.h"
#include <math.h>




/**
 * display the battle ship
 * display the incoming bullets
 * display the outgoing bullets
 */
void components_display(void);


/** Display a point in terms of postion
 * turn off all the LEDs first before displaying it
 */
void display_point(int position);



/**
 * Display the score earned by this player
 */
void display_result(void);


/**
 * Display the greeting message before game starts
 *
 */
void display_greet_message(void);



#endif
