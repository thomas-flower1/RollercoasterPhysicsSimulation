output_file = main
compile:
	gcc main.c events.c drawing.c render.c update.c game.c -o $(output_file)  `sdl2-config --cflags --libs` -lm

run: compile
	./$(output_file)