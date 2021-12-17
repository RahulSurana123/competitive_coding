

/* 
    Solution by Rahul Surana
    
    ***********************************************************


We have n chips, where the position of the ith chip is position[i].

We need to move all the chips to the same position. In one step, we can change the position of the ith chip from position[i] to:

position[i] + 2 or position[i] - 2 with cost = 0.
position[i] + 1 or position[i] - 1 with cost = 1.
Return the minimum cost needed to move all the chips to the same position.



    ***********************************************************
*/


#include <bits/stdc++.h>


class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int e = 0, o = 0; 
        for(int i = 0 ; i < position.size(); i++){
            if(position[i]&1) o++;
            else e++;
        }
        return min(e,o);
    }
};