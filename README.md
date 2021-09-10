Steve and Miles' Painting Placement Algorithm 

Given a wall with a predetermined size and a set of paintings with predetermined size and value, our algorithm utilizes three different methods in an attempt to find the most valuable combination.

Our placement algorithm keeps track of a max X and a max Y and then checks if the next painting fed to the wall can fit past these specifcations. If it cannot,  Max X is reset to 0 and the painting is then checked once again. If the painting still does not fit it is not placed on the wall.

1. Brute Force Algorithm (ONLY VALID WITH 10 OR LESS PAINTINGS): this algorithm calculates the value of every permutation of the painting sets and chooses the most valuable combination. 
2. Expense Algorithm: this algorithm sorts the paintings by value and adds the most expensive paintings first.
3. Custom Algorithm: our custom algorithm sorts the paintings by size and adds the smallest paintings first.

Our program takes a .txt file in the following format,
the first line denotes the width and height of the wall (in that order)
the second line denotes # of paintings 
each line after that specifies the id, value, width, and height of a painting (in that order)
Sample Input:
[input3.txt](https://github.com/smu-cs-3353/21f-pa01-thelads/files/7140246/input3.txt)

Our Program will output every painting placed on the wall. It specifes id, value, width, height, top left x coordinate, and top left y coordinate in that order
It will produce 3 .txt files for the 3 different algorithms labeled yourinputname-bruteforce.txt, yourinputname-highvalue.txt, and yourinputname-custom.txt respectively 
Sample (Custom Algo)Output:
[input3-custom.txt](https://github.com/smu-cs-3353/21f-pa01-thelads/files/7140245/input3-custom.txt)



From the test sets we have ran, we have seen our brute force algorithm is the most sucessful (however it does not work past 10 paintings).
Our custom algorithm seems to be better than the highest value algorithm, but this might be due to the limitations of our placement algorithm.

-Steve and Miles
