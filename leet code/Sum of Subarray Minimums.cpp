

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array of integers arr, find the sum of min(b), 
where b ranges over every (contiguous) subarray of arr. 
Since the answer may be large, return the answer modulo 109 + 7.



    ***********************************************************
*/


#include <bits/stdc++.h>
#define MOD 1000000007

class Solution {
public:
    
    Solution(){
        cout.tie(0),
        cin.tie(0);
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st; 
        int ans = 0;
        st.push(-1);
        for(int i = 0; i <= arr.size(); i++){    
            int cv = i < arr.size()? arr[i]:0;
            while(st.top()!=-1 && cv<arr[st.top()]){
                int a = st.top();
                st.pop();
                int b = st.top();
                long add = ((a-b)* (i-a) * (long)arr[a])%MOD;
                ans = (ans + add) %MOD;
            }
            st.push(i);
        }
        return ans;
    }
};