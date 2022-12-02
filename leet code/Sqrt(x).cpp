

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given a non-negative integer x, return the square root of x rounded down to the nearest integer. 
The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.


    ***********************************************************
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        return floor(sqrt(x));
    }
};