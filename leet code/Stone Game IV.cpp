
/* 
    Solution by Rahul Surana
    
    ***********************************************************


Alice and Bob take turns playing a game, with Alice starting first.

Initially, there are n stones in a pile. On each player's turn, 
that player makes a move consisting of removing any non-zero square number of stones in the pile.

Also, if a player cannot make a move, he/she loses the game.

Given a positive integer n, return true if and only if Alice wins the game otherwise return false, 
assuming both players play optimally.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    
    vector<bool> dp;
    
    bool df(int n){
        for(int j = 1; j <= n; j++){
            for(int i = 1; i*i <= j; i++){
                if(!dp[j-(i*i)]) { dp[j] = true; break; }
            }
        }
        return dp[n];
    }
    
    bool winnerSquareGame(int n) {
        // if(n == 1 || n ==3 || n == 4) return true;
        // if(n == 2) return false;
        // if(n%5 == 0 || n%5 == 2 || n%5 == 4) return true;
        // if(n%5 == 1 || n%5 == 3) return false;
        dp.resize(n+1,false);
        if(n==0) return false;
        return df(n);
    }
};