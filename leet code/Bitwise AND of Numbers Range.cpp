

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given two integers left and right that represent the range [left, right], 
return the bitwise AND of all numbers in this range, inclusive.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        int ans = 0;
        for(int i = 31; i >=0 ; i--){
            int x = 1<<i;
            if((left&x) && (right&x)){
                ans += x;
            }
            else if(((left&x) || (right&x))) break;
        }
        return ans;
    }
};