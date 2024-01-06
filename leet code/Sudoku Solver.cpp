

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.


    ***********************************************************
*/

class Solution {
public:

    vector<vector<char>> sudoku;
    vector<set<pair<int,int>>> blocks;

    pair<int,int> getNext(){
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                if(sudoku[i][j] == '.') {
                    return {i,j};
                }
            } 
        }
        return {-1,-1};
    }

    bool solve(){
        auto u = getNext();
        if(u.first == -1 && u.second == -1) return true;
        for(int k = 1; k <= 9; k++){
            if(error(u,('0' + k))){
                sudoku[u.first][u.second] = '0' + k;
                if(solve()) {
                    return true;
                }
                sudoku[u.first][u.second] = '.';
            }
        }
        sudoku[u.first][u.second] = '.';
        return false;
    }

    bool error(pair<int,int> pos, char num){
        
        for(int k = 0; k < 9; k++){
            if(pos.second != k && sudoku[pos.first][k] == num) return false;
            if(pos.first != k && sudoku[k][pos.second] == num) return false;
        }

        int block_number = (pos.first /3) *3 + pos.second/3;

        for(auto x: blocks[block_number]){
            if(pos.first!=x.first && pos.second != x.second && num == sudoku[x.first][x.second]){
                return false;
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        swap(sudoku,board);
        blocks.resize(9,set<pair<int,int>>());

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if( i < 3 && j < 3) blocks[0].insert({i,j});
                else if( i < 3 && j >= 3 && j <= 5) blocks[1].insert({i,j});
                else if( i < 3 && j >5) blocks[2].insert({i,j});
                else if( i >= 3 && i<= 5 && j < 3) blocks[3].insert({i,j});
                else if( i >= 3 && i<= 5 && j >= 3 && j <= 5) blocks[4].insert({i,j});
                else if( i >= 3 && i<= 5 && j > 5) blocks[5].insert({i,j});
                else if( i > 5 && j < 3 ) blocks[6].insert({i,j});
                else if( i > 5 && j >= 3 && j <= 5) blocks[7].insert({i,j});
                else if( i > 5 && j > 5) blocks[8].insert({i,j});
            }	
        }
        solve();
        swap(board,sudoku);
        
    }
};