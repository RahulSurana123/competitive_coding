

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given two integer arrays pushed and popped each with distinct values, return true if this could 
have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& poped) {
        stack<int> st;
        int i = 0,j=0;
        while(i < pushed.size()){
            if(st.empty()){
                st.push(pushed[i++]);
            }
            if(poped[j] == st.top()){
                st.pop();
                j++;
            }
            else{
                if(i < pushed.size()) st.push(pushed[i]);
                i++;
            }
        }
        while(!st.empty() && st.top() == poped[j]) { st.pop(); j++; }
        return st.empty();
    }
};