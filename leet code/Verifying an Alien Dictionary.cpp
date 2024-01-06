

/* 
    Solution by Rahul Surana
    
    ***********************************************************


In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. 
The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, 
return true if and only if the given words are sorted lexicographically in this alien language.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> um;
        vector<bool> v(words.size(),false);
        for(int i = 0; i < order.length(); i++) um[order[i]] = i;
        for(int i = 0 ; i < words[0].length(); i++){
            char x = words[0][i];
            for(int j = 1; j <words.size(); j++){
                if(words[j].length()-1 < i && !v[j]) return false;
                if(!v[j] && um[x] > um[words[j][i]]) return false;
                else if(i < words[j].length()){ 
                    if(um[words[j][i]] > um[x]) v[j] = true;
                     x = words[j][i]; 
                }
            }
            bool f = true;
            for(int j = 1; j <words.size(); j++) if(!v[j]) f= false;
            if(f) break;
        }
        return true;
    }
};