

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges 
where edges[i] = [ai, bi, weighti] represents a bidirectional and weighted edge between nodes ai and bi. 
A minimum spanning tree (MST) is a subset of the graph's edges that 
connects all vertices without cycles and with the minimum possible total edge weight.

Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). 
An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. 
On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.

Note that you can return the indices of the edges in any order.


    ***********************************************************
*/

class Solution {
public:

    vector<int> p;
    vector<int> size;
    int ms = 1;

    int find(int a){
        if(p[a] != a) p[a] = find(p[a]);
        return p[a];
    }

    bool con(int a, int b){
        int x = find(a);
        int y = find(b);
        if(x==y) return false;
        if(size[x]<size[y]) swap(x,y);
        p[y] = x;
        size[x] += size[y];
        ms = max(ms,size[x]);
        return true;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < edges.size(); i++) edges[i].push_back(i);
        sort(edges.begin(), edges.end(),[&](auto a, auto b){return a[2]<b[2];});
        p.resize(n,0);
        size.resize(n+1,1);
        ms = 1;
        for(int i = 0; i < n; i++) {p[i] = i; size[i] = 1;}
        int mst = 0;
        for(auto x: edges){
            int u = x[0], v = x[1], w = x[2];
            if(con(u,v)){
                mst += w;
            }
        }
        vector<vector<int>> ans(2,vector<int>());
        for(int i = 0; i < edges.size(); i++){
            ms = 1;
            for(int j = 0; j < n; j++)  {p[j] = j; size[j] = 1;}
            int new_mst = 0;
            for(int j = 0; j < edges.size(); j++){
                if(j == i) continue;
                int u = edges[j][0], v = edges[j][1], w = edges[j][2];
                if(con(u,v)){
                    new_mst += w;
                }
            }
            // cout << mst <<" "<<new_mst<<" "<<ms<<" "<<edges[i][3]<<"\n";
            if(ms < n || mst < new_mst) ans[0].push_back(edges[i][3]);
            else{
                ms = 1;
                for(int j = 0; j < n; j++)  {p[j] = j; size[j] = 1;}
                new_mst = edges[i][2];
                con(edges[i][0],edges[i][1]);
                for(int j = 0; j < edges.size(); j++){
                    if(j == i) continue;
                    int u = edges[j][0], v = edges[j][1], w = edges[j][2];
                    if(con(u,v)){
                        new_mst += w;
                    }
                }
                // cout << mst <<" "<<new_mst<<" "<<i<<"\n";
                if(mst == new_mst) ans[1].push_back(edges[i][3]);
            }
        }
        return ans;
    }
};