

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. 
The digits are ordered from most significant to least significant in left-to-right order. 
The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        bool f = true;
        for(auto x : digits){
            if(x != 9) f = false;
        }
        if(f){
            vector<int> x(digits.size()+1,0);
            x[0] = 1;
            return x;
        }
        else{
            int x = 1;
            for(int i = digits.size()-1 ;i >= 0; i--){
                digits[i] = digits[i] + x;
                x = digits[i]/10;
                digits[i] = digits[i]%10;
                if(x == 0) break;
            }
            return digits;
        }
    }
};