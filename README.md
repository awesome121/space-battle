# Space Battle
## Introduction
This is a simple game running on UCFUNKIT4 written in C.<br>
Please prepare two Funkits to play the game.<br><br>
Push down the navigation switch to start the game. When the game starts, push down the navigation switch to shoot a bullet at a time.<br>
When your bullets shoot your enemy, you will score one point.<br><br>
Push the button S1 to end the game, which in turn displays the final score of your ship.<br>
Push down the navigation switch to start the game again.<br>
Please try to score as much points as possible!


## Program Structure
There are 4 source files:<br>
game.c  Main source file to run.<br>
game_initialise.c  Initialise all the components required in the game.<br>
components_update.c  Refresh components(update bullets movement, add bullets).<br>
components_display.c  Display greeting message before game starts, Ship, bullets on LEDs and the final score when game ends.<br>
game_status_check.c  Provides status check functions for Space Battle game.<br><br>
and their 4 corresponding header files.<br>


## Ohter Useful Commands
"make program" to make the program</br>
"make clean" to clean all the .hex .o .out files



## Acknowledgement
Author: Cory Pelham, Changxing Gong<br>
Date: 11/10/2020<br><br>
ENCE260<br>
University of Canterbury



