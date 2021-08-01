/** @file   component_update.h
    @author Cory Pelham Changxing Gong
    @date   11 Oct 2020
    @brief  component update header file

*/
#ifndef COMPONENTS_UPDATE_H
#define COMPONENTS_UPDATE_H

#include "system.h"


/**
 * Add new bullets in the incoming bullets array if detect infrared signal
 */
void add_incoming_bullets(int position);




/**
 * Add new bullets in the outgoing bullets array if navswitch is pushed
 */
void add_outgoing_bullets(void);




/**
 * Update the bullets position (outgoing and incoming bullets) by looping through the arrays
 *
*/
void bullets_update(void);



/**
 * Update the battle ship position
 */
void ship_update(void);



/**
 * Update battle ship position (if the position is changed)
 * Update incoming bullets position
 * Update outgoing bullets position
 */
void components_update(void);



/**
 * Clean up outgoing and incoming bullets, set them to 0
 */
void clean_bullets(void);



#endif

