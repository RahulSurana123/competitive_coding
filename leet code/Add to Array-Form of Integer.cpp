

/* 
    Solution by Rahul Surana
    
    ***********************************************************


The array-form of an integer num is an array representing its digits in left to right order.

For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size()-1;
        int m = ceil(log10(k));
        int i,c = 0;
        vector<int> ans;
      
        for(i =  max(n,m); i >= 0 && n>=0; i--){
            ans.push_back(num[n--]+(k%10)+c);
            if(ans.back() >= 10) c = 1; 
            else c = 0;
            k/=10;
            ans.back() %= 10;
        }
        while(k>0) { 
            ans.push_back((k%10) + c); 
            k/=10; 
            if(ans.back() >= 10) c = 1; 
            else c = 0;  
            ans.back() %= 10;
        }
        if(c > 0) ans.push_back(c);
        reverse(ans.begin(),ans.end());
        return vector<int>(ans.begin(),ans.end());
    }
};