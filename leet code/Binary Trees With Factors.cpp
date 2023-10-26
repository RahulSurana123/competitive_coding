/* 
   
   Solution by Rahul Surana
    
    ***********************************************************

Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

We make a binary tree using these integers, and each number may be used for any number of times. 
Each non-leaf node's value should be equal to the product of the values of its children.

Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.

   
   ***********************************************************

*/

class Solution {
public:
    int MOD = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,int> dp;
        for(auto x: arr) dp[x]=1;
        for(auto x: arr){
            for(auto y: arr){
                if(y>sqrt(x)) break;
                if(x%y == 0 && dp.count(x/y)){
                    long long t = (long long)dp[y]*dp[x/y];
                    if( y == sqrt(x)) dp[x] = (dp[x] +t) %MOD;
                    else dp[x] = (dp[x]+t*2)%MOD;
                }
            }
        }
        int ans = 0;
        for(auto &x: dp){
            ans= (ans+x.second) %MOD; 
        }
        return ans;
    }
};