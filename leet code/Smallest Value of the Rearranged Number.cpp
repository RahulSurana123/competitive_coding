

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an integer num. Rearrange the digits of num such that its value is minimized and it does not contain any leading zeros.

Return the rearranged number with minimal value.

Note that the sign of the number does not change after rearranging the digits.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    long long smallestNumber(long long num) {
        bool f= false;
        if(num<0) { f = true; num*=-1; }
        string ans = "";
        while(num>0){
            // cout << num%10 <<" ";
            ans += (num%10)+'0';
            num/=10;
            
        }
        if(f) sort(ans.begin(),ans.end(),greater<char>());
        else sort(ans.begin(),ans.end());
        
        long long a = 0;
        int i = 0;
        while(i<ans.length() && ans[i] == '0') i++;
        int z = i;
        if(z>0) { 
            a += ans[i++] -'0';
            // cout << a <<" ";
            for(int k = 0; k < z; k++) { 
                 a*=10; 
            }  
        }
        // cout << a <<" ";
        while(i<ans.length()) { a*=10; a+=ans[i++]-'0'; }
        if(f) return -a;
        return a;
    }
};