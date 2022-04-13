

/* 

    Solution by Rahul Surana
    
    ***********************************************************


According to Wikipedia's article: "The Game of Life, also known simply as Life, 
is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0).
 Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, 
where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> b(board.begin(),board.end());
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                int c = 0;
                if(i > 0){
                    if(j > 0) {
                        c += b[i-1][j-1] == 1;
                    }
                    if(j < board[i].size()-1){
                        c += b[i-1][j+1] == 1;
                    } 
                    c += b[i-1][j] == 1;
                }
                if(j > 0){
                    if(i < board.size()-1){
                        c += b[i+1][j-1] == 1;
                    } 
                    c += b[i][j-1] == 1;
                }
                if(i < board.size()-1){
                    if(j < board[i].size()-1) {
                       c += b[i+1][j+1] == 1;
                    }
                    c += b[i+1][j] == 1;
                }
                if(j < board[i].size()-1) c+=b[i][j+1] == 1 ;
                    
                if(c<2) board[i][j] = 0;
                else if(c>3) board[i][j] = 0;
                else if(c==3) board[i][j] = 1;
                // else board[i][j] = 1;
            }   
        }
    }
};