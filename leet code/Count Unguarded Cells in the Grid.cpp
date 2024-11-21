

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given two integers m and n representing a 0-indexed m x n grid. 
You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and 
walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.

A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. 
A cell is guarded if there is at least one guard that can see it.

Return the number of unoccupied cells that are not guarded.



    ***********************************************************
*/


class Solution {
public:

    void fill(vector<vector<int>> &vis, int x, int y, int m, int n){
        for(int r = x-1; r>=0; r--){
            if (vis[r][y] == 1 || vis[r][y] == 2) break;
            vis[r][y] = 3;
        }
        for(int r = x+1; r<m; r++){
            if (vis[r][y] == 1 || vis[r][y] == 2) break;
            vis[r][y] = 3;
        }
        for(int r = y-1; r>=0; r--){
            if (vis[x][r] == 1 || vis[x][r] == 2) break;
            vis[x][r] = 3;
        }
        for(int r = y+1; r<n; r++){
            if (vis[x][r] == 1 || vis[x][r] == 2) break;
            vis[x][r] = 3;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans = 0;
        for( auto &z: walls){
            vis[z[0]][z[1]] = 1;
        }
        for( auto &z: guards){
            vis[z[0]][z[1]] = 2;
        }
        for( auto &z: guards){
            fill(vis,z[0],z[1],m,n);
        }
       
        for(auto &z: vis){
            for(auto &x: z){ans+=(x ==0);}
        }
        return ans;
    }
};
