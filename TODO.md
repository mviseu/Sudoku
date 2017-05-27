# TO DO 

## Classes
### Matrix
* Data members
	* vector of vector of ints
	* cursor location
* Functions
	* select cell -> change "cursor" location
		* must contain an exception if selected cursor is on starting sudoku location
	* change cell -> based on cursor location

### Sudoku
* print grid with numbers
	*replace 0's with spaces
	*have clear dividers between regions 

	X X X | X X X | X X X
	X X X | X X X | X X X
	X X X | X X X | X X X
	- - - + - - - + - - -
	X X X | X X X | X X X
	X X X | X X X | X X X
	X X X | X X X | X X X
	- - - + - - - + - - -
	X X X | X X X | X X X
	X X X | X X X | X X X
	X X X | X X X | X X X

* check rows 
* check columns
* check regions

Note: check functions check only the particular row/column/region the user has selected


## Dumb proof/error handling
* Throw/catch clause if input value of cell is not int
* Check that the user selects a "changeable" location for the cursor


## Start
* With an initial known grid (in-class initializer?)
* http://elmo.sbs.arizona.edu/sandiway/sudoku/examples.html for resources


## Notes 
How to provide visual feedback for selected cells?
* select a row, column
* check if it is the intended cursor position (with X?)
* user will answer y-n
* then change value