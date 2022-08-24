

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
Return the maximum number of points you can earn by applying the above operation some number of times.



    ***********************************************************
*/


#include <bits/stdc++.h>


class Solution {
public:
    
    int df(int i, vector<int> &x, map<int,int> &dp,map<int,int> &m){
        if(i >= x.size()) return 0;
        if(dp.find(i) != dp.end()) return dp[i];
        int ans = 0;
        cout << ans <<" "<<x[i]<<" "<< m[x[i]]<<"\n";
        ans = max(ans, (m[x[i]] * x[i]) + ((m.find(x[i]+1) != m.end()) ? df(i+2,x,dp,m):df(i+1,x,dp,m)));
        cout << ans <<" "<<x[i]<<" "<< m[x[i]]<<"\n";
        ans = max(ans,df(i+1,x,dp,m));
        return dp[i] = ans;
    }
    
    int deleteAndEarn(vector<int>& nums) {
        
        // Recursive Implementation
        
        // map<int,int> m;
        // for(auto x: nums) { m[x]++; }
        // vector<int> u;
        // for(auto x: m){
        //     u.push_back(x.first);
        // }
        // sort(u.begin(),u.end());
        // map<int,int> dp;
        // return df(0,u,dp,m);
        
        //
        
        vector<int> f(10001,0);
        int ma;
        for(auto x: nums){
            f[x]++;
            ma = max(ma,x);
        }
        vector<int> dp(10001,0);
        dp[1] = f[1];
        // int a = f[1], b = 0, c = 0;
        for(int i = 2; i <= ma; i++){
            dp[i] = max(dp[i-1], f[i] * i + dp[i-2]);
            // c = max(a , (f[i] * i) + b);
            // b = a;
            // a = c;
        }
        return dp[ma];
    }
};