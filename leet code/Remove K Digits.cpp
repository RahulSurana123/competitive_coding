

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given string num representing a non-negative integer num, 
and an integer k, return the smallest possible integer after removing k digits from num.

    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k>= num.length()) return "0";
        if(k ==0) return num;
        stack<char> st;
        for(int i = 0 ; i < num.length(); i++){
            while(k && !st.empty() && num[i] < st.top()){
                k--;
                st.pop();
            }
            st.push(num[i]);
            if(st.size() == 1 && st.top() == '0') st.pop();
        }
        string ans;
        while(k && !st.empty()){
            st.pop();
            k--;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        if(ans.length() == 0) return "0";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};