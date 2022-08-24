


/* 

    Solution by Rahul Surana
    
    ***********************************************************


Consecutive elements

You are given a list arr of N numbers, determine the number of ways to replace the missing elements such that the following conditions hold:

The first and the last numbers of the array should be 0.
Adjacent elements have an absolute difference of at most 1.
Numbers can not be negative.
Task

Determine the number of ways to replace the missing elements. The number of ways can be large, so output it modulo .

Notes

1-based indexing is followed.
Missing elements are represented by -1.
Two ways of replacing the missing elements, with A and B being the final states of the array, are considered different if there exists some index i where such that A[i] is different from B[i].
Example

Assumptions

N = 4
arr = [-1, -1, 1, 0]
Approach

The first and last elements should be 0. Hence, you now have [0, -1, 1, 0]
The following possibilities satisfy the required conditions.
[0, 1, 1, 0]
[0, 0, 1, 0]
Hence, the total number of possibilities is 2.

Function description

Complete the consecutiveElements function provided in the editor. This function takes the following 2 parameters and returns the number of possibilities:

N: Represents an integer denoting the length of the list
arr: Represents an array of integers denoting the numbers
Input format

Note: This is the input format that you must use to provide custom input (available above the Compile and Test button).

The first line contains a single integer T denoting the number of test cases. T also specifies the number of times you have to run the consecutiveElements function on a different set of inputs.
For each test case:
The first line contains a single integer denoting the number N.
The second line contains N space-separated integers denoting the given numbers.
Output format

For each test case, print only a single integer in a single representing the line number of possibilities. Since the answer can be too large, output your answer modulo .



    ***********************************************************
*/



// This Question is yet not solved


#include<bits/stdc++.h>
using namespace std;


int consecutiveElements (int N, vector<int> arr) {
   int ans = 0,c=0;
   for(int i = 1; i < N-1; i++){
       if(arr[i] == -1)
       c++;
   }
   return pow(2,c);
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        for(int i_arr = 0; i_arr < N; i_arr++)
        {
            cin >> arr[i_arr];
        }

        int out_;
        out_ = consecutiveElements(N, arr);
        cout << out_;
        cout << "\n";
    }
}