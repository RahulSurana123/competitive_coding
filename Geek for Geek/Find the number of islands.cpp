



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
    void dfs(int i, int j, int n, int m,vector<vector<char>> &grid){
    	grid[i][j] = '0';
    	if(i > 0 && grid[i-1][j] != '0') dfs(i-1,j,n,m,grid);
    	if(i < n-1 && grid[i+1][j]!='0') dfs(i+1,j,n,m,grid);
    	if(j > 0 && grid[i][j-1] != '0') dfs(i,j-1,n,m,grid);
    	if(j < m-1 && grid[i][j+1] != '0') dfs(i,j+1,n,m,grid);
    	if(i > 0 && j > 0 && grid[i-1][j-1]!='0') dfs(i-1,j-1,n,m,grid);
    	if(i < n-1 && j > 0 && grid[i+1][j-1]!='0') dfs(i+1,j-1,n,m,grid);
    	if(j < m-1 && i > 0 && grid[i-1][j+1]!='0') dfs(i-1,j+1,n,m,grid);
    	if(j < m-1 && i < n-1 && grid[i+1][j+1]!='0') dfs(i+1,j+1,n,m,grid);
    }
    //Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) 
    {
    	int c = 0;
    	int n = grid.size();
    	int m = grid[0].size();
        for(int i = 0; i < n; i++){
        	for(int j = 0; j < m; j++){
        		if(grid[i][j] == '1') {
        			dfs(i,j,n,m,grid);
        			c++;
        // 			for(int i = 0; i < n; i++){
        // 	        for(int j = 0; j < m; j++){ cout << v[i][j] <<" ";} cout << "\n";}
                    // cout<<""
        		}
        	}	
        }
        return c; 
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