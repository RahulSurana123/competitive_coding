



/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?



    ***********************************************************
*/




class Solution {
public:
    
    vector<int> dp;
    
    int fact(int n){
        if(n==1 || n==0) return 1;
        return fact(n-1)*n;
    }
    
    int df(int i, int n){
        if(i > n) return 0;
        if(i == n) return 1;
        if(dp[i]!=-1) return dp[i];
        int ans = 0;
        ans += df(i+2,n);
        ans += df(i+1,n);
        return dp[i] = ans;
    }
    
    int climbStairs(int n) {
        // int m = n/2;
        int ans = 0;
        // int e = n%2;
        // for(int i = 0; i <= m; i++){
        //     ans += fact((2*(m-i) + i + e )) / (fact(2*(m-i)+e) * fact(i)); 
        //     // cout << 2*(m-i)+e << " "<< i <<"\n";
        // }
        // return ans;
        dp.resize(n+1,-1);
        return df(0,n);
    }
};