

/* 
    Solution by Rahul Surana
    
    ***********************************************************
    
Given two strings ransomNote and magazine, 
return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.
    
    ***********************************************************

*/


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mag;
        unordered_map<char,int> ran;
        for(auto x:ransomNote){
            ran[x]++;
        }
        for(auto x:magazine){
            mag[x]++;
        }
        for(auto z: ran){
            if(ran[z.first]>mag[z.first]) return false;
        }
        return true;
    }
};
