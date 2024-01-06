

/* 
    Solution by Rahul Surana
    
    ***********************************************************


The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. 
In one operation, you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.


    ***********************************************************
*/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int i = 0,j = 1, n = nums.size(), ans = 1;
        long c = 0;
        sort(nums.begin(),nums.end());
        while(j < n){
            if(c <= k){
                if(c + (1L*(j-i) *(nums[j]-nums[j-1])) <= 1L*k){
                    ans = max(ans,j-i+1);
                }
                c += (1L*(j-i) *(nums[j]-nums[j-1]));
                j++;
            }
            else{
                c-= nums[j-1]- nums[i];
                i++;
            }
        }
        return ans;
    }
};