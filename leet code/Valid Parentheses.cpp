

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    bool isValid(string &s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                if(st.empty())return false;
                char x = st.top();
                st.pop();
                if(x == '(' && s[i] != ')') return false;
                if(x == '{' && s[i] != '}') return false;
                if(x == '[' && s[i] != ']') return false;
            }
        }
        return st.size() == 0? true:false;
    }
};