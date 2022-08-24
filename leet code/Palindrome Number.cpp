

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward.

For example, 121 is a palindrome while 123 is not.


    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long z = 1;
        while(z <= x) z*=10;
        z/=10;
        int a = 10;
        while(z>=a){
            // cout << ((x/z)%10) <<" "<< (((x%a)*10)/a) <<"\n";
            if(((x/z)%10) != (((x%a)*10)/a)){ return false;}
            z/=10;
            a*=10;
        }
        return true;
    }
};