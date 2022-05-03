

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given two strings s and t, return true if they are equal when both are typed into empty text editors. 
'#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1,s2;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '#'){
                if(!s1.empty()) s1.pop();
            }
            else{
                s1.push(s[i]);
            }
        }
        for(int i = 0; i < t.length(); i++){
            if(t[i] == '#'){
                if(!s2.empty()) s2.pop();
            }
            else{
                s2.push(t[i]);
            }
        }
        if(s1.size() != s2.size()) return false;
        while(!s1.empty()){
            if(s1.top() != s2.top()) return false;
            s1.pop();
            s2.pop();
        }
        return true;
    }
};