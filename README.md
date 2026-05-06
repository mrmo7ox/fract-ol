# fract-ol

description: a 2d fractal renderer built in c using the minilibx graphics library for the 1337 curriculum.

## the story
this project was my first real dive into graphical programming and the math behind complex numbers. the idea of zooming infinitely into a mathematical set sounds cool until you realize you have to calculate the escape value for every single pixel on the screen, 60 times a second. i had to figure out how to translate complex plane coordinates into window pixels and optimize the math so the program wouldn't freeze up when zooming in deep.

## the goal
the main objective was to create a program that renders at least the mandelbrot and julia sets. the entry point and argument parsing are handled in `main.c`. i built the core mathematical logic for calculating the fractal sets in `fracles.c`. to actually get things on the screen, i used `mlx_utils.c` to interface with the minilibx library, allowing me to manage the window and push pixels to an image buffer. all the common helper functions are tucked away in `utils.c`, and the whole project is tied together by the `fract_ol.h` header file. 

## the lesson
this was a massive lesson in optimization and event handling. calculating a fractal is computationally heavy, so learning how to write efficient loops and push an entire image buffer to the window instead of drawing pixel-by-pixel saved the frame rate. i also learned how to hook into mouse and keyboard events to implement smooth zooming, panning, and color shifting.

## how to use
to run the fractal explorer, use the `Makefile` by typing `make` in your terminal. this will compile the project. then, run the executable and pass the fractal name as an argument. for example, run `./fractol mandelbrot` to see the classic set, or `./fractol julia <real> <imaginary>` to explore different julia variations based on the coordinates you feed it.
