

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array of digits which is sorted in non-decreasing order. You can write numbers using each digits[i] as many times as we want. For example, if digits = ['1','3','5'], we may write numbers such as '13', '551', and '1351315'.

Return the number of positive integers that can be generated that are less than or equal to a given integer n.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int i = 0,x = n;
        while(x>0){
            i++;
            x/=10;
        }
        long ans =0,j=1;
        while(j<i){
            ans += pow(digits.size(),j);
            // a[j-1] = p; 
            j++;
        }
        // cout << i<<" " << ans <<" ";
        string l = to_string(n);
        for(int k = 0; k < l.length(); k++){
            bool f = false;
            for(auto d: digits){
                if(d[0] < l[k]){
                    ans += pow(digits.size(),l.length()-k-1);
                }
                else if(d[0]==l[k]){
                    f = true;
                }
            }
            if(!f) return ans;
            
        }
        return ans+1;
    }
};