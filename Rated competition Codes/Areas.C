
/* 

    Solution by Rahul Surana

    ***********************************************************

You are given a 2D grid. A '#' represents an obstacle and a '.' represents free space. 
You need to find the areas of the disconnected components. 
The cells (i+1, j), (i, j+1), (i-1, j), (i, j-1) are the adjacent to the cell (i, j).

There are multiple test cases in this problem.

SAMPLE INPUT 
3

3 3
##.
..#
#.#

3 5
#.#.#
.#.#.
#.#.#

SAMPLE OUTPUT 

2
1 3 

7
1 1 1 1 1 1 1 

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
#define FOR(i,a)     for(int i = 0; i < (int)a; i++)
#define trace(x)    cerr<<#x<<" : "<<x<<endl;
#define trace2(x,y) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<" | "<<#z<<" : "<<z<<endl;
#define fast_io 	std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;
int inf=1e9+7,MOD=1e9+7;

vector<pi> adj[100][100];        
int a[100][100];
int v[100][100];

int dfs(int i, int j){
    
    int count=1;
    v[i][j] = 1;
    
    for(pi u : adj[i][j]){
        if(!v[u.F][u.S]){
            count += (dfs(u.F,u.S));
        }
    }
    
    return count;
}

int main()
{
    
    int n,t,m;
	
	fast_io;
    cin>>t;
    
    while(t--){
        cin >> n >> m;
        vi ans;
        
        FOR(i,n){
            FOR(j,m){
                char c;
                cin >> c;
                if (c == '#') a[i][j] = 0;
                else a[i][j] = 1; 
                // cout << a[i][j] <<" ";
            }
            // cout <<"\n";
        }
        
        FOR(i,n){
            FOR(j,m){
                if (a[i][j]){
                    if(i>0 && a[i-1][j]) adj[i][j].pb({i-1,j});
                    if(i<n-1 && a[i+1][j]) adj[i][j].pb({i+1,j});
                    if(j>0 && a[i][j-1]) adj[i][j].pb({i,j-1});
                    if(i<m-1 && a[i][j+1]) adj[i][j].pb({i,j+1}); 
                }  
            }
        }
        

        FOR(i,n){
            FOR(j,m){
                if(!v[i][j] && a[i][j]){
                int k = dfs(i,j);
                // cout << k <<" ";
                if (k>0) ans.pb(k);}  
            }
        }
        cout << ans.size()<<"\n";
        FOR(i,ans.size()) cout << ans[i]<<" ";
        cout<<"\n";

        FOR(i,n){
            FOR(j,m){
                v[i][j]=0;
                a[i][j]=0;
                adj[i][j].clear();
            }
        }
    }
}