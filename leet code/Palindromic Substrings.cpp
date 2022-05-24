

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    int countSubstrings(string s) {
       
        int dp[1002][1002];
        memset(dp,0,sizeof(dp));
        string t = s;
        // reverse(t.begin(),t.end());
        int ans = 0;
        for(int i = s.length()-1; i >= 0; i--){
            for(int j = i; j < t.length(); j++){
               if(i==j){
                    ans++;
                    dp[i][j]=1;
                }
                else  if(s[i]==t[j]){
                    if(abs(j-i) == 1){
                        dp[i][j] = 1;    
                        ans++;
                    }
                    else{
                        ans+= dp[i+1][j-1];
                        if(dp[i+1][j-1]) dp[i][j] = 1;
                    }
                }
                else{
                    dp[i][j] = 0;
                }
                // cout << i << " "<<j <<" "<< ans <<"\n"; 
            }   
        }
        return ans;
    }
};