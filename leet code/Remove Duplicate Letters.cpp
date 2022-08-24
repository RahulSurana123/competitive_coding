

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given a string s, remove duplicate letters so that every letter appears once and only once. 
You must make sure your result is the smallest in lexicographical order among all possible results.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    
    string removeDuplicateLetters(string s) {
        vector<bool> v(26,false);
        vector<int> f(26,0);
        for(int i = 0; i < s.length();i++){
            f[s[i]-'a']++;
        }
        string ans = "0";
        for(int i = 0; i < s.length();i++){
            f[s[i]-'a']--;
            if(v[s[i]-'a']) continue;
            while(s[i] < ans.back() && f[ans.back()-'a']){
                v[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans+=s[i];
            v[s[i]-'a'] = true;
        }
        return ans.substr(1);
    }
};