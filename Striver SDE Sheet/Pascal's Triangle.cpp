

/* 

    Solution by Rahul Surana
    

    ***********************************************************


Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


                        1
                    1       1
                1       2       1
            1       3       3       1
        1       4       6       4       1

        

    ***********************************************************
*/



#include <bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0 ; i < numRows; i++){
            vector<int> x(i+1,1);
            for(int j = 1; j <= ceil((i)/2); j++){
                x[j] = x[i-j] = ans[i-1][j-1]+ ans[i-1][j];
            }
            ans.push_back(x);
        }
        return ans;
    }
};  