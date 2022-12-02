

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, 
and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    
    
    
    bool closeStrings(string word1, string word2) {
        int f[26],q[26];
        memset(f,0,sizeof(f));
        memset(q,0,sizeof(q));
        set<char> st;
        for(auto x: word1) { f[x-'a']++; st.insert(x); }
        for(auto x: word2) { q[x-'a']++; if(!st.count(x)) return false; }
        sort(f,f+26,[&](auto a,auto b){return a>b;});
        sort(q,q+26,[&](auto a,auto b){return a>b;});
        for(int i = 0; i < 26; i++){
             // cout << f[i] <<" "<< q[i]<<"\n";
            if(f[i] != q[i]) { return false; }
           
        }
        return true;
    }
};