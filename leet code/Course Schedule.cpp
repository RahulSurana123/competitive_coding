

/* 

    Solution by Rahul Surana
    
    ***********************************************************

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that 
you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.


    ***********************************************************
*/


class Solution {
public:
    vector<int> v;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        v.resize(numCourses,0);
        int c = 0;
        for(auto x: prerequisites){
            v[x[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(v[i]==0) { q.push(i); c++; }
        }
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            for(int i = 0;i < prerequisites.size(); i++){
                if(prerequisites[i][1] == x){
                    v[prerequisites[i][0]]--;
                    if(v[prerequisites[i][0]] == 0) { q.push(prerequisites[i][0]); c++; }
                }
            }
        }
        return (numCourses == c);
    }
};