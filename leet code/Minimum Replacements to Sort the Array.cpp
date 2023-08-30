

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given a 0-indexed integer array nums. 
In one operation you can replace any element of the array with any two elements that sum to it.

For example, consider nums = [5,6,7]. 
In one operation, we can replace nums[1] with 2 and 4 and convert nums to [5,2,4,7].
Return the minimum number of operations to make an array that is sorted in non-decreasing order.

 
    

    ***********************************************************
*/

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long extra = 0, nn = 0, i = n-1;
        while(i > 0){
            int k = max(1,nums[i-1]/nums[i]);
            while(k*nums[i] < nums[i-1]){
                k++; 
            }
            // cout << i << " "<<nums[i] <<" "<<nums[i-1]<<"\n";
            if(nums[i] < nums[i-1]){
                nums[i-1] = nums[i-1]/k;
                extra+=k-1;
            }
            i--;
        }
        return extra;
    }
};