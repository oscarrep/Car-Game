# Synthcar

> Synthcar is a car game created by two university students, Oscar Reguera and Jan Adell, utilizing the Bullet 3D libraries. The game consists in a local 2 player game in which you drive a car down a ramp in order to land on a target. Each player has 3 turns,a dn the player with more points in the end wins. 

 * **Oscar Reguera:**
 > https://github.com/oscarrep
 
 * **Jan Adell:**
 > https://github.com/JanAdell

## How to play
 * **Top Arrow Key:** Accelerate forward
 * **Left Arrow Key:** Steer left
 * **Right Arrow Key:** Steer right
 * **Down Arrow Key:** Accelerate backwards
 * **Spacebar:** Brake
 * **R Key:** Restart the game from 0
 * **ESC Key:** Quit the game
 
In Synthcar you target to fall with your car into a square target formed by 5 horizontal lines. Each line has a different color, and each gives a certain amount of points:

  * Red Line: 3 points
  * Blue Line: 2 points
  * Green Line: 1 point
  * Yellow Line: 2 points
  * Black Line: 3 Points
  
  The lines value is defined by how hard it is to land on them. Green is the easiest, in most cases at good speed you'll fall there. Blue and Green are quite easy as well but need slightly reduced or inclreased speed compared to a jump for Green. Red and Black are the hardest, being in the edges of the target. Red requires the minimal speed to get to the target, but enough not to hit the ground. Black requires maximum speed to fall on the target, but not enough to fly by it. Furthermore, hitting the ground substracts one point and ends the player's turn. 
  
  Turns are programmed to be alternated between players. The score from turn 1, 3 and 4 will go to Player 1 and the one from turns 2,  and 6 to Player 2. Furthermore all UI is implemented in the window title, so information may be scarce. However, we left the car speed because it was fun during testing seeing how fast it could go.
  
## Warnings and Possibly Found Errors

Since this is our first experience programming a 3D game from scratch there are some issues to which we could not find solution with our limited time, however these are hard to come by or not that common. The two most important to mention are probably the fact that if the car overturns in the ramp the game has to be restarted because there is no way implemented to place it properly, and an error in which the car's front part gets stuck inbetween ramp tiles making it fling. We also reccomend driving carefully since tight turns make the car flip as well. 

## Assets Used

  **Music and SFX**
  * *Glass Break Sound* by stephan schutze 
  > http://soundbible.com/1765-Glass-Break.html
  
  * *Nihilore* by James Opie
  > https://nihilore.itch.io/nihilore-collection-2
  
  ## Project Repository
  
  **Find our project repository here:**
  >https://github.com/oscarrep/Car-Game
  
  
  
  
  
