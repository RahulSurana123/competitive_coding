

/* 

    Solution by Rahul Surana
    
    ***********************************************************

Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. 
Return 0 if there is no such subarray.


    ***********************************************************
*/


class Solution {
public:

static constexpr auto fast_io =  [](){  std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL); };

    int longestSubarray(vector<int>& nums) {
        int o1=0,o2=0, ans = 0;
        for(int i = 0; i < nums.size();i++){
            if(nums[i] == 1) o2++;
            else{
                o1 = o2;
                o2 = 0;
            }
            ans = max(ans,o1+o2);
        }
        if(ans == nums.size()) return ans-1;
        return ans;
    }
};