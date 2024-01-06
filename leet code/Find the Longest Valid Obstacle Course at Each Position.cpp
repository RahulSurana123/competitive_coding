

/* 

    Solution by Rahul Surana
    
    ***********************************************************

You want to build some obstacle courses. 
You are given a 0-indexed integer array obstacles of length n, 
where obstacles[i] describes the height of the ith obstacle.

For every index i between 0 and n - 1 (inclusive), 
find the length of the longest obstacle course in obstacles such that:

You choose any number of obstacles between 0 and i inclusive.
You must include the ith obstacle in the course.
You must put the chosen obstacles in the same order as they appear in obstacles.
Every obstacle (except the first) is taller than or the same height as the obstacle immediately before it.

Return an array ans of length n, 
where ans[i] is the length of the longest obstacle course for index i as described above.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& ob) {
        vector<int> lcs;
        vector<int> ans(ob.size(), 1);
        for(int i = 0; i < ob.size(); i++){
            auto x = std::upper_bound(lcs.begin(),lcs.end(),ob[i]) - lcs.begin();
            if(x == lcs.size()) {
                lcs.push_back(ob[i]);
            }
            else{
                lcs[x] = ob[i];
            }
            ans[i] = x+1;
        }
        return ans;
    }
};