

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.



    ***********************************************************
*/


#include <bits/stdc++.h>


class Solution {
public:

    bool dfs(string s, unordered_set<string> &x){
        for(int i = 1 ;i <= s.length(); i++){
            bool pre = x.count(s.substr(0,i));
            bool suf = x.count(s.substr(i));
            if(pre && suf) return true;
            else if(pre && dfs(s.substr(i),x)) return true;
            else if(suf && dfs(s.substr(0,i),x)) return true;
        } 
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // sort(words.begin(),words.end(),[&](auto a, auto b){ return a.length()<b.length(); });
        vector<string> ans;
        unordered_set<string> x(words.begin(),words.end());
        for(int i = 0; i < words.size(); i++){
            if(dfs(words[i],x)) ans.push_back(words[i]);
        }
        return ans;
    }
};