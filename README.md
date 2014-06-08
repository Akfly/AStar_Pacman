AStar Pacman
============

This demo is a PacMan done in ASCII with C++. It was a class exercise to learn AStar Path Finding. There are two excersises, the first one is just the world implementation with the Ghosts running randomly along the map, the second is the implementation of the A Star where the ghosts follow the player.

Controls
--------

You can control Pacman with W, A, S and D, any other key just skips a turn so Pacman does not make a move.

Change Map
----------
At the begining of the game you can choose between 2 maps (loaded from a file). You can modify this files (map1.txt and map2.txt) to make different maps.

When you open a map file you can see two numbers at the top of the file. The first number represents the number of rows of the map (map height) and the second is the number of columns (map width). If this numbers are not defined accordingly, then the map will not be loaded correctly. The symbols of the txt files mean:

- n: External walls
- b: Blocks inside the map. The characters are not able to walk through here
- f: Free tile, characters can walk through here.

Executables
-----------
As said before, this demo is composed by two exercises, the first exercise executable is Exec1\PacmanGhost.pdb
The second one is Exec2\PacmanGhost.pdb
