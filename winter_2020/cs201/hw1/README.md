## CS 201 HW 1 &#8594; Plinko
#### Michael Chang

This is a program that would run **Monte Carlo** for Plinko
And print out the result table at the end

The program is divide into three main section
1. Read in the board
2. Run test repeatedly and record all result
3. Print out the result table
***

**Read in the board**
* Use argc to check if there is a file name
* Use argv to open the board file
* Read in the **row** and **column**
* Allocate memory for the board and input how the board looks like at the same time
* Print out our board for confirmation
* Close our board file

**Run test repeatedly and record all result**
* Use `repeat` to control how many repeats we want to test
* Use `GetRandom` to generate a start for us to begin
* Go through each row of the board
```
if encounter 0
	go to next row
else
	Randomly choose left or right
	if able to go said left or right
		change current
	else
		change current the other way
```
* Record the result to the table
* I have implemented code for when testing you could print out the path the ball went through, but remember to change the `repeat = 1` for it to work
```
Board:
X00000X
X0X0X0X
X00000X
XX0X0XX
X00000X
X0X0X0X
X00000X

Board:
X000I0X
X0X0XIX
X0000IX
XX0XIXX
X000I0X
X0X0XIX
X0000IX
```

**Print out the result table**
 * Use a for loop to print out the result for each slot
