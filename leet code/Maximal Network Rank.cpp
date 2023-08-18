

/* 

    Solution by Rahul Surana
    
    ***********************************************************


There is an infrastructure of n cities with some number of roads connecting these cities. 
Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.

The network rank of two different cities is defined as the total number of directly connected roads to either city. 
If a road is directly connected to both cities, it is only counted once.

The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.

Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.


    ***********************************************************
*/

class Solution {
public:
    
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        vector<int> adj(n,0);
        int ans = 0;
        for(auto x: roads){
            adj[x[0]]++;
            adj[x[1]]++;
            vis[x[0]][x[1]] = true;
            vis[x[1]][x[0]] = true;
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                ans = max(ans,(adj[i]+adj[j]) - vis[i][j]);
            }
        }
        return ans;
    }
};