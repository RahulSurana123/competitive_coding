

/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are given an m x n grid. Each cell of grid represents a street. The street of grid[i][j] can be:

1 which means a street connecting the left cell and the right cell.
2 which means a street connecting the upper cell and the lower cell.
3 which means a street connecting the left cell and the lower cell.
4 which means a street connecting the right cell and the lower cell.
5 which means a street connecting the left cell and the upper cell.
6 which means a street connecting the right cell and the upper cell.

You will initially start at the street of the upper-left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.

Notice that you are not allowed to change any street.

Return true if there is a valid path in the grid or false otherwise.


    ***********************************************************
*/

class Solution {
public:
    // La  0:up 1:down 2:right 3:left
    bool isValid(int la, int g){
        switch(la) { 
            case -2: return false;
            case -1: return true;
            case 0: return g == 2 || g == 3 || g==4;
            case 1: return g == 2 || g == 5 || g==6;
            case 2: return g == 1 || g == 3 || g==5;
            case 3: return g == 1 || g == 4 || g==6;
            default: return false;
        };
        return false;
    }
    // La  0:up 1:down 2:right 3:left
    vector<int> next(int i, int j, int la, int p){
        switch(la) {
            case -1: {
                if(p == 1) return {i,j+1,2,i,j-1,3};
                if(p == 2) return {i+1,j,1,i-1,j,0};
                if(p == 3) return {i,j-1,3,i+1,j,1};
                if(p == 4) return {i,j+1,2,i+1,j,1};
                if(p == 5) return {i-1,j,0,i,j-1,3};
                return {i-1,j,0,i,j+1,2};
            } 
            case 0: {
                if(p == 2) return {i-1,j, 0};
                if(p == 3) return {i,j-1, 3};
                else return {i,j+1, 2};
            }
            case 1: { 
                if(p==2) return {i+1,j, 1};
                if(p==5) return {i,j-1, 3};
                else return {i,j+1, 2};
            }
            case 2: {
                if(p==1) return {i,j+1, 2};
                if(p==3) return {i+1,j, 1};
                else return {i-1,j, 0};
            }
            case 3: {
                if(p==1) return {i,j-1, 3};
                if(p==6) return {i-1,j, 0};
                else return {i+1,j,1};
            }
        };
        return {0,0,0};
    }


    // La  0:up 1:down 2:right 3:left
    bool df(int i,int j, vector<vector<int>>& grid, int la){
        if(i < 0 || j < 0 || i >= grid.size() || j>= grid[0].size() || !isValid(la,grid[i][j])) return false;
        if(i == grid.size()-1 && j == grid[0].size()-1) return true;
        auto x = next(i,j,la,grid[i][j]);
        grid[i][j] = -2; // mark vis
        return x.size()<=3 ? df(x[0],x[1],grid,x[2]):(df(x[0],x[1],grid,x[2]) | df(x[3],x[4],grid,x[5]));
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        return df(0,0,grid,-1);
    }
};