

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given N identical eggs and you have access to a K-floored building from 1 to K.

There exists a floor f where 0 <= f <= K such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break. There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
Return the minimum number of moves that you need to determine with certainty what the value of f is.

For more description on this problem see wiki page ( http://en.wikipedia.org/wiki/Dynamic_programming#Egg_dropping_puzzle )


    ***********************************************************
*/


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    vector<vector<int>> dp;
    int df(int n, int k){
        if(n==1) return k;
        if(k==1 || k==0) return k;
        if(dp[n][k] != -1) return dp[n][k];
        int ans = INT_MAX;
        for(int i = 1;i<=k; i++){
            int temp = 1+max(df(n-1,i-1),df(n,k-i));
            ans = min(ans,temp); 
        }
        // cout << n << " "<< k << " "<<ans <<"\n";
        return dp[n][k] = ans;
    }
    
    int eggDrop(int n, int k) 
    {
        dp.resize(n+1,vector<int>(k+1,-1));
        return df(n,k);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends