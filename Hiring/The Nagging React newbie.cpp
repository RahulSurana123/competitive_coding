

/*

Solution by Rahul Surana

    ***********************************************************


JS newbie “A” wants to learn React from “B” and wants to know in his network who can introduce him to B in the shortest time period.

 

INPUT FORMAT

Total Members in UI Friend Network = N

MemberId1 = N1

MemberId2 = N2

MemberId3 = N3

MemberIdN = Nn

 

Total Possible Edges = E

<Follower 1> <Following 1> <Time taken to send the message> = p1,q1,t1

<Follower 2> <Following 2> <Time taken to send the message> = p2,q2,t2

<Follower 3> <Following 3> <Time taken to send the message> = p3,q3,t3

<Follower N> <Following N> <Time taken to send the message> = pn,qn,tn 

Follower (Ninja A) = A

Following (JS expert B) = B 

 

OUTPUT FORMAT

Shortest Time A takes to reach B



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
#define fast_io     std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;

map<int,vector<int>> adj;

bool bfs(int s, int t)
{
    map<int,int> p;
    for(auto x: adj) p[x.F] = -1;
    queue<int> q;
    q.push(s);
    p[s] = s;
    map<int,bool> v;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if(v[u]) continue;
        v[u] = 1;
        if(u == t) { return true; }
        for (auto x: adj[u])
        {   
            if(!v[x])
            {   
                q.push(x);
                p[x] = u;
            }
        }
    }
  
    return false;
}


bool dfs(int s, int d, int p){
    if(s == d) return true;
    else{
        bool f = false;
        for(auto m : adj[s]){
            if(m!=p) f = dfs(m,d,s);
            if(f) break;
        }
        return f;
    }
}
  
// int min_cut(int source, int sink){
//     cap = adj;
//     int ans = 0;
//     while(bfs(source, sink)){
//         ans++;
//         int u = sink;
//         while(u != p[u]){
//             // cout << p[u] <<" - "<< u <<"\n";
//             cap[p[u]].erase(find(cap[p[u]].begin(),cap[p[u]].end(),u));
//             u = p[u];
//         }
//     }
//     return ans;
// }

int main()
{
    fast_io;
    int e,n;
    cin >> e;
    FOR(i,e) { int f; cin >>f; adj[f] = vector<int>(); }
    cin >> n;
    FOR(i,n) {
        int a,b;
        cin >> a >> b; 
        adj[b-1].pb(a-1); 
    }
    
    int x,y;
    cin >> x >> y;
    vector<int> ans;
    for(auto z : adj[y-1]){
        if(bfs(z,x-1)){
            ans.pb(z+1);
        }
    }
    for(auto z: ans) cout << z <<" ";
}