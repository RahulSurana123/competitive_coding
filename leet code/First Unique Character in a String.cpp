

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.


    ***********************************************************
*/


class Solution {
public:
    int firstUniqChar(string s) {
        int f[26] = {0}, n = s.length();
        for(auto &x: s){
            f[x-'a']++;
        }
        for(int i = 0; i < n; i++){
            if(f[s[i]-'a'] == 1) return i;
        }
        return -1;
    }
};