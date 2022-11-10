

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given a string s consisting of lowercase English letters. 
A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. 
It can be proven that the answer is unique.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        st.push(s[0]);
        for(int i = 1; i < s.length(); i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                char x = st.top();
                if(x == s[i]){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        string ans = "";
        while(!st.empty()) { ans+=st.top(); st.pop(); }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};