

/* 

    Solution by Rahul Surana
    
    ***********************************************************

Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
 
public:

    int maxVowels(string s, int k) {
        int c = 0, ans = 0, t = k;
        for(int i = 0; i < s.length(); i++){
            c+= is_vowel(s[i]);
            t--;
            if(t<0){ 
                // cout << s[i-k]<<"\n"; 
                c-=is_vowel(s[i-k]); 
            }
            ans = max(c,ans);
        }
        return ans;
    }
    private: 
    inline int is_vowel(const char ch)
    {
        switch (ch) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return 1;
        default:
            return 0;
        }
    }

    static constexpr auto fast_io =  [](){  std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL); };
};