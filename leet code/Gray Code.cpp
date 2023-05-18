

/* 

    Solution by Rahul Surana
    
    ***********************************************************

An n-bit gray code sequence is a sequence of 2n integers where:

Every integer is in the inclusive range [0, 2n - 1],
The first integer is 0,
An integer appears no more than once in the sequence,
The binary representation of every pair of adjacent integers differs by exactly one bit, and
The binary representation of the first and last integers differs by exactly one bit.
Given an integer n, return any valid n-bit gray code sequence.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:

    void df(int i, int n, vector<int> &ans){
        if(i == n+1) return;
        int s = ans.size();
        // cout << s<<" "<<i <<" "<<ans.back()<<"\n";
        for(int j = 0; j < s; j++){
            ans.push_back( (ans[j] | (1<<(i-1)) ));
        } 
        reverse(ans.begin()+s,ans.end());
        
        df(i+1,n, ans);
    }

    vector<int> grayCode(int n) {
        vector<int> ans(1,0);
        df(1,n,ans);
        return ans;
    }
};