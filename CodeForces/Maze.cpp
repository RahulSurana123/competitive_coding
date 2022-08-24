
/* 

    Solution by Rahul Surana

    ***********************************************************

You are given n integers a1,a2,…,an. Find the maximum value of max(al,al+1,…,ar)⋅min(al,al+1,…,ar) over all pairs (l,r) of integers for which 1≤l<r≤n.

Input:

The first line contains a single integer t (1≤t≤10000)  — the number of test cases.
The first line of each test case contains a single integer n (2≤n≤105).
The second line of each test case contains n integers a1,a2,…,an (1≤ai≤106).
It is guaranteed that the sum of n over all test cases doesn't exceed 3⋅105.

Output:

For each test case, print a single integer  — the maximum possible value of the product from the statement.


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
int inf=1e9+7,MOD=1e9+7;

char ar[501][501];
int v[501][501];

int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

void dfs(int x, int y, int n, int m, int& c){
    if(x < 0 || y < 0 || n <=x || m <= y || v[x][y] || ar[x][y] != '.') return;
    v[x][y] = 1;
    c--;
    if(c == 0) return;
    for(int i = 0; i < 4; i++){
            dfs(x+dx[i],y+dy[i],n,m,c);
            if(c == 0) return;
            // cout << c <<" "<<x<<" " << y <<"\n";
    }
}

int main()
{
	fast_io;
    int t=1;
    // cin >> t;
    while(t--){
    int n,m,k;
    cin >> n >> m >> k;
    int s = 0;
    int a=-1,b=-1;
    FOR(i,n) FOR(j,m) { cin >> ar[i][j]; v[i][j] = 0; if(ar[i][j] == '.') { s++; if(a==-1){a=i; b=j;} } }
    int z = s-k; 
    dfs(a,b,n,m,z);
    // cout << z <<" z ";
    // if(z != 0) {
        
    //     FOR(i,n) FOR(j,m) { v[i][j] = 0; }
    //     z = s-k;
    //     dfs(a,b,n,m,z);
    // }
    FOR(i,n) { FOR(j,m) { if(v[i][j] == 0 && ar[i][j] == '.') { ar[i][j] = 'X';} cout << ar[i][j]; } cout<<"\n";}
        
    }
    
}