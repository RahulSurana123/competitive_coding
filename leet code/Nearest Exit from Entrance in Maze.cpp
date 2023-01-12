



/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and 
walls (represented as '+'). You are also given the entrance of the maze, 
where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.

In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, 
and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. 
An exit is defined as an empty cell that is at the border of the maze. 
The entrance does not count as an exit.

Return the number of steps in the shortest path from the entrance to the nearest exit, 
or -1 if no such path exists.

 

    ***********************************************************
*/



class Solution {
public:
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int x = entrance[0] ,y = entrance[1];
        
        queue<pair<int,int>> q;
        q.push({x,y});
        
        int s = 0;
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto z = q.front();
                q.pop();
                 if(z.first < 0 || z.second < 0 || z.first>= maze.size() || z.second >= maze[0].size()){
                     if(s==1) continue;
                     return s-1;
                }
                if(maze[z.first][z.second] == '+') continue;
                
                maze[z.first][z.second] = '+';
                q.push({z.first+1,z.second});
                q.push({z.first,z.second+1});
                q.push({z.first-1,z.second});
                q.push({z.first,z.second-1});
            }
            s++;
        }
        return -1;
    }
};