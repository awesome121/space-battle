/** @file   game_status_check.h
    @author Cory Pelham Changxing Gong
    @date   11 Oct 2020
    @brief  Header file for game_status_check.c
*/


#ifndef GAME_STATUS_CHECK_H
#define GAME_STATUS_CHECK_H

#include "system.h"
#include "navswitch.h"
#include "game.h"
#include "ir_uart.h"
#include "led.h"
#include "pio.h"
#include "components_update.h"

/**
 *  Return 1 if NAVSWITCH_PUSH
 *  else return 0
 *
 */
int check_game_status(void);



/**
 * Check for infrared signal(bullet signal, target hit signal, end game signal)
 * check for button pushes if S1 button is pushed, the game ends
 */
void event_check(void);

#endif
