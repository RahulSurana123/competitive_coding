

/* 

    Solution by Rahul Surana
    
    ***********************************************************


There are n people that are split into some unknown number of groups. 
Each person is labeled with a unique ID from 0 to n - 1.

You are given an integer array groupSizes, where groupSizes[i] is the size of the group that person i is in. 
For example, if groupSizes[1] = 3, then person 1 must be in a group of size 3.

Return a list of groups such that each person i is in a group of size groupSizes[i].

Each person should appear in exactly one group, and every person must be in a group. 
If there are multiple answers, return any of them. 
It is guaranteed that there will be at least one valid solution for the given input.


    ***********************************************************
    
*/


class Solution {
public:

    map<int,vector<int>> mp;

    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        for(int i = 0; i < groupSizes.size(); i++){
            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto x: mp){
            int i = 0;
            vector<int> v;
            for(auto z: x.second){
                v.push_back(z);
                i++;
                if(i == x.first){
                    ans.push_back(v);
                    v.clear();
                    i = 0;
                }
            }
        }
        return ans;
    }
};