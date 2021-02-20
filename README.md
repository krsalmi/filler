# FILLER - the algorithmic game for two AI players.

The goal of this École42 school project was to code an AI player that would be placed on the "Filler" gameboard and battle its opponent. The Filler board is an x * y map and in the initial starting position each player is given one piece, a single 'x' or 'o' depending on the player order.  
The players take turns placing a randomly generated piece they are given onto the gameboard so that the new piece must touch one single node of the area the player has already claimed for themselves. The player who manages to block the spreading of their opponent and succeeds at conquering the biggest area wins the battle.
<p align="center">
    <img src="/resources/ezgif.com-crop.gif" alt="filler gif" width="363px" height="359px"/>
</p>
## The algorithm

The most important takeaway from this project was the understanding and eventual implementation of the heatmapping technique. In my project, the heatmap is basically a duplicate integer map of the gameboard, where each empty spot is represented as a number. The closer the spot is to the enemy, the smaller its value. This way each piece my player is given is placed as close to the opponent as possible while still placing one point on my player's own area.
This way the algorithm becomes bery aggressive and a strong "FILLER" contender.

## Try it

To compile the program, clone this repository and after typing and entering `make all` in the terminal, start the game with 
```
./resources/filler_vm -p1 ./ksalmi.filler -p2 ./resources/players/ChooseThisYourself.filler -f resources/maps/map01
```
As seen above, the Filler game is found in the "resources" folder, which also includes the provided opponents for the game (in "resources/players/") and the maps of different sizes (in "resources/maps/").
