

/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are given three integers n, m and k. 
Consider the following algorithm to find the maximum element of an array of positive integers:

<code>

arr_max = -1, step = 0
for(auto z: arr) 
    if(arr_max < z)
        arr_max = z
        step++;
return step

</code>

You should build the array arr which has the following properties:

arr has exactly n integers.
1 <= arr[i] <= m where (0 <= i < n).
After applying the mentioned algorithm to arr, the value search_cost is equal to k.
Return the number of ways to build the array arr under the mentioned conditions. 
As the answer may grow large, the answer must be computed modulo 109 + 7.


    ***********************************************************
*/


#define MOD 1000000007
class Solution {
public:



    int numOfArrays(int n, int m, int k) {
        if(m < k  || k == 0) return 0;
        vector<vector<long>> pdp(m+1,vector<long>(k+1,0));
        vector<vector<long>> pps(m+1,vector<long>(k+1,0));
        for(int i = 1; i < m+1; i++){
            pdp[i][1] = 1;
            pps[i][1] = i; 
        }        
        for(int _ = 2; _ < n+1; _++){
            vector<vector<long>> dp(m+1,vector<long>(k+1,0));
            vector<vector<long>> ps(m+1,vector<long>(k+1,0));  
            for(int i = 1; i < m+1; i++){
                for(int j = 1; j < k+1; j++){
                    dp[i][j] = (i * pdp[i][j])%MOD;
                    if(j>1 && i >1){
                        dp[i][j] += pps[i-1][j-1];
                        dp[i][j] %= MOD;
                    }
                    ps[i][j] = (ps[i-1][j] + dp[i][j])%MOD;
                }
            }
            pps = ps;
            pdp = dp;
        }
        return pps[m][k];
    }
};