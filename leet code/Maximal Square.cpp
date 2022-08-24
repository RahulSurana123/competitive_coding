



/* 
    Solution by Rahul Surana
    
    ***********************************************************

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

    ***********************************************************
*/


class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int i,int j,int n, int m, vector<vector<char>> matrix){
        if(i >= n || j >= m) return 0;
        if(matrix[i][j] == '0') return 0;
        if(dp[i][j] != -1) return dp[i][j];
        // cout << i << " " << j <<" "<< matrix[i][j]<< " \n";
        int s = dfs(i+1,j+1,n,m,matrix);
        return dp[i][j] = min(min(dfs(i+1,j,n,m,matrix),dfs(i,j+1,n,m,matrix)),s)+1;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int x=0,n=matrix.size(),m= matrix[0].size();
        dp.resize(n+1,vector(m+1,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0){
                    if(matrix[i][j]!='0') { x = 1; dp[i][j] = 1; }
                    continue;
                }
                if(matrix[i][j] == '0') dp[i][j]=0;
                else{
                    int a =min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
                    if(a==0)
                    dp[i][j] = 1;
                    else{
                        dp[i][j] = 1+a;
                    }
                }
            }   
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                x = max(x,dp[i][j]);
            }   
            cout << "\n";
        }
        return x*x;
    }
};