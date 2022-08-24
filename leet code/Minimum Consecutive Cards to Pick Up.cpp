

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an integer array cards where cards[i] represents the value of the ith card. 
A pair of cards are matching if the cards have the same value.

Return the minimum number of consecutive cards you have to pick up to have a pair of 
matching cards among the picked cards. If it is impossible to have matching cards, return -1.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    
    map<int,vector<int>> m;
    
    int minimumCardPickup(vector<int>& cards) {
        for(int i = 0 ; i < cards.size(); i++){
            m[cards[i]].push_back(i);
        }
        int a = 1e9;
        for(auto z: m){
            vector<int> k = z.second;
            for(int i = 1 ; i < k.size(); i++){
                a = min(a,k[i] - k[i-1] + 1);
            }
        }
        return a == 1e9? -1:a;
    }
};