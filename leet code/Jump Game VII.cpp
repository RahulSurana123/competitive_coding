

/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are given a 0-indexed binary string s and two integers minJump and maxJump. In the beginning, you are standing at index 0, which is equal to '0'. You can move from index i to index j if the following conditions are fulfilled:

i + minJump <= j <= min(i + maxJump, s.length - 1), and
s[j] == '0'.
Return true if you can reach index s.length - 1 in s, or false otherwise.


    ***********************************************************
*/

class Solution {
public:

    bool canReach(string s, int mi, int ma) {
        if(s.back() == '1') return false;
        int n = s.length();
        vector<bool> dp(s.length()+1,false);
        dp[n-1] = true;
        int mr = n-1;
        for(int i = n-1; i>=0; i--){
            if(!dp[i]) continue;
            for(int j = min(i-mi, mr); j >= i-ma && j>=0; j--){
                if(s[j] == '0') dp[j] = true;
            }
            mr = max(i-ma+1, 0);
        }
        return dp[0];
    }
};
