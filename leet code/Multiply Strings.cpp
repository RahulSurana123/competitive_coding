

/* 

    Solution by Rahul Surana

    ***********************************************************

Given two non-negative integers num1 and num2 represented as strings, 
return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.



    ***********************************************************
*/


#include <bits/stdc++.h>
class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.length();
        int m = num2.length();
        string ans(n+m,'0');
        for(int i = n-1; i>=0;i--){
            for(int j = m-1; j >= 0; j--){
                int x = (num1[i]-'0') * (num2[j]-'0');
                x += (ans[i+j+1] - '0');
                // cout << x<<" "<<num1[i]<<" "<<num2[j]<<"\n";
                ans[i+j+1] = (x%10) + '0'; 
                ans[i+j] += ((x/10));
            }
        }
        for(int i = 0; i<n+m;i++){
            if(ans[i] != '0') return ans.substr(i); 
        }
        return "0";
    }
};