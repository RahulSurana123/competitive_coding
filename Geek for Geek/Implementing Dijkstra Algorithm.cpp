

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a weighted, undirected and connected graph of V vertices and E edges, 
Find the shortest distance of all the vertex's from the source vertex S.
Note: The Graph doesn't contain any negative weight cycle.



    ***********************************************************
*/


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,S});
        dist[S] = 0;
        while(!pq.empty()){
            auto z = pq.top();
            pq.pop();
            // if(z.second > ) continue;
            for(auto x: adj[z.second]){
                if(dist[x[0]] > dist[z.second] + x[1]){
                    dist[x[0]] = dist[z.second] + x[1];
                    pq.push({dist[x[0]],x[0]});
                }
            }
        }
        return dist;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);
        
        for(int i=0; i<V; i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends