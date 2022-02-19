



/* 

    Solution by Rahul Surana

    ***********************************************************


Given a grid consisting of '0's(Water) and '1's(Land). Find the number of islands.
Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally 
i.e., in all 8 directions.


    ***********************************************************
*/



// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    void dfs(int i, int j, vector<vector<char>>& grid,vector<vector<bool>>& v){
        if(i>=grid.size() || j>=grid[0].size() || i< 0 || j <0 || grid[i][j] == '0') return;
        if(v[i][j]) return;
        v[i][j] = true;
        dfs(i+1,j,grid,v);
        dfs(i+1,j-1,grid,v);
        dfs(i+1,j+1,grid,v);
        dfs(i-1,j,grid,v);
        dfs(i,j-1,grid,v);
        dfs(i,j+1,grid,v);
        dfs(i-1,j-1,grid,v);
        dfs(i-1,j+1,grid,v);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> v(grid.size(),vector<bool>(grid[0].size(), false));
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(!v[i][j] && grid[i][j] == '1'){
                    dfs(i,j,grid,v);
                    ans++;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends