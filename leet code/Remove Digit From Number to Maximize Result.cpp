

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a string number representing a positive integer and a character digit.

Return the resulting string after removing exactly one occurrence of digit from 
number such that the value of the resulting string in decimal form is maximized. 
The test cases are generated such that digit occurs at least once in number.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    string removeDigit(string number, char digit) {
        int i = 0,rn = -1;
        while(i < number.size()){
            if(number[i] == digit){
                if(i+1 < number.length() && number[i+1] > digit){
                    rn = i;
                    break;
                }
                rn = i;
            }
            i++;
        }
        string ans;
        ans += number.substr(0,rn);
        ans += number.substr(rn+1);
        return ans;
    }
};