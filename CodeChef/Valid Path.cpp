
/* 

    Solution by Rahul Surana

    ***********************************************************


You are given a tree with N nodes numbered from 1 to N. 
A set S of nodes is called valid if there exist two vertices u and v (possibly, u=v) such that every node in S lies on the simple path from u to v.

Count the number of valid sets modulo 109+7. 
Two sets are different if one node is included in one set and not in the other. 
If there are multiple pairs (u,v) making a set valid, that set is still only counted once.

Input

The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains N lines of input.
The first line contains a single integer N, the number of tree nodes.
Each of the next N−1 lines contains two space-separated integers u and v representing an edge between nodes u and v.


Output

For each test case, output in a single line the number of valid sets modulo 109+7.


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
#define MOD 1000000007 
using namespace std;


int size[100000];
vector<vector<int>> adj(100000);
int ans;
bool v[100000];

int determine_size(int s,int p){
    int c = 0;
    for(auto u : adj[s]) {
    	if(u !=p) c+= determine_size(u,s);
    }
    size[s] = c + 1;
    return size[s];
}

void dfs(int s,int p,int pc){
	v[s] = true;
	pc++;
	int c = 0;
	for(auto x : adj[s]){
		if(x != p) { 
			
			cout << s+1 << " -> " << x+1 << " " << ans <<" \n"; 
			
			if(!v[x]) { c+=pc; dfs(x,s,c); } 
			 	 
		}
	}
	ans+=c;
	// cout << c << "\n";
}

int sop(vector<int> x){
	int c = 0;
	for(int i = 0; i < x.size(); i++)
		for(int j = i+1; j < x.size();j++) c+= (x[i]%MOD*x[j]%MOD)%MOD;
	return 2*c;
}

void answer(int s){
	vector<int> c;
	if(v[s]) return;
	v[s] = true;
	for(auto x : adj[s]){
		if(!v[x]) { c.pb(size[x]); }
	}
	cout << "*********" << s <<" " << size[s] << "***********\n";
	FOR(i,c.size()) cout << c[i] <<" ";
    cout << "\n";
	ans= (ans%MOD + size[s]%MOD)%MOD;
	cout << "s  "<<ans << "\n";
	ans = (ans %MOD + sop(c)%MOD) %MOD;

	cout << "sop  "<<ans << "\n";
}

int main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        FOR(i,100000) { adj[i].clear(); v[i] = false; size[i] = 0; }
        ans = 0;
        for(int i = 0; i < n-1; i++) { 
            int u,v; 
            cin >> u >> v;
            u--;
            v--; 
            adj[u].pb(v);
            adj[v].pb(u);
        }
         determine_size(0,0);
         FOR(i,n) cout << size[i] <<" ";
         cout << "\n";

        FOR(i,n) answer(i);
        // for(int i = 0; i < n; i++) { for(int j = i; j < n-i; j++) v[j] = false; cout << "******" << i <<"*****\n"; dfs(i,0,0); ans++; }

        cout << ans << "\n";
    }
}