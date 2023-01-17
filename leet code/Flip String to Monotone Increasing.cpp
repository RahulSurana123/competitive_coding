



/* 
    Solution by Rahul Surana
    
    ***********************************************************


A binary string is monotone increasing if it consists of some number of 0's (possibly none), 
followed by some number of 1's (also possibly none).

You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.

Return the minimum number of flips to make s monotone increasing.
 

    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<int> ps(s.length(),0);
        for(int i = 1; i < s.length();i++){
            ps[i] = ps[i-1] + (s[i-1] == '1');
        }
        int temp = 0;
        int ans  = ps[s.length()-1];
        for(int i = s.length()-2; i >= 0;i--){
            temp += (s[i+1] == '0');
            ans = min(ans,ps[i]+temp);
        }
        return ans;
    }
};