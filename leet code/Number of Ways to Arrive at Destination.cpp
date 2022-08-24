


/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. 
The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. 
You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.


    ***********************************************************
*/



#define ll long long
class Solution {
public:
    int MOD = 1e9 + 7;
    int compare(vector<int> a, vector<int> b){
        return a[2]<b[2];
    }
    
    int dfs(int v, vector<vector<int>> list){
        if(v == 0) return 1;
        int ans = 0;
        for(auto x : list[v]){
            ans += dfs(x,list);
        }
        return ans;
    }
    
    
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<ll> d(n+1,LONG_MAX);
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> s;
        vector<ll> ways(n);
        ways[0] = 1;
        vector<vector<pair<ll,ll>>> adj(n+1,vector<pair<ll,ll>>());
        for(auto x : roads){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        // sort(roads.begin(),roads.end(),compare);  
        d[0] = 0;
        s.push({0,0});
        while(!s.empty()){
            
            auto [z,u] = s.top();
            s.pop();
            if(d[u]<z) continue;
            for(auto x : adj[u]){
                int v = x.first;
                int w = x.second;
                if(d[v] > z + w){
                    
//                         if(d[x.first] != INT_MAX){
//                             s.erase(s.find({x.first,d[x.first]}));
//                         }
                        d[v] = z + w;
                        ways[v] = ways[u];
                        s.push({d[v],v});
                }
                else if(d[v]  == z + w) ways[v] = (ways[v] + ways[u]) % MOD;
            }
        }
        return ways[n-1];
    }
};