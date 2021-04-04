
/*

You are given an undirected weighted graph with n vertices and m edges.

Consider all shortest paths between vertices 1 and n, for any vertex such as v(1 <= v <= n), say that, if v is in either all shortest paths or some of them or none of them.

Input format

The first line contains two integers n, m denoting the number of the graph's vertices and edges respectively.
Each of the following m lines contains space-separated ui, vi, and wi describing the graph's ith edge's vertices (ui,vi) and its weight (wi).
Output format

Print n lines where the ith line contains either all if vertex i is in all shortest paths between 1 to n or some if vertex i is in some of shortest paths or none otherwise.



*/


#include <bits/stdc++.h>
#define ll          long long
#define vl          vector<ll>
#define vi          vector<int>
#define pi          pair<int,int>
#define pl          pair<ll,ll>
#define all(a)      a.begin(),a.end()
#define mem(a,x)    memset(a,x,sizeof(a))
#define pb          push_back
#define mp          make_pair
#define F           first
#define S           second
#define FOR(i,a)     for(int i = 0; i < a; i++)
#define trace(x)    cerr<<#x<<" : "<<x<<endl;
#define trace2(x,y) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<" | "<<#z<<" : "<<z<<endl;
#define fast_io 	std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;

vector<pi> adj[200000];
vector<int> edgeTo[200000];
const int INF = 0x3f3f3f3f;
int distTo[200000];
vector<vector<int>> paths;

// utility function to check if current
// vertex is already present in path
bool isNotVisited(int x, vector<int> &path)
{
    for (int i = 0; i < path.size(); i++)
        if (path[i] == x)
            return false;
    return true;
}
 
// utility function for finding paths in graph
// from source to destination
void findpaths(int src, int dst)
{
    // create a queue which stores
    // the paths
    queue<vector<int>> q;
    vector<int> path;
    // path vector to store the current path
    path.push_back(src);
    q.push(path);
    while (!q.empty()) {
        path = q.front();
        q.pop();
        int last = path[path.size() - 1];
 
        // if last vertex is the desired destination
        // then print the path
        if (last == dst) {
            // int s = 0;
            paths.pb(path);
        }
        // traverse to all the nodes connected to
        // current vertex and push new path to queue
        for (int i = 0; i < edgeTo[last].size(); i++) {
            if (isNotVisited(edgeTo[last][i], path)) {
                vector<int> newpath(path);
                newpath.push_back(edgeTo[last][i]);
                q.push(newpath);
            }
        }
    }
}

// void  dfsPaths(pi ps, int d) {
//     v[ps.F] = true;
//     path[path_index++] = ps;
//     if(ps.F == d){
//         vector<pi> x;
//         for(int i = 0; i < path_index; i++) {
//             x.pb(path[i]);
//         }
//         paths.pb(x);
//     }
//     else{
//         for(int i = 0; i < adj[s].size(); i++) {
//             if(!v[adj[s][i].F]) dfsPaths(adj[s][i],d);
//         }
//     }
//     path_index--;
//     v[s] = false;
// }

void shortestPaths(int s, int d) {
    
    priority_queue<pi,vector<pi>,greater<pi>> p;
    
    p.push({0,s});
    distTo[s] = 0;
    edgeTo[s].pb(s);
    while(!p.empty()){
        int u = p.top().S;
        int c = p.top().F;
        p.pop();
        if(distTo[u]<c) continue;
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first; // node
            int w = adj[u][i].second; // edge weight

            if(distTo[v] > distTo[u] + w) {
                distTo[v] = distTo[u] + w;
                edgeTo[v].clear();
                edgeTo[v].pb(u); 
                // cout << 1 <<"u " << u <<" w "<< w<<" dist "<< distTo[v] << "edgeTo " << edgeTo[v][0] <<" \n";
                p.push({distTo[v], v});
            }
            else if(distTo[v] == distTo[u] + w) {
                edgeTo[v].pb(u);
                // cout << 2 <<"u " << u <<" w "<< w<<" dist "<< distTo[v] << "edgeTo " << edgeTo[v][1] <<" \n";    
            }
        }
    }
}

// vector<int> path_d(int d){
//     vector<int> p;
//     queue<vector<pi>> q;
//     if(s == )
//     int i = d;
//     while(edgeTo[i] != i){
//         p.pb(i);
//         i = edgeTo[i];
//     }
//     p.pb(i);
//     return p;
// }

int main()
{
	fast_io;
    int n, m;
    cin >> n >> m;
    
    FOR(i,n) { distTo[i] = INF; }
    FOR(i,m) {
        int a,b,w;
        cin >> a >> b >> w; 
        adj[a-1].pb({b-1,w}); 
        adj[b-1].pb({a-1,w}); 
    }
    // Atempt 1
    shortestPaths(0,n-1);
    findpaths(n-1,0);
    int counts[n];
    FOR(i,n) counts[i] = 0;
    FOR(i,paths.size()) { FOR(j,paths[i].size()) counts[paths[i][j]]++; }
    // FOR(i,n) { cout << counts[i] << " "; }
    // cout <<"\n";
    // FOR(i,n) { FOR(j,edgeTo[i].size()) cout << i << edgeTo[i][j] <<" ";
    // cout <<"\n"; }
    // FOR(i,paths.size()) { FOR(j,paths[i].size()) 
    //         cout << " " << paths[i][j] << " "; 
    //     cout <<"\n"; }
    FOR(i,n) { 
        
        if(counts[i] == paths.size()) cout << "all\n";
        else if(counts[i]<paths.size() && counts[i] != 0) cout << "some\n";
        else cout << "none\n";
    }
    // vector<int> path = path_d(n-1);
    // sort(path.begin(),path.end());
    // int ind = 0;
    // vector<int> ans[3];
    // FOR(i,n) if(edgeTo[i].size())
    // FOR(i,n) { 
    //     if(ind < path.size() && path[ind] == i) { 
    //         cout << "all\n"; 
    //         ind++; 
    //         }
    //     else cout <<"none\n";
    // }
    // Atempt 2
    // dfsPaths(0,n-1);
    // FOR(i,paths.size()) {
    //     int s;
    //     FOR(j,paths[i].size()) cout << paths[i][j] << " "; 
    //     cout <<"\n";
    // } 
    // Attempt 3
    // findpaths(0,n-1);
    // int distTo[paths.size()];
    // FOR(i,paths.size()) {
    //     int s = 0;
    //     // sort(paths[i].begin(),paths[i].end());
    //     FOR(j,paths[i].size()) { 
    //         // cout << paths[i][j].F << " "; 
    //         s+=paths[i][j].S ;
    //     }
    //     // cout << s <<"\n";
    //     distTo[i] = s;
    // }
    // int min1=INF,c=0;
    // FOR(i,paths.size()) { 
    //     if(min1>=distTo[i]) { 
    //         min1 = distTo[i]; 
    //     }
    // }
    // int print[n];
    // FOR(i,n) print[i] = 0;
    // FOR(i,paths.size()) {
    //     if(distTo[i] == min1) {
    //         FOR(j,paths[i].size()) { 
    //             print[paths[i][j].F]++;
    //         }
    //         c++;
    //     }
    // }
    // // cout << "\n" << c <<"\n"; 
    // FOR(i,n) {
    //     // cout << print[i]<<" ";
    //     if(print[i]==0) cout<<"none\n"; 
    //     else if(print[i]==c) cout << "all\n"; 
    //     else cout << "some\n";
    // }
}