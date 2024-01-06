

/* 
    Solution by Rahul Surana
    
    ***********************************************************


There is an integer array nums that consists of n unique elements, but you have forgotten it. 
However, you do remember every pair of adjacent elements in nums.

You are given a 2D integer array adjacentPairs of size n - 1 
where each adjacentPairs[i] = [ui, vi] indicates that the elements ui and vi are adjacent in nums.

It is guaranteed that every adjacent pair of elements nums[i] and nums[i+1] will exist in adjacentPairs, 
either as [nums[i], nums[i+1]] or [nums[i+1], nums[i]]. The pairs can appear in any order.

Return the original array nums. If there are multiple solutions, return any of them.


    ***********************************************************
*/

class Solution {
public:

    unordered_map<int,vector<int>> idx;

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
       
        for(auto &x: adjacentPairs){
            idx[x[0]].push_back(x[1]);
            idx[x[1]].push_back(x[0]);
        } 
        vector<int> ans;
        int prev = -1;
        for(auto &x: idx){
            if(x.second.size() == 1) { 
                ans.push_back(x.first); 
                ans.push_back(x.second[0]); 
                prev = x.first; 
                break; 
            } 
        } 
       
        while(ans.size() < adjacentPairs.size()+1){
            int t = ans.back();
            if(idx[t][0] != prev){
                ans.push_back(idx[t][0]);  
            }
            else{
                ans.push_back(idx[t][1]);
            } 
            prev = t;
        }
        return ans;
    }
};