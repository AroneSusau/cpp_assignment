# Maze Solver Assignment for COSC1076

* [Short Description](##Short-Description)
  * [Milestone 1](###Milestone-1)
  * [Milestone 2](###Milestone-2)
  * [Milestone 3](###Milestone-3)
  * [Milestone 4](###Milestone-4)
* [Describe any issues you encountered](###Describe-any-issues-you-encountered)
* [Justify choices you made in your software design and implementation](###Justify-choices-you-made-in-your-software-design-and-implementation)
* [Project Build](##Project-Build)

## Short Description
For this assignment I tried to seperate most major components into the smallest unit of functionality, or at least within reason, to make testing and troubleshooting the program as easy as possible. You can see this by the many methods I have written for the MazeSolver class. 

### Milestone 1
I have written as many tests I could possiblly think of for both happy and bad paths. As you can see, I've covered failing cases for empty mazes, bad characters and unreachable endings. I believe I have covered almost all cases where the program could possibly go wrong.

### Milestone 2
For implementing the MazeSolver class I tried to keep the same structure that was provided in the sample code, but I found that creating a seperate test and util class was much easier for troubleshooting and testing as it provides the ability to narrow down problems to smaller units of functionality.

MazeSolver still follows the algorithm outlined in the assignment documetation, but I've also provided validation methods to check the quality of the input maze and ensure that it is correct and reliable. It solves the maze by running while loop, adding a breadcrumb and looking for the next available breadcrumb, if a breadcrumb is found it will move to that position or else it will backtrack to its previous position, until the solver reaches the end of the maze.

Unless, the MazeSolver has no more spaces to move, or an error was encountered, where in that case the maze will shortciruit out of the while loop and output an error.

### Milestone 3
This was the easiest milestone as I only had to make a single print directions method in the Util class.

My assumption is that, if the current position of a breadcrumb is say, (2, 4) as (x, y) respectively, and the previous position was (1, 4), that makes a change in position of (x2 - x1, y2 - y1), which in our case would be (2 - 1, 4 - 4) to make a change in direction of (1, 0).

Since the change in direction of our x position is -1, we can safely assume that we have moved in the EAST direction.

Hence we can make a rule that if 
  - delta x = 1, we have moved east.
  - delta x = -1, we have moved west.
  - delta y = 1, we have moved north.
  - delta y = -1, we have moved south.

After writing this I have realised I had actually implemented this the opposite way around, so -1 (x1 - x2) is actually east, but both versions work.

### Milestone 4
Most code did not need to be rewritten for milestone 4, with the exception of the reading in of the maze. 

To read in the maze, I had the maze stored into a string variable as it being read in, also making a count for how long the columns and rows were to be by checking when the newline characters appear ("\n"). Once the maze was read into a string, I then looped through the string to store the values back into the char pointer array, and because I had gathered the row and column sizes when reading in the string, I was able to create enough memory space for the exact size of the maze.

Now, I'm aware that this was probably not the expected approach when solving milestone 4 and that there is most likely some way to have dynamically input each character into the charater array without triggering an out of bounds error. But, due to time limitations, this seemed to be the most viable option that worked, so I stuck with it.

I also decided to use a MazeManager class to handle storing and updating the maze, I found that this method was much easier and cleaner, especially for debugging any issues I had as I was moving the responsibility for the maze itself into the single class.

### Describe any issues you encountered
The primary issues I had with this project was figuring out how to read and store the characters in the arrays, especially for milestone 4. I have described above how I tackled that issue.

One issue I kept coming across was having a value that was actually a nullptr where I thought it would have been initialised or filled as a value. I mostly solved this by ensuring I used if statements for null checks and shortciruiting the program appropriately if erroneous input was discovered. 

### Justify choices you made in your software design and implementation
Two major choices I wanted to discuss was my directory structure and the seperation of responsibilities into seperate classes.

I found that working around multiple files into a single class became rather cumbersome rather quickly, so I ended up decicing that it would be much easier learn how to use the Makefile, and use an src and output file to better organise my code. I've also used a short bash script to run all my tests which was very handy towards the end of my assignment when the code base and number of tests was much larger.

Seperating out my classes into either smaller classes or adding more methods into the classes was much better for troubleshooting where underlying problems were. This is because each methods generally only have a small unit of responsibility and narrows the scope of where issues could arrise.

For instance, if I found that the trail was empty or null, I know for certain that it could only possily have occured during the copying of the array, or adding of the breadcrumbs.

Analyse (briefly) the efficiency and quality of your implementation, identifying both positive and negative
aspects of your software

## Project Build

### How to build

Please enter the following command into your terminal or shell application to build the program.
```
$ make
```

### How to test

Please enter the following command into your terminal or shell application to run all program tests.

Note: Please ensure the program has been compiled prior to running.
```
$ make test
```

### How to run

Please enter the following command into your terminal or shell application to run the program, replacing `INPUT_MAZE` and `OUTPUT_MAZE` with your desired filenames.
```
$ ./MazeSolver < INPUT_MAZE.maze > OUTPUT_MAZE.out
```

## References

- [Makefile Resource](https://www.gnu.org/software/make/manual/html_node/Functions.html)
- [C++ Docs](https://devdocs.io/cpp/)
- [Canvas Material](https://rmit.instructure.com/)