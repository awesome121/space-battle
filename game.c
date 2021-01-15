/**
 * Main source file
 *
 * Auther: Cory Pelham, Changxing Gong
 * Date: 05/10/2020
 *
 */

#include "system.h"
#include "game.h"
#include "components_update.h"
#include "components_display.h"
#include "game_initialise.h"
#include "game_status_check.h"




/**
 * main function:
 * initalise
 * display greet message
 * update
 * display
 * check for special events
 */
int main (void)
{

    while (1) {
        game_init();
        int game_start = 0;

        display_greet_message();

        while (!game_start) {
            pacer_wait();
            tinygl_update();
            game_start = check_game_status();
        }

        while (!GAME_OVER) { // Loops until end game condition met

            if (navswitch_release_event_p(NAVSWITCH_PUSH)) {
                add_outgoing_bullets();
            }

            //display part:
            components_display();

            //update part:

            components_update();

            //check for special event:
            event_check();


        }

        display_result();
        clean_bullets();
    }


}
