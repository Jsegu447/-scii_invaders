# @scii Invaders
 ## Links and demos
> Full demo: https://youtu.be/Q7RuQu2hal0 (3:45/Complete) https://youtu.be/JQ6FZE83EEo(2:10/ Compressed does not include win screen showcase due to time)
Complexity 1: https://youtu.be/bBm8hvFajPQ Complexity 1 & 2: https://youtu.be/DV7FZrfLBs4 Complexity 1, 2 & 3: https://youtu.be/ucQ1IN8G6h8
## Project Description
  Using 4 buttons, 2 joysticks, 1 atmega1284 and a Nokia 5110 screen, A Space invaders like game named @SCII Invaders was created. 
  The Project uses a Nokia 5110 screen to display the enemy characters and the player characters throughout the game, in addition to displaying the 
  Win/Loss/Pause and main screen. When starting the game up for the first time, the player is prompted to push the Start button, that being the button in 
  the middle of both joysticks. The players are then able to work together to bring down two waves of invaders, attempting to not let any reach the bottom.
  At any time, the players can decide to reset the game with the reset button located at the top of the board or pause the game.
## User Guide:
> ### Rules
>> The Players must work together to survive two rounds of invaders. For the first round, the Invaders will drop down in a staircase manner, with a delay in the spawn of the next
enemy. For the second wave, all enemies will spawn at the exact same time and rush towards the players. 
The player must assure they do not allow no more than 2 invaders to breach the defences, as doing so will doom their city and lose them the game. 
If the players are successful and are able to ward off the invaders, they are rewarded with a win screen. 
The play is not allowed to shoot multiple times in a row, and must either hit a target to be allowed to fire again or wait until their projectile reaches 
the end of the screen. If the invaders reach the player character’s ground level, they will be unable to harm the invader and simply watch as they cross the 
boarder, losing them a life.
> ### Controls
>> The Players have a total of 4 buttons and 2 joysticks that are used for controls. Each joystick controls the movement for one of the characters/player, with A being player 1 and
b being player 2. At any time the player may shoot with the button next to their joystick, 
however they are only allowed one shot, refilling once it reaches the end of the screen or they hit a target. The players are only allowed to move 
left and right to position themselves in front of the enemy and fire. The button between both player controls can be used to pause the game at any time, and 
the button on the top right corner can be used at any time to reset back to the menu screen.

> ### Special Considerations
>> Ideally the game requires two players to be played as it was made to be played, however since either character can destroy all enemy invaders, 
a single player can win the game. The only issue with using a single player is that the game would be considerably more difficult as the 
enemies do move quite quickly for a singular play if their aim is not precise.

## Source Files
> ### Main.c
>> The main file with the whole game. Includes main function in addition to game function which handles running the actual game in multiple states. 
>> In addition includes bitmap arrays created with LCD assistant.
> ### Nokia5110.h
>> header for the Nokia 5110. Include bare bone code used to generate images on the screen, 
>> including a write data, write command, initialize and clear function. Followed LCD lab ideas to implement the Nokia.h functions 
>> in addition to NOKIA 5110 datasheet 
>> and https://www.sparkfun.com/products/10168 product page which include an Arduino example as reference
> ### Timer.h
>> Header file for timer implementation that allows for Synch state machines. Provided by CS120B Lab
> ### simAVRheader
>>  Provided by CS120B Lab

