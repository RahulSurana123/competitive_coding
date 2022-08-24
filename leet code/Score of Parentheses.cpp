

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:

"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    
    int scoreOfParentheses(string s) {
        if(s.length() == 0) return 0;
        int ans = 0;
        stack<int> st;
        st.push(0);
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                st.push(0);
            }
            else{
                int x = st.top();
                st.pop();
                int val = 0;
                if(x > 0){
                    val = x*2;
                }
                else{
                    val = 1; 
                }
                st.top() += val;
            }
        }
        return st.top();
    }
};