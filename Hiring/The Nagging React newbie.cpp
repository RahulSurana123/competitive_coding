


/*

Solution by Rahul Surana

    ***********************************************************



A Nagging React newbie “B” is constantly troubling React expert “A”. React Expert “A” needs to know the minimum set of people following him he needs to remove from his network to stop “B” from reaching out to him.

INPUT FORMAT

Total Members in UI Friend Network = N

MemberId1 = N1

MemberId2 = N2

MemberId3 = N3

MemberIdN = Nn

Total Possible Edges = E

<Follower 1> <Following 1>

<Follower 2> <Following 2>

<Follower N> <Following N>

Follower = A

Following = B

 

OUTPUT FORMAT

Set of memberId “A” needs to block


    ***********************************************************


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

map<int,vector<int>> adj;
map<int,bool> v;
map<int,int> p;
map<int,vector<int>> level;

void bfs(int s, int t)
{
    queue<pair<int,int>> q;
    q.push({0,s});
    for(auto x: v) {
        x.S = false;
    }
    v[s] = true;
    p[s] = -1;
  
    while (!q.empty())
    {
        int u = q.front().S;
        int l = q.front().F;
        q.pop();
        if(u == t) continue;
        for (auto x: adj[u])
        {
            if (v[x]==false)
            {   level[l+1].pb(x);
                q.push({l+1,x});
                p[x] = u;
                v[x] = true;
            }
        }
    }
  
    // If we reached sink in BFS starting from source, then return
    // true, else false
    return ;
}
  
// A DFS based function to find all reachable vertices from s.  The function
// marks visited[i] as true if i is reachable from s.  The initial values in
// visited[] must be false. We can also use BFS to find reachable vertices
// void dfs(map<int,vector<int>> &ad, int s, map<int,bool> &visited)
// {
//     visited[s] = true;
//     for (auto x: ad[s])
//        if (!visited[x])
//            dfs(ad, x, visited);
// }
  
// int minCut(int s, int t)
// {
//     int u, v;
//     map<int,vector<int>> copy;
//     for(auto x: adj){
//         copy[x.F] = vector<int>(x.S.begin(),x.S.end());
//     }
//     while (bfs(copy,s, t))
//     {
//         for (v=t; v != s; v=p[v])
//         {
//             u = p[v];
//             copy[u].erase(find(copy[u].begin() ,copy[u].end() ,v));
//         }
//     } 
  
//     return ans;
// }

// bool dfs(int s, int d){
//     if(s == d) return true;
//     else{
//         bool f = false;
//         for(auto m : adj[s]){
//             f = dfs(m.F,d);
//             if(f) {  break; }
//         }
//         return f;
//     }
// }

int main()
{
	fast_io;
    int e,n;
    cin >> e;
    FOR(i,e) { int f; cin >>f; adj[f] = vector<int>(); v[f] = false; }
    cin >> n;
    FOR(i,n) {
        int a,b;
        cin >> a >> b; 
        adj[a-1].pb(b-1); 
    }
    
    int x,y;
    cin >> x >> y;
    bfs(x-1,y-1);
    int ans = INT_MAX;
    vector<int> print;
    for(auto x: level){
        ans = min(ans,(int)(x.S.size()));
        if(ans == (int)x.S.size()) {
            print.clear(); 
            print = vector<int>(x.S.begin(),x.S.end()); 
        }
    }
    FOR(i,print.size()) cout << print[i] + 1 <<" ";
}