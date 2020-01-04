# FibbonacciFractals
This C program takes a user input number and creates the fibbonacci fractal to match and stores it in a bmp file.

To run the program, execute the fib excecutable with parameters of your choice, for example: ./fib 9 10 10 10 400 400 fib9.bmp
Running this would output the bmp file that has been included in this repository.

Standard Usage: ./fib n x y step width height filename

To run this program the fib script has been included as well as a makefile. When make runall is entered the makefile currently makes a fib sequence for n = 7, 9, 25, 26 and 30.

Input Legend:
  -n: how many fibbonacci words are concatenated to 
  -x: first x coordinate to begin drawing
  -y: first y coordinate to begin drawing
  -step: length value in pixels for each line drawn
  -width: width of output file in pixels
  -height: height of output file in pixels
  -filename: name of file to hold final drawing
