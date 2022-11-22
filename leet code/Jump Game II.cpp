



/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a 0-indexed array of integers nums of length n. 
You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. 
In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. 
The test cases are generated such that you can reach nums[n - 1].

 

    ***********************************************************
*/



class Solution {
public:
    
    // vector<int> dp;
    
    // top down
    
//     int df(int x, int n, vector<int>& nums){
//         if(n<=x) return 0;
//         if(dp[x] != -1) return dp[x];
//         // cout << x <<" "<<n <<"\n";
//         int ans = 1e9;
//         for(int i = 1; i <= nums[x]; i++){
//             ans = min(ans,df(x+i,n,nums)+1);
//         }
//         return dp[x] = ans;
//     }
    
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        // dp.resize(nums.size()+1,1e9);
        
        // bottom up
        int ans = 0, next = 0,end = 0;
        for(int i = 0; i < nums.size()-1; ++i){
                next = max(next,i+nums[i]);
                if(next >= nums.size()-1){
                    ++ans;
                    break;
                }
                if(end == i){
                    ++ans;
                    end=next;
                }
        }
        
        return ans;
        // return dp[0];
//      return df(0,nums.size()-1,nums);

    }
};