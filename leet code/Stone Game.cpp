

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.

Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<pair<int,int>>> dp;
    
    pair<int,int> pics(vector<int> &p,int l, int r){
        if(l>r) return {0,0};
        if(dp[l][r] != make_pair(-1,-1)) return dp[l][r];
        auto left = pics(p,l+1,r);
        auto right = pics(p,l,r-1);
        if(p[l]+left.second > p[r] + right.second){
            return dp[l][r] = { p[l]+left.second, left.first};
        }
        return dp[l][r] = {p[r]+right.second,right.first};
    }
    
    bool stoneGame(vector<int>& piles) {
        dp.resize(piles.size(),vector<pair<int,int>>(piles.size(),{-1,-1}));
        auto x = pics(piles,0,piles.size()-1);
        return x.first > x.second;
        // return true;
    }
};