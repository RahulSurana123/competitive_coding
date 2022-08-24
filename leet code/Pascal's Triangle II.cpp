

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
        vector<int> ans(rowIndex+1,1);
        for(int i = 1; i < rowIndex; i++){
            vector<int> temp(rowIndex+1,1); 
            // for(auto x: ans) cout << x <<" ";
            // cout <<"\n";
            for(int j = 1; j < i+1; j++){
                temp[j] = ans[j-1] + ans[j];
            }
            ans = temp;
        }
        return ans;
    }
};