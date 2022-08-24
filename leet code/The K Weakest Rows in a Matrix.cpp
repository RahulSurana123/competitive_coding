

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). 
The soldiers are positioned in front of the civilians. 
That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> w;
        for(int i = 0; i < mat.size(); i++){
            int c = 0;
            while(c < mat[i].size() && mat[i][c] == 1) c++;
            w.push_back({c,i});
        }
        sort(w.begin(),w.end());
        vector<int> ans;
        for(int i = 0 ; i < k; i++) ans.push_back(w[i].second);
        return ans;
    }
};