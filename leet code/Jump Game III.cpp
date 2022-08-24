


/* 
    Solution by Rahul Surana
    
    ***********************************************************

Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

Notice that you can not jump outside of the array at any time.

    ***********************************************************
*/



class Solution {
public:
    
    vector<int> dp;
    vector<int> v;
    
    bool df(int s, int n, vector<int>& ar){
        if(s > n-1 || s<0) return false;
        v[s] = 1;
        if(dp[s] != -1) return dp[s]; 
        if(ar[s]==0) return true;
        bool f = false;
        if(s+ar[s]<n && v[s+ar[s]] == 0)
            f = df(s+ar[s],n,ar);
        if(f) return dp[s] = f;
        else {
            if(s-ar[s]>=0 && v[s-ar[s]] == 0)
                return dp[s] = df(s-ar[s],n,ar);
            return false;
        }
    }
    
    bool canReach(vector<int>& arr, int start) {
        dp.resize(arr.size(),-1);
        v.resize(arr.size(),0); 
        return df(start,arr.size(),arr);
    }
};