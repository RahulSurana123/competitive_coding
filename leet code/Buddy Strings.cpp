

/* 

    Solution by Rahul Surana
    
    ***********************************************************

Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, 
otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and 
swapping the characters at s[i] and s[j].

For example, swapping at indices 0 and 2 in "abcd" results in "cbad".


    ***********************************************************
*/


class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length()) return false;
        vector<int> f(26,0);
        int c = 0;
        bool same = (s == goal), x = false;
        for(int i = 0; i < s.length(); i++){
            f[s[i]-'a']++;
            if(s[i] != goal[i]) c++;
            if(c>2) return false;
            if(f[s[i]-'a'] >1) x = true;
        }
        if(same && x) return true;
        for(auto z: goal) f[z-'a']--;
        if(c != 2) return false;
        for(auto a: f){
            if(a>0) return false;
        }
        return true;
    }
};