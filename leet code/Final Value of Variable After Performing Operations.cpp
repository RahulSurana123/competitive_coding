


/* 

    Solution by Rahul Surana
    

    ***********************************************************


There is a programming language with only four operations and one variable X:

++X and X++ increments the value of the variable X by 1.
--X and X-- decrements the value of the variable X by 1.
Initially, the value of X is 0.

Given an array of strings operations containing a list of operations, 
return the final value of X after performing all the operations.

        

    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for(auto z: operations){
            if(z == "++X" || z == "X++") x++;
            else x--;
        }
        return x;
    }
};