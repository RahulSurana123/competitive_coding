

/* 

    Solution by Rahul Surana

    ***********************************************************


Best houses

Alice and Bob are best friends. They are planning to buy one house for each of them. 

The available houses for sale are located on land which is divided into NxN plots. The houses are numbered 1 to N from top to bottom and 1 to N from left to right. The coordinates of each house can be represented as (i, j), which denotes the ith house from the top and jth house from the left.

Of course, each house is not equally good. You are also given an NxN matrix G and G[i][j] denotes the goodness value of the house at (i, j). 

Alice and Bob both want good houses but they also don't want to be too far from each other.

Let's define a happiness function,  H = G(a,b) + G(c,d) - abs(d-b) - abs(c - a)

Now Bob and Alice wonder, what is the maximum value of the function H that they can get if they consider every pair of coordinates  and  such that .

Task

Print the maximum possible value of H if you consider all pairs of houses.

Example

Assumptions 

N = 3
G[][] = { { 1, 2, 3 }, 
             { 2, 3, 6 },
             { 9, 5, 2 } }
Approach 

The maximum happiness value is obtained by considering houses at (3, 1) and (2, 3).
The value is 9 + 6 - |3-2| - |1-3| = 15 - 1 - 2 = 12.

Function description

Complete the solve function provided in the editor. The function takes the following 2 parameters and returns the final value as described in the problem statement:

N: Represents an integer denoting the size of the matrix
G: Represents a two-dimensional array of order NxN containing the goodness value for all houses
Input format 

Note: This is the input format that you must use to provide custom input (available above the Compile and Test button).

The first line contains an integer T denoting the number of test cases. T also denotes the number of times you have to run the solve function on a different set of inputs.
For each test case:
The first line contains one integer N.
N lines follow, each line contains N space-separated integers denoting the goodness values.
Output format

For each test case in a new line, print the maximum possible value of H.

Constraints

1 < T < 10^3
2 < N < 500
1 < G(i,j) < 10^9



      ***********************************************************
*/



