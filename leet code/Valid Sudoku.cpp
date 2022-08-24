

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.



    ***********************************************************
*/


#include <bits/stdc++.h>


class Solution {
public:
    
    bool isValidSudoku(vector<vector<char>>& board) {
       for(int i = 0; i < 9; i++){
           set<char> s;
           for(int j = 0; j < 9; j++){
               if(s.count(board[i][j]) ) return false;
               else if(board[i][j] != '.') s.insert(board[i][j]);
               // cout << "("<<i<<","<<j<<") ";
           }
           cout <<"\n";
       }
        for(int i = 0; i < 9; i++){
           set<char> s;
           for(int j = 0; j < 9; j++){
               if(s.count(board[j][i])) return false;
               else if(board[j][i] != '.') s.insert(board[j][i]);
               // cout << "("<<j<<","<<i<<") ";
           }
            cout <<"\n";
       }
        
        for(int k = 0; k < 3; k++){
            for(int l = 0; l < 3; l++){
                set<char> s;
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        if(s.count(board[(k*3)+i][(l*3)+j])) return false;
                        else if(board[(k*3)+i][(l*3)+j] != '.') s.insert(board[(k*3)+i][(l*3)+j]);
                        // cout << "("<<(k*3)+i<<","<<(l*3)+j<<") ";
                    }
                    cout <<"\n";
                }
            }
        }
        return true;
    }
};