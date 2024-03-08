

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array nums consisting of positive integers.

Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

The frequency of an element is the number of occurrences of that element in the array.

    ***********************************************************
*/


class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> m;
        int ma = -1;
        for(auto x: nums) {m[x]++; if(ma < m[x]) ma = m[x];}
        int ans = 0;
        for(auto [a,b] : m) if(b == ma) ans+=ma; 
         return ans;
    }
};