

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer n, return an array ans of length n + 1 such that 
for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.



    ***********************************************************
*/


#include <bits/stdc++.h>


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++){
            int temp = i;
            int c = 0;
            while(temp>0){
                if(temp%2 == 1)c++;
                temp = temp>>1;
            }
            ans.push_back(c);
        }
        return ans;
    }
};