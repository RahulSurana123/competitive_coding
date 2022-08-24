

/* 

    Solution by Rahul Surana

    ***********************************************************

Quite recently a creative student Lesha had a lecture on trees. After the lecture Lesha was inspired and came up with the tree of his own which he called a k-tree.

A k-tree is an infinite rooted tree where:

each vertex has exactly k children;
each edge has some weight;
if we look at the edges that goes from some vertex to its children (exactly k edges), then their weights will equal 1, 2, 3, ..., k.
The picture below shows a part of a 3-tree.



As soon as Dima, a good friend of Lesha, found out about the tree, he immediately wondered: "How many paths of total weight n (the sum of all weights of the edges in the path) are there, starting from the root of a k-tree and also containing at least one edge of weight at least d?".
Help Dima find an answer to his question. As the number of ways can be rather large, print it modulo 1000000007 (109 + 7).

Input
A single line contains three space-separated integers: n, k and d (1 ≤ n, k ≤ 100; 1 ≤ d ≤ k).

Output
Print a single integer — the answer to the problem modulo 1000000007 (109 + 7).



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

int dp[200][2];

ll dfs(int n, int k, int d, int s,bool f){
    // cout << s <<"\n";
    if(dp[s][f] != -1) return dp[s][f];
    if(s == n && f) {  return 1; }
    if(s>n) return 0;
    ll ans = 0;
    for(int i = 1; i <= k; i++){
        ans += dfs(n,k,d,s+i,i>=d || f)%MOD;
    }
    return dp[s][f] = ans%MOD;
}


int main()
{
    fast_io;
    // int t;
    // cin >> t;
    // while(t--){
        int n,k,d;
        cin >> n >> k >> d;
        FOR(i,200) FOR(j,2) dp[i][j] = -1;
        ll ans = dfs(n,k,d,0,false); 
        cout << ans%MOD << "\n";

    // }
    
} 