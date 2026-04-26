# LeftRightCenter
---------
How to run:
1) Open a terminal in the project directory, either directly in it or by navigating to the project folder.
2) send "make" command
3) send "./lrc" command

If you want to change the seed, open lrc.c and change the seed variable to any integer you want.

---------
General process:

Each player name is stored in an array, with their money stored in a separate array.

All players start with $3, and the pot starts empty.

Important variables and functions are declared:

turn = 0

This determines which player's turn it is.

players = sizeof(names) / sizeof(names[0])

This determines how many players are in the game.

left(position, playerCount)

This returns the position of the player on the current player's left.

right(position, playerCount)

This returns the position of the player on the current player's right.

-----------

After sending ./lrc, main(void) is called. Void is necessary to show that main takes no arguments.

The outcomes of dice rolls are decided through the seed.

### The following actions infinitely loop until the game ends:

  The balance array is checked for all numbers other than 0.
  
  When a number other than 0 is encountered,
    
  the current winner is overwritten with the respective player.
      
  the current winnings are overwritten with their respective balance combined with the pot.
  
  If there is exactly 1 non-zero number,
  
  the game ends with a print to display the winner and the infinite loop is broken.

  ### Otherwise, the game is still running.
  
  The active player is given a rollCount equal to their current balance.
    
  If rollCount is over 3, it is set to 3.
    
  For each roll the active player has,
    
  a random number is generated from 0 to 6.
      
  If it rolled 1,
      
  the active player gives $1 to the player on their left by using left(turn, playerCount).
      
  If it rolled 2,
   
  the active player gives $1 to the player on their right by using right(turn, playerCount).
      
  If it rolled 3,
      
  the active player adds $1 to to the pot.
      
  Otherwise, nothing happens.
    
  ### After the active player has exhausted all their rolls, they pass their turn to the player on their left by using left(turn, playerCount).
      



