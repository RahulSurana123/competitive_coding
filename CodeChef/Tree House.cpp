

/* 

    Solution by Rahul Surana

    ***********************************************************

There is a large tree house in an unknown world. It is ruled by the great emperor KZS. 
It consists of N nodes numbered from 1 to N in which the people of that world reside. 
The nodes are organized in a tree structure rooted at node 1. 
You need to assign values to the nodes according to the wishes of emperor KZS which are as follows :-

-> The value of node 1 is X.
-> All immediate children of any node have pairwise distinct values.
-> For every node with at least one immediate child, the gcd of the values of all immediate children is equal to the value of the node.
-> The total sum of the values of all nodes should be minimum.
-> The greatest common divisor gcd(a,b) of two positive integers a and b is equal to the largest integer d such that both integers a and b are divisible by d.

Print the sum of all values, modulo 10^9+7.

Input

The first line contains an integer T, the number of test cases. T testcases follow.
The first line of each test contains two integers N and X.
Each of the following N−1 lines contains two integers u and v, denoting an edge between nodes u and v.

Output

For each test case, print the sum of values, modulo 109+7.


    ***********************************************************
*/


// Most correct solution will start from bottom of tree to the top


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

ll MOD = 1e9+7; 

vector<vector<int>> adj(300000);
int size[300000];
int len[300000];
ll ar[300000];

int determine_size(int s,int p){
    int c = 0;
    for(auto u : adj[s]) {
        if(u!=p)
        c+= determine_size(u,s);
    }
    size[s] = c + 1;
    return size[s];
}

int len_find(int s, int p){
    int k = 0;
    for(auto x : adj[s]){
        if(x!=p) k = max(k,len_find(x,s));
    }
    len[s] = k+1;
    return len[s];
}

bool compare(int a,int b){
    return size[a] > size[b];
}

void assign_value(int s,int p) {
    sort(adj[s].begin(),adj[s].end(),compare);
    ll k = 1;
    for(auto x : adj[s]) {
        if(x!=p) {
            ar[x] = (k%MOD*ar[s]%MOD)%MOD;
            k++;
            assign_value(x,s);
        }
        // cout << s << " " << adj[s][i] <<" "<<size[adj[s][i]] <<" " << len[adj[s][i]]<< " " << ar[adj[s][i]] <<"\n";
    }    
}

int main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--) {
        ll n , x;
        cin >> n >> x;
        FOR(i,300000) { size[i] = 0; len[i] = 0; ar[i] = 0; adj[i].clear();}
        ar[0] = x%MOD;
        for(int i = 0; i < n-1; i++) { 
            int u,v; 
            cin >> u >> v;
            u--;
            v--; 
            adj[u].pb(v); 
            adj[v].pb(u);
            // cout << u << " with size: "<<adj[u].size()<<" -> "; for(auto m : adj[u]) cout << m <<" -> "; cout << "\n"; 
        }
        determine_size(0,0);
        len_find(0,0);
        // for(int i = 1;i <=n;i++) { cout << i << " with size: "<<size[i]<<" -> "; for(auto m : adj[i]) cout << m << " -> ";  cout << "\n";}
        
        // for(int i = 1;i <=n;i++) { cout << i << " -> "; for(auto x : adj[i]) cout << x << " -> ";  cout << "\n";}         
        assign_value(0,0);
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ans = (ans%MOD + ar[i]%MOD)%MOD;
        }
        cout << (ans%MOD) << "\n";
    }   
}