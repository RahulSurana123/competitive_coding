
/* 

    Solution by Rahul Surana

    ***********************************************************

Consider an n×n grid whose squares may have traps. It is not allowed to move to a square with a trap.

Your task is to calculate the number of paths from the upper-left square to the lower-right square. 
You can only move right or down.

Input

The first input line has an integer n: the size of the grid.

After this, there are n lines that describe the grid. 
Each line has n characters: '.' denotes an empty cell, and '*' denotes a trap.

Output

Print the number of paths modulo 109+7
.


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
#define fast_io 	std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;

const int MOD = 1e9+7;

vector<vector<ll>> dp;

ll df(int i, int j, vector<vector<int>> &g, int &n){
    if(i > n -1 || j > n-1 || g[i][j] == 1) return 0;
    if(i == n-1 && j == n-1) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = (df(i+1,j,g,n) + df(i,j+1,g,n))%MOD;
}

int main() {
	fast_io;
    int n;
    cin >> n;
    dp.resize(n,vector<ll>(n,-1));
    vector<vector<int>> grid(n,vector<int>(n,0));
    FOR(i,n){
        FOR(j,n) {
            char val;
            cin >> val;
            if(val == '*') grid[i][j] = 1;
        }
    }
    cout << df(0,0,grid,n) <<"\n";
}
