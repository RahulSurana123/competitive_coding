

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

                1
            1       1
        1       2       1
    1       3       3       1


    ***********************************************************
    
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pt(rowIndex+1,1);
        long n = rowIndex;
        for(int i = 1; i < rowIndex; i++){
            pt[i] = ((pt[i-1]*n)/i);
            n--;
        }
        return pt;
    }
};