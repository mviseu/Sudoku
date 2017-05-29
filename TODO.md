# TO DO 

# OVERALL PLAN
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
	```
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
	```

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

# DAILY PLAN

## DAY 2

### Objective
check if the row at position cursor.row does not have another value that is the same as the one in the cursor position

**Matrix**
Matrix has a function called getElement that returns the element at the cursor position (returns unsigned) 
Matrix has a function getCursorColumn that returns the cursor column (returns unsigned) 
Matrix has a function getRow that returns a vector<unsigned>

**Sudoku**
Sudoku has a private function called searchRow which returns true if a given element(from getElement) is in the row(from getRow) of the cursor, false if not.
The cursor position (given from getCursorColumn) must be ignored (sudoku specific). 
	
