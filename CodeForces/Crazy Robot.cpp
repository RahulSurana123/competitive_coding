

/* 
    Solution by Rahul Surana
    
    ***********************************************************


There is a frog initially placed at the origin of the coordinate plane. In exactly 1 second, the frog can either move up 1 unit, move right 1 unit, or stay still. 
In other words, from position (X,Y), the frog can spend 1 second to move to:

-> (X,Y)
-> (X+1,Y)
-> (X,Y+1)

After T seconds, a villager who sees the frog reports that the frog lies on or inside a square of side-length S with coordinates (X,Y),(X+s,Y) ,(X,Y+S) ,(X+S,Y+S). 
Calculate how many points with integer coordinates on or inside this square could be the frog's position after exactly T seconds

Input Format:

The first and only line of input contains four space-separated integers: X, Y, S, and T.

Output Format:

Print the number of points with integer coordinates that could be the frog's position after T seconds.


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


vector<vector<char>> ar;
vector<vector<int>> v;

void dfs(int i, int j, int n, int m){
    if(i<0 || j < 0 || i >= n || j >=m ) return;
    int c = 0;
    int k = 0;
     if(i > 0) { c+=ar[i-1][j] == '.'; k+=ar[i-1][j] == '#';}
    if(j > 0) {c+=ar[i][j-1] == '.'; k+=ar[i][j-1] == '#';}
    if(i < n-1) {c+=ar[i+1][j] == '.';k+=ar[i+1][j] == '#';}
    if(j < m-1) {c+=ar[i][j+1] == '.';k+=ar[i][j+1] == '#';}
    if(c<=1) ar[i][j] = '+';
    if(c ==k) ar[i][j] = '+';
}

void df(int i, int j, int n, int m){
    if(i<0 || j <0 || i >= n || j >=m || v[i][j]) return;
    v[i][j]=1;
    if(j > 0 && ar[i][j-1] == '.') { dfs(i,j-1,n,m); df(i,j-1,n,m); }
    if(i > 0 && ar[i-1][j] == '.') { dfs(i-1,j,n,m); df(i-1,j,n,m); }
    if(i < n-1 && ar[i+1][j] == '.') { dfs(i+1,j,n,m); df(i+1,j,n,m); }
    if(j < m-1 && ar[i][j+1] == '.') { dfs(i,j+1,n,m); df(i,j+1,n,m); }
    v[i][j] = 0;
}

int main(){
    fast_io;
    int t=1;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        ar.resize(n+1,vector<char>(m+1));
        v.resize(n+1,vector<int>(m+1,0));
        // vector<vector<char>> ans(n,vector<char>(m));
        int x = -1,y=-1; 
        FOR(i,n) FOR(j,m){ cin >> ar[i][j]; if(ar[i][j] == 'L') {x = i; y = j;} }
        if(x!=-1 &&y!=-1)
        df(x,y,n,m);
        // dif[n-1] = pow(10,18);
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m;j++){
                cout << ar[i][j];  
            }   
            cout <<"\n";
        }
    }
}