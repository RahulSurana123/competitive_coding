

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a gold mine called M of (n x m) dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner can start from any row in the first column. From a given cell, the miner can move

-> to the cell diagonally up towards the right 
-> to the right
-> to the cell diagonally down towards the right
Find out maximum amount of gold which he can collect.



    ***********************************************************
*/


// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // vector<vector<int>> dp;

    // int lf(int i, int j, int n, int m, vector<vector<int>> M){
    //     if( i < 0 || i >= n || j >= m) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
        
    //     int ans = M[i][j] + max(lf(i-1,j+1,n,m,M),max(lf(i,j+1,n,m,M),lf(i+1,j+1,n,m,M)));
    //     // cout << i << " " <<j << " "<<ans<<"\n";
    //     return dp[i][j] = ans;
    // }

    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // dp.resize(n,vector<int>(m,-1));
        int ans = 0;
        for(int j = 1; j < m; j++){
            for(int i = 0; i < n; i++){
                M[i][j] += max({((i>0) ? M[i-1][j-1] : 0), M[i][j-1], ((i+1<n) ? M[i+1][j-1] : 0)});
            }
        }
        
        for(int i = 0; i < n; i++){
            ans = max(ans,M[i][m-1]);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends