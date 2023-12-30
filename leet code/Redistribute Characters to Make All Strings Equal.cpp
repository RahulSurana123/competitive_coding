

/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are given an array of strings words (0-indexed).

In one operation, pick two distinct indices i and j, where words[i] is a non-empty string, 
and move any character from words[i] to any position in words[j].

Return true if you can make every string in words equal using any number of operations, 
and false otherwise.


    ***********************************************************
*/

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int x[26] = {0};
        int n = words.size();
        for(int i = 0; i < n; i++){
            for(auto &b: words[i]) x[b-'a']++;
        }
        for(int i = 0; i < 26;i++){
            if(x[i]%n != 0) return false;
        }
        return true;
    }
};