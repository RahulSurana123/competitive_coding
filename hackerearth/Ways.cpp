
/* 

    Solution by Rahul Surana

    ***********************************************************

Amit and his wife Shweta are in Singapore for their honeymoon. 
Shweta wants to visit every hotel present there. 
Amit and Shweta are in their hotel and Amit is planning out how can he fulfill Shweta’s wish.


There are N hotels there(they are staying at the hotel No. 1). 
There are exactly M roads connecting those hotels (It is guaranteed that any hotel can be visited from any other by roads). 
Each road has its length. Every day the couple visits exactly one unvisited hotel and come back. 
Amit wants to take the shortest distance to get to any hotel from his hotel(they use the same path to get back to their hotel).


But there is a problem , Singapore government has announced that 
the tourists have to choose N-1 roads to move in the city 
i.e Amit has to choose total N-1 roads such that they can visit all the other hotels. 
Also path taken to reach any other hotel from their hotel should be the shortest. 
So in how many ways can Amit choose such N-1 roads.

    ***********************************************************
*/

#include "bits/stdc++.h" 
using namespace std; 
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define mod 1e9 + 7 
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++) 
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++) 
// #define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--) 
#define INF 1000000000000000003 
#define ll          long long
typedef vector<int> vi;
typedef vector<pair<int, int>> vp; 
typedef pair<int, int> pi; 
#define F first 
#define S second 
#define pb push_back 
#define POB pop_back 
#define MP make_pair 
#define trace(x)    cout<<#x<<" : "<<x<<endl;
#define trace2(x,y) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<" | "<<#z<<" : "<<z<<endl;


int MOD = 1e9+7, inf=1e9+7;

int main() 
{ 
    std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    int T; 
    cin >> T; 
    while (T--) 
    { 
        int n,m; 
        cin >> n >> m; 
        vector<vector<pi>> adj(n+1);
		
		vi c(n+1,1),dist(n+1,inf);
        
        for(int i=0;i<m;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			adj[a].pb({c,b});
			adj[b].pb({c,a});
		}
        
        priority_queue<pi> pq;
		
		pq.push({0,1});
		dist[1]=0;
		vi v(n+1,0);
        
        while(!pq.empty())
        {   
            pi temp = pq.top();
            pq.pop();
            
            int d = temp.F, u = temp.S;
            d*=-1;
            
            if (v[u]) continue;
            
            v[u] = 1;
            
            for (auto i : adj[u])
            {
                if(dist[i.S]==dist[u]+i.F)	c[i.S]++;
				
				if(dist[i.S]>dist[u]+i.F)	c[i.S]=1,	dist[i.S]=dist[u]+i.F,	pq.push({-dist[i.S],i.S});
				
            }
        }
        
        ll ans=1;
        
        FOR(i,n) 
        {
            // cout << i+1 <<" " << dist[i+1]<<endl;
            ans = (ans*c[i+1])%MOD;
        }
        
        cout << ans << endl;
    } 
    return 0; 
} 
