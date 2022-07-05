# CS202A Assignment-1

## Sudoku Solver

Given a sudoku puzzle pair S1, S2 (both of dimension k) as input,this is a program to fill the empty cells of both sudokus such that it satisfies the following constraints,

-> Individual sudoku properties should hold.

-> For each empty cell S1[i, j] ≠ S2[i, j], where i is row and j is column.

### How to run

Before running the script, make sure that python and python-sat is installed in the system and file containing the input namely ‘input.csv’ is in the same folder as of the script.

This csv file consists of values in dimensions (2k^2) * (k^2).

Use the command ``` python3 solver.py ``` to run the script.

Upon running the file, a message ``` Enter the value of k : ``` will appear and we need to give the input parameter k. 

If the sudoku-pair is solvable, Solved sudoku will be printed otherwise None will be printed.

NOTE - The value of k should be in accordance with the dimensions of sudoku in the csv file, otherwise the code may not run.







