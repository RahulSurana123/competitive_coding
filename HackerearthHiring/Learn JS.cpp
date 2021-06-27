
/*

Solution by Rahul Surana

    ***********************************************************

Input:

-> n 
-> n no of nodes
-> e 
-> e no of weighted(time) directed edges
-> Source Node
-> Destination Node

Output:

print shortest time to reach from source to destination


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

map<int,vector<pi>> adj;
map<int,bool> v;

int minimumCostSimplePath(int s, int d)
{
    if (s == d)
        return 0;
    v[s] = 1;
 
    int ans = INT_MAX;
    for (auto z : adj[s]) {
        if (!v[z.F]) {
            int curr = minimumCostSimplePath(z.F,
                        d);
            ans = min(ans, z.S + curr);
        }
    }
    v[s] = 0;
 
    return ans;
}

bool dfs(int s, int d){
    if(s == d) return true;
    else{
        bool f = false;
        for(auto m : adj[s]){
            f = dfs(m.F,d);
            if(f) break;
        }
        return f;
    }
}

int main()
{
	fast_io;
    int e,n;
    cin >> e;
    FOR(i,e) { int f; cin >>f; adj[f] = vector<pi>(); v[f] = false; }
    cin >> n;
    FOR(i,n) {
        int a,b,t;
        cin >> a >> b >> t; 
        adj[a-1].pb({b-1,t}); 
    }
    int x,y;
    cin >> x >> y;
    cout << minimumCostSimplePath(x-1,y-1) << "\n";
}