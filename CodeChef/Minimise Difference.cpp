

/*

Solution by Rahul Surana

    ***********************************************************


You're given a simple undirected graph G with N vertices and M edges. You have to assign, to each vertex i, a number Ci such that 1≤Ci≤N and ∀i≠j,Ci≠Cj.

For any such assignment, we define Di to be the number of neighbours j of i such that Cj<Ci.

You want to minimise maxi∈{1..N}Di−mini∈{1..N}Di.

Output the minimum possible value of this expression for a valid assignment as described above, and also print the corresponding assignment.

Note:
The given graph need not be connected.
If there are multiple possible assignments, output anyone.
Since the input is large, prefer using fast input-output methods.

Input Format:

First line will contain T, number of testcases. Then the testcases follow.
The first line of each test case contains two integers N,M - the number of vertices and edges in the graph respectively.
The next M lines each contain two integers - X,Y, denoting that there exists an edge between vertex X and vertex Y.

Output Format:

The output of each test case consists of two lines:
The first line contains the minimum possible value of the expression described above.
The second line contains N space separated integers - the ith of which is Ci in the corresponding assignment.


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

vector<vector<int>> adj;
vector<int> c;

bool compare(int a, int b){
    // if(adj[c[a]].size() == adj[c[b]].size()) return c[a]<c[b];
    return adj[c[a]].size() >= adj[c[b]].size();
}


int main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n,e;
        cin >> n>>e;
        adj.clear();
        adj.resize(n,vector<int>());
        c.clear();
        c.resize(n);
        FOR(i,n) { c[i] = i; }
        FOR(i,e) {
            int a,b;
            cin >> a >> b; 
            adj[a-1].pb(b-1);
            adj[b-1].pb(a-1); 
        }

        // FOR(i,n) cout << adj[i].size() << " ";
        // cout <<"\n";
        sort(c.begin(),c.end(),compare);
        // FOR(i,n) cout << c[i]+1 << " ";
        // cout << "\n";
        int ans = 0;
        // ans += ((ans/t)*t);
        for(int i = 0; i < n;i++){
            int k = 0;
            // cout << i <<" -> ";
            for(int j = 0; j < adj[i].size();j++){
                if(c[adj[i][j]] < c[i]){
                    k++;
                }   

                // cout << adj[i][j] <<" ";
            }
            ans = max(ans,k);
            // cout <<"\n";
        } 
        cout << ans << "\n";

        FOR(i,n) cout << c[i]+1 << " ";
        // for(auto x: path){
        //     cout << x <<" ";
        // }
        cout << "\n";
    }
}