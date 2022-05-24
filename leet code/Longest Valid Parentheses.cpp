

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a string containing just the characters '(' and ')', 
find the length of the longest valid (well-formed) parentheses substring.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for(int i = 0 ; i  < s.length(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            else {
                st.pop();
                if(st.empty()) {
                    st.push(i);
                }
                else{
                    ans = max(ans,i-st.top());
                }
            }
            cout << st.top()<< "\n";
        }
        return ans;
    }
};