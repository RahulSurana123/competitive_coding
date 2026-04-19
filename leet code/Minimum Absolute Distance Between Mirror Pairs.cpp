



/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an integer array nums.

A mirror pair is a pair of indices (i, j) such that:

0 <= i < j < nums.length, and
reverse(nums[i]) == nums[j], where reverse(x) denotes the integer formed by reversing the digits of x. 
Leading zeros are omitted after reversing, for example reverse(120) = 21.
Return the minimum absolute distance between the indices of any mirror pair. 
The absolute distance between indices i and j is abs(i - j).

If no mirror pair exists, return -1.


    ***********************************************************
*/

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size(), ans = n;
        unordered_map<int,int> m;
        for(int i = 0;i<n; i++){
            if(m.count(nums[i])){
                ans = min(ans,i-m[nums[i]]);
            } 
            string rev = to_string(nums[i]);
            reverse(rev.begin(),rev.end());
            int v = stoi(rev);
            m[ v ] = i;
        }
        return ans == n?-1:ans;
    }
};