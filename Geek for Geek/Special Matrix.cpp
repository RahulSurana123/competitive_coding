

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given a matrix having n rows and m columns. 
The special property of this matrix is that some of the cells of this matrix are blocked i.e. they cannot be reached. 
Now you have to start from the cell (1,1) and reach the end (n,m) provided during the journey you can move horizontally 
right from the current cell or vertically down from the current cell. 
Can you answer the number of ways you can traverse the matrix obeying the above constraints starting from (1,1) and ending at (n,m).



    ***********************************************************
*/


// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
    
    int MOD = 1e9+7;
    
    int df(int i, int j, vector<vector<bool>> &go,vector<vector<int>> &dp){
        if(i== go.size() || j == go[0].size() || !go[i][j]) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(i==go.size()-1 && j == go[0].size()-1) return 1;
        int ans = (df(i+1,j,go,dp)%MOD + df(i,j+1,go,dp)%MOD) %MOD;
        return dp[i][j]=ans;
    }

    int FindWays(int n, int m, vector<vector<int>> blocked_cells){
        vector<vector<bool>> go(n,vector<bool>(m,true));
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(auto bc: blocked_cells){
            go[bc[0]-1][bc[1]-1] = false;
        }
        return df(0,0,go,dp);
    }
};

// { Driver Code Starts.
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>>blocked_cells;
        for(int i = 0; i < k; i++){
            int x, y;
            cin >> x >> y;
            blocked_cells.push_back({x, y});
        }
        Solution obj;
        int ans = obj.FindWays(n, m, blocked_cells);
        cout << ans <<'\n';
    }
    return 0;
}  // } Driver Code Ends