

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    
    vector<vector<int>> ans;
    
    void df(vector<int> &temp, int i,int n, int k){
        if(i > n) {
            if(temp.size() != k) return;
            ans.push_back(temp);
            return;
        }

        temp.push_back(i);
        df(temp,i+1,n,k);
        temp.pop_back();
        df(temp,i+1,n,k);
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        for(int i = 1; i <= n; i++){
            vector<int> temp;
            temp.push_back(i);
            df(temp,i+1,n,k);
        }
       
        return ans;
    }
};