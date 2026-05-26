

/* 
    Solution by Rahul Surana
    
    ***********************************************************

Given an array of integers arr and an integer d. In one step you can jump from index i to index:

i + x where: i + x < arr.length and  0 < x <= d.
i - x where: i - x >= 0 and  0 < x <= d.
In addition, you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] for all indices k between i and j (More formally min(i, j) < k < max(i, j)).

You can choose any index of the array and start jumping. Return the maximum number of indices you can visit.

Notice that you can not jump outside of the array at any time.


    ***********************************************************
*/

class Solution {
public:

    int df(int i,vector<int>& arr, int d, vector<int>& dp, int n){
        if(i < 0 || i >= n) return 0;
        if(dp[i] != 0) return dp[i];
        // cout << i <<" -> "<<"\n";
        int ans = 1;
        int a = 1;
        while(i+a < n && a <= d && arr[i] > arr[i+a]) { ans = max(ans,1 + df(i+a,arr,d,dp,n)); a++; } 
        a = 1;
        while(i-a >= 0 && a <= d && arr[i] > arr[i-a]) { ans = max(ans,1 + df(i-a,arr,d,dp,n)); a++; }
        // cout << i <<" "<< ans<<" <-\n";
        return dp[i] = ans; 
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n,0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            dp[i] = df(i,arr,d,dp,n);
            // ans = max(ans, dp[i]);
        }
        for(auto x:dp){ 
            ans = max(ans, x);
        // cout << x <<" ";
        }
        // cout <<"\n";
        return ans;
    }
};
