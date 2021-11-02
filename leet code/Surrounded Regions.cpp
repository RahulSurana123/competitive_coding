
/* 

    Solution by Rahul Surana

    ***********************************************************

Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.



    ***********************************************************

*/



#include <bits/stdc++.h>
class Solution {
public:
    
    vector<vector<int>> v;
    
    void dfs(int i, int j, int m, int n,vector<vector<char>>& board){
        // bool a=true,b=true,c=true,d=true;
        if(i < 0 || j < 0 || i > m-1 || j > n-1 || board[i][j] == 'X') return;
        v[i][j] = 1;
        if(i > 0 && !v[i-1][j]) {
            cout << i-1 <<" "<< j <<" "<< board[i-1][j] <<"\n";
            dfs(i-1,j,m,n,board);  
        }
        if(i < m-1 && !v[i+1][j]) {
            cout << i+1 <<" "<< j <<" "<< board[i+1][j] <<"\n";
            dfs(i+1,j,m,n,board);    
        }
        if(j > 0 && !v[i][j-1]) {
            cout << i <<" "<< j-1 <<" "<< board[i][j-1] <<"\n";
            dfs(i,j-1,m,n,board);   
        }
        if(j < n-1 && !v[i][j+1]) {
            cout << i <<" "<< j+1 <<" "<< board[i][j+1] <<"\n"; 
            dfs(i,j+1,m,n,board); 
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size(),n=board[0].size();
        v.resize(m,vector<int>(n,0)); 
        for(int i = 0 ; i < m; i++){
                dfs(i,0,m,n,board);
                dfs(i,n-1,m,n,board);
        }
        for(int i = 0 ; i < n; i++){
                dfs(0,i,m,n,board);
                dfs(m-1,i,m,n,board);
        }
        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j < n; j++){
                if(!v[i][j]) board[i][j] = 'X';
            }
        }
        // cout << "\n";
    }
};