

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.

A customer's wealth is the amount of money they have in all their bank accounts. 
The richest customer is the customer that has the maximum wealth.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int maximumWealth(vector<vector<int>>& a) {
        vector<int> r(a.size(),0);
        int ans=0;
        for(int i =0; i < a.size();i++){
            for(auto z: a[i]){
                r[i]+=z;
            }
            ans = max(ans,r[i]);
        }
        return ans;       
    }
};