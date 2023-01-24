



/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the 
bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 
6 destinations, regardless of the size of the board.
If next has a snake or ladder, you must move to the destination of that snake or ladder. 
Otherwise, you move to next.
The game ends when you reach the square n2.
A board square on row r and column c has a snake or ladder if board[r][c] != -1. 
The destination of that snake or ladder is board[r][c]. Squares 1 and n2 do not have a snake or ladder.

Note that you only take a snake or ladder at most once per move. If the destination to a snake or 
ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.

For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. 
You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
Return the least number of moves required to reach the square n2. If it is not possible to reach the square, return -1.
 

    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();        
        if(n*n < 7) return 1;
        vector<pair<int,int>> num((n*n)+n);
        int w = 1;
        for(int i = n-1; i >= 0; i--){
            int dir = ((w/n)%2)==1? -1:1;
            int j = (dir == -1) ? n-1:0;
            int a = n;
            while(a--){
                num[w++]= {i,j};
                if(dir == 1) j++;
                else j--; 
            }
        }
        vector<int> dir((n*n)+n,-1);
        queue<int> q;
        q.push(1);
        dir[1] = 0;
        while(!q.empty()){
            auto x = q.front();
            q.pop();

            for(int i = x+1 ; i <= min(x+6 , n*n); i++){
                auto [a,b] = num[i];
                int des = board[a][b] != -1 ? board[a][b]:i;
                if(dir[des] == -1){
                    dir[des] = dir[x]+1;
                    if(des == n*n) return dir[des];
                    q.push({des});
                }
           
            }
        }

        return dir[n*n];
    }
};