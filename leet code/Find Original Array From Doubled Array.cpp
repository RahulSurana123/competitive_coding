

/* 
    Solution by Rahul Surana
    
    ***********************************************************


An integer array original is transformed into a doubled array changed by appending twice the value of every element in original, and then randomly shuffling the resulting array.

Given an array changed, return original if changed is a doubled array. If changed is not a doubled array, return an empty array. The elements in original may be returned in any order.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    map<int,int> m;
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2==1) return vector<int>();
        vector<int> ans;
        sort(changed.begin(),changed.end());
        for(int i = 0 ; i < changed.size();i++){
            if(changed[i]&1){
                ans.push_back(changed[i]);
                m[changed[i]*2] -=1;
            }
            else{
                if(m[changed[i]] >= 0){
                    ans.push_back(changed[i]);
                    m[changed[i]*2] -=1;
                }
                else{
                     m[changed[i]] +=1;
                }
            }
        }
        if(ans.size() != changed.size()/2) return vector<int>();
        return ans;
    }
};