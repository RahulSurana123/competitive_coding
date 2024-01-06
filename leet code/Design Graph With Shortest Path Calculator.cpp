

/* 
    Solution by Rahul Surana
    
    ***********************************************************


There is a directed weighted graph that consists of n nodes numbered from 0 to n - 1. 
The edges of the graph are initially represented by the given array edges 
where edges[i] = [from(i), to(i), edgeCost(i)] meaning that 
there is an edge from from(i) to to(i) with the cost edgeCost(i).

Implement the Graph class:

-> Graph(int n, int[][] edges) initializes the object with n nodes and the given edges.
-> addEdge(int[] edge) adds an edge to the list of edges where edge = [from, to, edgeCost]. 
   It is guaranteed that there is no edge between the two nodes before adding this one.
-> int shortestPath(int node1, int node2) returns the minimum cost of a path from node1 to node2. 
   If no path exists, return -1. The cost of a path is the sum of the costs of the edges in the path.


    ***********************************************************
*/

class Graph {
public:

    vector<vector<int>> dist;
    int n;
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        dist.resize(n,vector<int>(n,1e9));
        for(int i = 0;i < n; i++) dist[i][i] = 0;
        for(auto edge : edges){
            dist[edge[0]][edge[1]]= edge[2];
        }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][j] > dist[i][k] + dist[k][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        if(dist[edge[0]][edge[1]] <= edge[2]) return;
            dist[edge[0]][edge[1]] = edge[2];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][j] > dist[i][edge[0]] + edge[2] + dist[edge[1]][j]){
                    dist[i][j] = dist[i][edge[0]] + edge[2] + dist[edge[1]][j];
                }
            }
        }
    }

    int shortestPath(int node1, int node2) {
        
        // cout << node1 <<" "<<node2 <<" "<< dis[node1][node2] <<"\n";
        return dist[node1][node2] >= 1e9? -1: dist[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */