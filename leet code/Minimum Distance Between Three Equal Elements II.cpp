
/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an integer array nums.

A tuple (i, j, k) of 3 distinct indices is good if nums[i] == nums[j] == nums[k].

The distance of a good tuple is abs(i - j) + abs(j - k) + abs(k - i), where abs(x) denotes the absolute value of x.

Return an integer denoting the minimum possible distance of a good tuple. If no good tuples exist, return -1.


    ***********************************************************
*/


class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int,vector<int>> vidx;
        for(int i = 0; i < nums.size(); i++){
            vidx[nums[i]].push_back(i);
        }
        int ans = 1e9;
        for(auto x: vidx){
            if(x.second.size()>2){
                for(int i = 0; i < x.second.size()-2; i++){
                    ans = min(ans,(2*(x.second[i+2]-x.second[i])));
                }
            }
        }
        return ans>10000000?-1:ans;
    }
};
