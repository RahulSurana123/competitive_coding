

/* 

    Solution by Rahul Surana
    

    ***********************************************************


Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

        

    ***********************************************************
*/



#include <bits/stdc++.h>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1) return;
        int i = nums.size()-2;
        while(i >=0  && nums[i]>=nums[i+1]) i--;
        if(i < 0){
            sort(nums.begin(),nums.end());
            return;
        }
        int j = nums.size()-1;
        while(nums[i] >= nums[j]) j--;
        cout << i << " "<<j<<"\n";
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        sort(nums.begin()+i+1,nums.end());
        
    }
};