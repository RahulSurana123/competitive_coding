

/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are given a 0-indexed array nums consisting of positive integers.

There are two types of operations that you can apply on the array any number of times:

Choose two elements with equal values and delete them from the array.
Choose three elements with equal values and delete them from the array.
Return the minimum number of operations required to make the array empty, or -1 if it is not possible.


    ***********************************************************
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto &x: nums) m[x]++;
        int ans = 0;
        for(auto x: m){
            int z = x.second;
            if(z==1) return -1;
            else if(z%3==0) ans+=z/3;
            else ans += (z+3)/3;
        }
        return ans;
    }
};