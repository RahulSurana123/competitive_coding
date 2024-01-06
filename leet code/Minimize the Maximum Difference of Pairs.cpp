

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a 0-indexed integer array nums and an integer p. 
Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. 
Also, ensure no index appears more than once amongst the p pairs.

Note that for a pair of elements at the index i and j, 
the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.

Return the minimum maximum difference among all p pairs. 
We define the maximum of an empty set to be zero.


    ***********************************************************
*/

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int s = 0, e = nums.back()-nums.front();
        auto df = [&](int m){
            int v = 0;
            for(int j = 0; j < nums.size()-1; j++){
                if(nums[j+1]-nums[j] <= m){
                    j++;
                    v++;
                }
            }
            return v;
        };
        while(s < e){
            int m = s+(e-s)/2;
            if(df(m) >= p) e = m;
            else s = m + 1;
        }
        return s;
    }
};