/** @file   game_initialise.h
    @author Cory Pelham Changxing Gong
    @date   11 Oct 2020
    @brief  Provides initialisation functions for Space battle game

*/

#ifndef GAME_INITIALISE_H
#define GAME_INITIALISE_H

#include "system.h"
#include "game.h"
#include "led.h"
#include "pio.h"
#include "pacer.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "../fonts/font3x5_1.h"
#include "led.h"
#include "button.h"


/**
 * Initialise all the LED lights: turn off all of them
 *
 */
void LED_init(void);


/**
 * Set the battle ship position
 * The battle ship should be in the middle of last column
 *
 */

void set_ship_position(void);




/**
 * Initialise all the components we need in the game
 *
 */
void game_init(void);

#endif


