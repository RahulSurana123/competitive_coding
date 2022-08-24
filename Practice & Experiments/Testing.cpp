
/* 

    Solution by Rahul Surana

    ***********************************************************

This is Testing Workspace to learn and know about something new 

    1. euclidean gcd
    2. fast exponention  

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
#define trace(x)    cerr<<#x<<" : "<<x<<endl;
#define trace2(x,y) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<" | "<<#z<<" : "<<z<<endl;
#define fast_io 	std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;
int inf=1e9+7, MOD=1e9+7;

vector<vector<int>> adj;
vector<int> v;


ll int gcd(ll int a,ll int b){
    if (b==0) return a;
    return gcd(b,a%b);
}

ll int fastexpo(int x,int n){
    if (n == 0) return 1;
    ll int result = fastexpo(x,n/2);
    if (n%2==1){
         
        return result * x * result ;
    }
    else return result * result;
}

bool dfs(int u, int p){
    if(v[u]) return true;
    v[u]=1;
    bool f = false;
    for(auto x: adj[u]){
        if(!v[x] && x!=p) { f = dfs(x,u); if(f) break; }
    }
    v[u]=0;
    return f;
}


int main()
{
	fast_io;
    // ll int result = gcd(865480988334076944, 181153058753871872);

    // cout << yo <<"\n";
    // cout << fastexpo(18,6)<<"\n";

    for(int i = 0; i < 1024; i++){
        
        cout << (i & -i) <<"\n";
    }
    // FOR(i,n){
    //     int a,b;
    //     cin >>a>>b;
    //     adj[a].pb(b);
    //     adj[b].pb(a);
    // }
    // dfs(0,-1);

}