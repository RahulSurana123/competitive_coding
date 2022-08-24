

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:   
    
    bool df(int i, int j, int y, vector<vector<char>>& board,string word,int n, int m){
        if(y == word.length()){
            return true;
        }
        if(i<0 || j < 0 || j > m-1 || i > n-1 || board[i][j] != word[y]) return false;
        board[i][j] = '0';
        bool ans = df(i+1,j,y+1,board,word,n,m) || df(i,j+1,y+1,board,word,n,m) || 
        df(i-1,j,y+1,board,word,n,m) || df(i,j-1,y+1,board,word,n,m);
        board[i][j] = word[y];
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(df(i,j,0,board,word,n,m)) return true;
            }   
        }
        return false;
    }
};