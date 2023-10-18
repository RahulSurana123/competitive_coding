

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given an integer n, which indicates that there are n courses labeled from 1 to n. 
You are also given a 2D integer array relations where relations[j] = [prevCoursej, nextCoursej] 
denotes that course prevCoursej has to be completed before course nextCoursej (prerequisite relationship). 
Furthermore, you are given a 0-indexed integer array time where time[i] 
denotes how many months it takes to complete the (i+1)th course.

You must find the minimum number of months needed to complete all the courses following these rules:

You may start taking a course at any time if the prerequisites are met.
Any number of courses can be taken at the same time.
Return the minimum number of months needed to complete all the courses.

Note: The test cases are generated such that it is possible to complete every course 
(i.e., the graph is a directed acyclic graph).


    ***********************************************************
    
*/

class Solution {
public:

    vector<int> dp;

    int df(int i,vector<int>&t,vector<vector<int>> &adj){
        
        if(dp[i] != -1) return dp[i];
        if(adj[i].size() == 0) return dp[i] = t[i];
        int ans = 0;
        for(auto z: adj[i]){
                ans = max(ans, df(z,t,adj));
        }
        // cout << i << " " << ans <<"\n"; 
        return dp[i] = t[i] + ans;
    }

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        dp.resize(n,-1);
        for(auto x: relations){
            adj[x[0]-1].push_back(x[1]-1);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans,df(i,time,adj));
        }
        return ans;
    }
};