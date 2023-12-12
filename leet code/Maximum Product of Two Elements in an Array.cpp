

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the array of integers nums, you will choose two different indices i and j of that array. 
Return the maximum value of (nums[i]-1)*(nums[j]-1).


    ***********************************************************
*/

    
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a = 0,b=0, n = nums.size();
        for(int i = 0; i < n; i++) {
            int x = nums[i]-1;
            if(a<=x){
                b = a;
                a = x;
            }
            else{
                b = max(b,x);
            }
        }
        // sort(nums.begin(),nums.end());
        // int a = nums.back()-1;
        // int b = nums[nums.size()-2]-1;
        return a * b;
    }
};