# Yossan's Spreadsheet
This is final project for Programming Algortihm course. Finnaly i have finished this code after spend 10 hours of code.

# Compile
```sh
g++ -std=c++17 -g main.cpp -o main
```

# Command
The command must be capital letter
### Assign a value to a cell
```sh
SET(CELL,VALUE)
```
for example
```sh
SET(A1,5)
```
It will assign 5 to A1 cell

### Delete a value from a cell
```sh
DEL(CELL)
```
For example: 
```sh
DEL(A1)
```
then it will delete value of A1 cell

### Sum rows or column that you want
```sh
SUM(Begin_cell, End_cell)
```
For example
```sh
SUM(A1,A10)
```
then it will give your SUM from A1 until A10
### Look for anywhere in a number
```sh
SEARCH(number)
```
For example:
```sh
SEARCH(5)
```
then it will give you list of cell that contain the 5

### Sorting a data in a row or column with 2 method that is ascending or descending (1 for ascending and 0 for descending)
```sh
SORT(Row/Column,Method)
```
For example:
```sh
SORT(A,1)
```
then it will sorting A ROW with ascending

### Calculate the mean of a row or column
```sh
MEAN(row/column)
```
for example:
```sh
MEAN(E)
```
then it will give you the MEAN result in row E

### Look for minimum value in a row or column
```sh
MIN(row/column)
```
For example 
```sh
MIN(1)
```
then it will give you the minimum number in column 1
### Look for maximum value in a row or column
```sh
MAX(row/column)
```
for example:
```sh
MAX(1)
```
then it will give you the maximum number in column 1
