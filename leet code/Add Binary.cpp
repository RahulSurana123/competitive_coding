

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
        string ans(max(a.length(),b.length())+5,'a');
        int i = a.length()-1, j = b.length()-1, k = max(a.length(),b.length())+4;
        int c = 0;
        while(i>=0 && j >= 0){
            if(a[i] == '1' && b[j] == '1'){
                ans[k] = '0' + c;
                c=1;
            }
            else if(a[i] == '1' && b[j] == '0' || a[i] == '0' && b[j] == '1'){
                ans[k] = (c==0)? '1' : '0';
                // c = (c==1)? 1 : 0;
            }
            else {
                // if(c>1) c = 1;
                ans[k] = '0'+c;
                c = 0;
            }
            k--;
            i--;
            j--;
        }
        if(i>=0){
            while(i>=0){
                if(a[i]=='0') { ans[k] = '0'+c; c = 0; }
                else { ans[k] = ((c == 0) ? '1' : '0'); } 
                k--;
                i--;
            }
        }
        if(j>=0){
            while(j>=0){
                if(b[j]=='0') { ans[k] = '0'+c; c = 0; }
                else { ans[k] = ((c == 0) ? '1' : '0'); } 
                k--;
                j--;
            }
        }
        if(c == 1) ans[k--] = '1';
        int z = 0;
        cout << ans <<" ";
        while(z < max(a.length(),b.length())+5 && ans[z] == 'a') z++;
        return ans.substr(z,max(a.length(),b.length())+5-z);
    }
};