/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an integer array of unique positive integers nums. Consider the following graph:

There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.
Return the size of the largest connected component in the graph.


    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    
    vector<int> p;
    
    int find(int z){
        if(p[z] != z) p[z] = find(p[z]);
        return p[z];
    }
    void un(int x, int y){
        p[find(x)] = p[find(y)];
    }
    
    int largestComponentSize(vector<int>& nums) {
        // p.resize(nums.size()+1,0);
        int m = *max_element(nums.begin(),nums.end());
        p.resize(m+1,0);
        for(int i = 0; i <= m; i++) p[i] = i;
        for(int i : nums){
            for(int j = 2; j <= sqrt(i); j++){
                if(i%j == 0){
                    un(i,i/j);
                    un(i,j);
                }
                // cout << nums[i] <<" "<< find(nums[i]) <<"\n";
            }   
        }
        int ans = 0;
        unordered_map<int,int> c;
        for(int i : nums){
            ans = max(ans,++c[find(i)]);
        }
        return ans;
    }
};