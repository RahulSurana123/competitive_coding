

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array nums containing n distinct numbers in the range [0, n], 
return the only number in the range that is missing from the array.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = 0, n = nums.size();
        for(int i = 0; i < nums.size(); i++){
            x = x^nums[i];
        }
        if(n%4 == 3){
            return x;
        }
        else if(n%4 == 2){
            return x^(n+1);
        }
        else if(n%4 == 1){
            return x^1;
        }
        else{
            return x^n;
        }
    }
};