


/* 

    Solution by Rahul Surana
    

    ***********************************************************


Given an array nums of n integers and an integer k, 
determine whether there exist two adjacent subarrays of length k such that both subarrays are strictly increasing. 
Specifically, check if there are two subarrays starting at indices a and b (a < b), where:

Both subarrays nums[a..a + k - 1] and nums[b..b + k - 1] are strictly increasing.
The subarrays must be adjacent, meaning b = a + k.
Return true if it is possible to find two such subarrays, and false otherwise.

        

    ***********************************************************
*/



#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        vector<int> lsd;
        int c = 1;
        for(int i = nums.size()-1; i > 0; i--){
            if(nums[i] > nums[i-1]) {
                c++;
            }
            else{
                lsd.push_back(c);
                c=1;
            }
        }
        lsd.push_back(c);
        if(lsd.size()==1) return true;
        for(int i = 0; i < lsd.size()-1; i++){
            if(lsd[i] >= k && lsd[i+1]>=k || lsd[i] >= k*2 || lsd[i+1]>=k*2) return true;
        }
        return false;
    }
};
