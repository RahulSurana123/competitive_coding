

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. 
Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the smallest possible weight of the left stone. If there are no stones left, return 0.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> x;
        for(auto z: stones) x.push(z);
        while(x.size()>1){
            int a = x.top();
            x.pop();
            int b = x.top();
            x.pop();
            if(a-b > 0) x.push(a-b);
        }
        if(x.size() == 0) return 0;
        else return x.top();
    }
};