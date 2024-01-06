

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif

    ***********************************************************
    
*/


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0; i < numRows; i++){
            vector<int> t(i+1,1);
            for(int j = 1; j <= ceil(i/2);j++){
                t[j] = t[i-j] = ans[i-1][j] + ans[i-1][j-1];
                // cout << t[j] <<" ";
            }
            // cout <<"\n";
            ans.push_back(t);
        }
        return ans;
    }
};