
/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. 
It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

A subarray is defined as a contiguous block of elements in the array.



    ***********************************************************
*/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int s = 0;
        for(int i = 0; i< nums.size();i++) { 
            s += nums[i]%p; 
            if(s >= p) s -= p; 
        }
        if(s == 0) return 0;
        // int i = 0, j = n-1;
        int l = nums.size();
        int ss = 0;
        map<int,int> mp;
        mp[0] = -1; 
        for(int i = 0; i < nums.size(); i++){ 
            ss += nums[i]%p;
            ss%=p;
            int tr = (ss-s+p)%p;
            if(mp.find(tr) != mp.end()){
                l = min(l,i-mp[tr]);
            }
            mp[ss] = i;
        }
        return l==nums.size()? -1:l;
    }
};
