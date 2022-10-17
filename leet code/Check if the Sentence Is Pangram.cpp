

/* 
    Solution by Rahul Surana
    
    ***********************************************************


A pangram is a sentence where every letter of the English alphabet appears at least once.

Given a string sentence containing only lowercase English letters, 
return true if sentence is a pangram, or false otherwise.
 



    ***********************************************************
*/


class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool f[26] = {};
        for(char x: sentence){
            f[x-'a'] = true;
        }
        for(auto x: f){
            if(!x) return false;
        }
        return true;
    }
};