






/* 
    Solution by Rahul Surana
    
    ***********************************************************

Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

perm[i] is divisible by i.
i is divisible by perm[i].
Given an integer n, return the number of the beautiful arrangements that you can construct.

    ***********************************************************
*/



class Solution {
public:
    vector<int> dp;
    int countArrangement(int n) {
        // int dp[15];
        dp.resize((1<<(n+1)),-1);
        int count = f(n,0,1);
        return count;
    }
    
    int f(int n, int x, int k){
        if(k > n){
            return 1;
        }
        if(dp[x] != -1) return dp[x];
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(!(x&(1<<(i-1))) && (i % k ==0 || k%i == 0 )){
                int m = x | (1<<(i-1));
                ans += f(n,m,k+1);
            }
        }
        return dp[x] = ans;
    }
    
};