

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a string array words, return the maximum value of length(word[i]) * length(word[j]) 
where the two words do not share common letters. If no such two words exist, return 0.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    
    int maxProduct(vector<string>& words) {
        vector<vector<bool>> wvec(words.size(),vector<bool>(26,false));
        vector<vector<bool>> wwr(words.size(),vector<bool>(words.size(),false));
        for(int i = 0 ; i < words.size(); i++){
            // p[i] = i;
            for(int j = 0; j < words[i].size(); j++){
                wvec[i][words[i][j] - 'a'] = true; 
            }
        }
        int ans = 0;
        for(int i = 0; i < words.size(); i++){
            for(int j = i+1; j < words.size(); j++){
                for(int k = 0; k < 26; k++){
                    if(wvec[i][k] && wvec[j][k]){
                        wwr[i][j] = true;
                        break;
                    }
                }
                if(!wwr[i][j] && ans < words[i].size()*words[j].size()){
                    ans = words[i].size()*words[j].size();
                }
            }
        }
        return ans;
    }
};