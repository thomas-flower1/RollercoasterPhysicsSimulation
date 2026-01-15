### Rollercoaster Simulation in C using SDL2

Personal project to further develop my skills and familiarity in C. 

## Functionality
- Allow the user to place a "Rollercoaster" at any point on a library of predefined tracks.

- Allow the user to tweak and edit constants such as acceleration, friction, gravity etc.

- The project uses a basic line following algorithm in combination with rotation about a point and besenham's algorithm to rotate the rollercoaster.


## Issues
- Besenham's Algorithm only works when coordinate 1 < coordinate 2

### Usage

Compile using "make run"