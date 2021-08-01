/** @file   game.h
    @author Cory Pelham Changxing Gong
    @date   11 Oct 2020
    @brief  Provides global constants and arrays for Space Battle game

*/
#ifndef GAME_H
#define GAME_H

#include "system.h"

#define MAX_NUM_BULLETS 10 //Maximum bullets in outgoing and incoming bullets
#define PACER_RATE 500
#define TEXT_RATE 10
#define BULLET_SPEED 500 //Bullets moving speed
#define SHOOTING_SPEED 1000 //milliseconds per bullet
#define GAMING_TIME 60 //seconds
#define INITIAL_SHIP_POSITION 20



int GAME_OVER; //GAME_OVER = 0 if game is ongoing GAME_OVER
int SCORE; //Players score (amount of hits on enemy ship)
int OUTGOING_BULLETS[MAX_NUM_BULLETS]; //allocate outgoing bullets array(First element is the ship)
int INCOMING_BULLETS[MAX_NUM_BULLETS]; //allocate incoming bullets array(First element is the ship)



#endif
