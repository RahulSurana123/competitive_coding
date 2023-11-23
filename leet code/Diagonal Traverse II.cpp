

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a 2D integer array nums, return all elements of nums in diagonal order as shown in the below images.


    ***********************************************************
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<int>> v;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0;j < nums[i].size(); j++){
                v.push_back({i+j,j,i});
            }
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        for(auto x: v){
            ans.push_back(nums[x[2]][x[1]]);
        }
        return ans;
    }
};