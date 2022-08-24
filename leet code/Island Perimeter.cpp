

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). 
The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. 
One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.



    ***********************************************************
*/






class Solution {
public:
    
    vector<vector<bool>> v;
    
//     int df(int i,int j,int n,int m,vector<vector<int>> g){
//         if(i < 0 || j < 0 || i > n-1 || j > m-1) return 0;
//         if(g[i][j] == 0) return 0;
//         if(v[i][j]) return -1;
//         v[i][j]=true;
//         cout << i<<" " <<j<<" \n";
//         int ans = 0;
//         int a =-1,b=-1,c=-1,d=-1; 
//         // if(i>0 && !v[i-1][j]) 
//             a = df(i-1,j,n,m,g);
//         // if(j>0 && !v[i][j-1]) 
//             b = df(i,j-1,n,m,g);
//         // if(i<n-1 && !v[i+1][j]) 
//             c = df(i+1,j,n,m,g);
//         // if(j<m-1 && !v[i][j+1]) 
//             d = df(i,j+1,n,m,g);
//         if(a == 0) ans++;
//         else if(a > 0) ans+=a;
//         if(b == 0) ans++;
//         else if(b > 0) ans+=b;
//         if(c == 0) ans++;
//         else if(c > 0) ans+=c;
//         if(d == 0) ans++;
//         else if(d > 0) ans+=d;
        
//         cout << i<<" " <<j<<" " << ans<<" \n";
//         return ans;
//     }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // v.resize(n+1,vector<bool>(m+1,false));
        int ans=0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    ans+=4;        
                    if(i > 0 && grid[i-1][j]) ans-=2;
                    if(j > 0 && grid[i][j-1]) ans-=2;
                }
            }
        }
        return ans;
    }
    
};