

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given two integer arrays nums and multipliers of size n and m respectively, where n >= m. The arrays are 1-indexed.

You begin with a score of 0. You want to perform exactly m operations. On the ith operation (1-indexed), you will:

Choose one integer x from either the start or the end of the array nums.
Add multipliers[i] * x to your score.
Remove x from the array nums.
Return the maximum score after performing m operations.
 


    ***********************************************************
*/


class Solution {
public:
    //      ############################################
    //                   Top - down Approach
    //      ############################################
    // vector<vector<int>> dp;
    // int df(int left, int j, vector<int>& nums, vector<int>& m){
    //     if(j==0) { return max(nums[0]*m[0],nums[nums.size()-1]*m[0]); }
    //     if(dp[j] != -1) return dp[j];
    //     int x = m[j];
    //     int right = nums.size()-1-j+left;
    //     return dp[j] = max(df(left+1, j+1, nums, m) + (nums[left]*m[j]),df(left , j+1, nums, m) + 
    //     (nums[right]*m[j]));
    // }
    
    int maximumScore(vector<int>& nums, vector<int>& m) {
        
        // dp.resize(m.size()+1,vector<int>(m.size()+1,0));
        vector<int> dp(m.size()+1,0);
        
        for(int i = m.size()-1; i >= 0; i--){
            
            vector<int> temp(m.size()+1,0);
            for(int j = i; j >= 0; j-- ){
                
                //      ############################
                //           bottom-up approach
                //      #############################
                // int left = i;
                // dp[i][j] = max( m[i]*nums[j] + dp[i+1][j+1], m[i]*nums[right] + dp[i+1][j] );
                // cout << m[i]*nums[j] << " " << m[i]*nums[right] <<"\n";
                
                int right = nums.size()-1-(i-j);
                temp[j] = max(m[i]*nums[j] + dp[j+1],m[i]*nums[right] + dp[j]);
            }
            dp = temp;
        }
        
        return dp[0];
    }
};