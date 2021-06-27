
/*

Solution by Rahul Surana

    ***********************************************************

Input:

-> n 
-> n no of nodes
-> e 
-> e no of directed edges
-> Source Node
-> Destination Node

Output:

print 1 if source can reach destination else print 0


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
map<int , bool> v;

bool dfs(int s, int d){
    v[s] = true;
    if(s == d) return true;
    else{
        bool f = false;
        for(auto m : adj[s]){
            if(!v[m])
            f = dfs(m,d);
            if(f) break;
        }
        return f;
    }
}

int main()
{
	fast_io;
    int e,n;
    cin >> n;
    FOR(i,n) { int f; cin >>f; adj[f] = vector<int>(); v[f] = false; }
    cin >> e;
    FOR(i,e) {
        int a,b;
        cin >> a >> b; 
        adj[a-1].pb(b-1); 
    }
    int x,y;
    cin >> x >> y;
    cout << dfs(x-1,y-1) << "\n";
}