

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given two binary strings a and b, return their sum as a binary string. 



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length()-1,m = b.length()-1;
        string ans(max(n,m)+2,'a');
        int k = max(n,m)+1;
        int c = 0;
        int i;
        while(0 <= n && 0 <= m){
            if(a[n]=='1' && b[m] == '1'){
                ans[k] = c + '0';
                c=1;
            } else if(a[n]=='1' || b[m] == '1'){
                ans[k] = (c^1) + '0';
                // c=c^1;
            }
            else{
                ans[k] = c + '0';
                c = 0;
            }
            // cout << n<<" "<<m<<" "<<ans<<"\n";
            n--;
            m--;
            k--;
        }
        while(n>=0){ if(a[n] == '1') ans[k--] = (c^1)+'0'; else { ans[k--] = c+'0'; c = 0; } n--; }
        while(m>=0){ if(b[m] == '1') ans[k--] = (c^1)+'0'; else { ans[k--] = c+'0'; c = 0; } m--; }
        //   cout << n<<" "<<m<<" "<<c<<" "<<ans<<"\n";
        if(c) { ans[k] = '1';  return ans;}   
        return ans.substr(1);
    }
};