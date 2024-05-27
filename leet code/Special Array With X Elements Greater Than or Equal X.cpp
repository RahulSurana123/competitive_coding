

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array nums of non-negative integers. 
nums is considered special if there exists a number x such that 
there are exactly x numbers in nums that are greater than or equal to x.

Notice that x does not have to be an element in nums.

Return x if the array is special, otherwise, return -1. 
It can be proven that if nums is special, the value for x is unique.


    ***********************************************************
*/


class Solution {
public:
    int specialArray(vector<int>& nums) {
        int s = 0, e = 100;
        
        auto x = [&](int m){
            int c = 0;
            for(auto z: nums) if(z>=m) c++;
            return c;
        };

        while(e>=s){
            int m = (s+e) >> 1;
            auto v = x(m);
            if(v == m) return m;
            else if(v > m) s = m+1;
            else e = m-1;
        }
        return -1;
    }
};