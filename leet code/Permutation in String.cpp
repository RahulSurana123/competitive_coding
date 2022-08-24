

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.


    ***********************************************************
*/


class Solution {
public:
    
    bool checkInclusion(string s1, string s2) {
        if(s2.length() < s1.length()) return false;
        vector<int> f(26,0);
        vector<int> fa(26,0);
        for(int i = 0; i < s1.length(); i++){
            f[s1[i]-'a']++;
            fa[s2[i]-'a']++;
        }
        bool fl = true;
        for(int i = 0; i < 26; i++){
            if(f[i] != fa[i]) fl = false;
        }
        if(fl) return true;
        for(int i = s1.length(); i < s2.length(); i++){
            bool a = true;
            fa[s2[i-s1.length()]-'a']--;
            fa[s2[i]-'a']++;
            for(int j = 0; j < 26; j++){
                if(f[j] != fa[j]) a = false; 
            }
            if(a) return true;
        }
        return false;
    }
};