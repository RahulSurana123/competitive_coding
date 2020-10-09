
/* 

    Solution by Rahul Surana

    ***********************************************************

You have been given an undirected graph consisting of N nodes and M edges. 
This graph can consist of self-loops as well as multiple edges. 
In addition , you have also been given Q queries. 
For each query , you shall be given 2 integers A and B. 
You just need to find if there exists an edge between node A and node B. 
If yes, print "YES" (without quotes) else , print "NO"(without quotes).

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

int main()
{
	fast_io;
    
    int n,m;
    cin >> n >> m;
    vi adj[n+1];
    
    for(int i = 0; i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int q;
    cin >> q;
    
    for(int i = 1; i <= q; i++)
    {
        int a,b;
        cin >> a >> b;
        vector<int>::iterator it = find(adj[a].begin(),adj[a].end(),b);
        if (it != adj[a].end()) cout << "YES" << "\n";
        else cout << "NO"<< "\n";    
    }
}