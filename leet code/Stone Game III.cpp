


/* 
    Solution by Rahul Surana
    
    ***********************************************************

Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take 1, 2, or 3 stones from the first remaining stones in the row.

The score of each player is the sum of the values of the stones taken. The score of each player is 0 initially.

The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.

Assume Alice and Bob play optimally.

Return "Alice" if Alice will win, "Bob" if Bob will win, or "Tie" if they will end the game with the same score.

    ***********************************************************
*/


class Solution {
public:

    vector<vector<int>> dp;

    int df(int i,vector<int>& sv, bool isA){
        if(i==sv.size()) return 0;
        if(dp[i][isA] != -1) return dp[i][isA];
        int ans = sv[i] - df(i+1,sv,!isA);
        if(i+1<sv.size()) ans= max(ans, sv[i] + sv[i+1] -df(i+2,sv,!isA));
        if(i+2<sv.size()) ans= max(ans, sv[i] + sv[i+1]+sv[i+2] -df(i+3,sv,!isA));
        return dp[i][isA] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        dp.resize(stoneValue.size(), vector<int>(2,-1));
        int a = df(0,stoneValue,true);
        if(a < 0) return "Bob";
        if(a==0) return "Tie";
        return "Alice";
    }
};
