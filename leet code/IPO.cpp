

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.

You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.

Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.

The answer is guaranteed to fit in a 32-bit signed integer.


    ***********************************************************
*/


#include <bits/stdc++.h>

#define S second
#define F first
class Solution {
public:
    
    
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        priority_queue<int> q;
        vector<pair<int,int>> s;
        int n = p.size();
        for(int i = 0 ; i < n; i++){
            s.push_back({p[i],c[i]});
        }
        sort(s.begin(),s.end(),[](auto a, auto b){
            return a.S < b.S; 
        });
        int i = 0;
        int ans = 0;
        while(k){
            while(i < n && w >= s[i].S) q.push(s[i++].F); 
            if(!q.empty()){
                w += q.top();
                q.pop();
            }
            k--;
        }
        return w;
    }
};