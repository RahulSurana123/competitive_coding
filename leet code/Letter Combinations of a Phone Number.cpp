

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    
    map<char,vector<char>> m;
    
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return vector<string>();
        vector<string> ans;
        m.insert({'2',{'a','b','c'}});
        m.insert({'3',{'d','e','f'}});
        m.insert({'4',{'g','h','i'}});
        m.insert({'5',{'j','k','l'}});
        m.insert({'6',{'m','n','o'}});
        m.insert({'7',{'p','q','r','s'}});
        m.insert({'8',{'t','u','v'}});
        m.insert({'9',{'w','x','y','z'}});
        
        for(auto k: m[digits[0]]){
            cout << k <<" ";
            ans.push_back(string(1,k));
        }
        
        for(int i = 1; i < digits.size(); i++){
            vector<string> temp;
            for(auto k: m[digits[i]]){
                for(auto d: ans){
                    temp.push_back(d+k);
                }
            }
            swap(temp,ans);
        }
        return ans;
    }
};