### Rollercoaster Simulation in C using SDL2

Personal project to further develop my skills and familiarity in C. 

## Functionality
- Allow the user to place a "Rollercoaster" at any point on a library of predefined tracks.

- Allow the user to tweak and edit constants such as acceleration, friction, gravity etc.

- The project uses a basic line following algorithm in combination with rotation about a point and besenham's algorithm to rotate the rollercoaster.


### Usage

Compile using "make run"

## Todo
- add gravity (the ability to 'drop' the rollercoaster at any point)
- implement the line following alg to be bi-directional and vertical movement
- implement the rollercoaster line generation
- combine the line following alg with the rotation alg
- fix besenham's alg implementation so that order does not matter
