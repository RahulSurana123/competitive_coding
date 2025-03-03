
/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:

Every element less than pivot appears before every element greater than pivot.
Every element equal to pivot appears in between the elements less than and greater than pivot.
The relative order of the elements less than pivot and the elements greater than pivot is maintained.
More formally, consider every pi, pj where pi is the new position of the ith element and pj is the new position of the jth element. 
If i < j and both elements are smaller (or larger) than pivot, then pi < pj.

Return nums after the rearrangement.



    ***********************************************************
*/

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> s,b;
        int c = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < pivot) s.push_back(nums[i]);
            else if(nums[i] == pivot) c++;
            else b.push_back(nums[i]);
        }
        vector<int> r(s);
        while(c--) r.push_back(pivot);
        for(auto x: b) r.push_back(x);
        return r;
    }
};
