

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. 
If it is impossible to form any triangle of a non-zero area, return 0.
 



    ***********************************************************
*/


class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = nums.size()-1, j = 0, k = i-1;
        int m = 0;
        while(i>=2){
            if(nums[i] < (nums[i-1]+nums[i-2])){
                m = max(nums[i] + nums[i-1] + nums[i-2],m);
                break;
            }
            i--;
        }
        
        // 1st solution
        
        // while(i > j && k > j ){
        //     if(nums[i] - nums[j] >= nums[k]){
        //         if(nums[i] - nums[k-1] >= nums[k]) {  i--; k--; }
        //         else{
        //             j++;
        //         }
        //     }
        //     else if( nums[j] + nums[k] <= nums[i]){
        //         // if()
        //         j++;
        //     }
        //     else{
        //         m = max(nums[i] + nums[k] + nums[j],m);
        //         j++;
        //     }
        //     cout << nums[i] << " " << nums[j] << " " << nums[k] << "\n";
        // }
        
        return m;
    }
};