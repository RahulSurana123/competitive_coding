
/* 

    Solution by Rahul Surana

    ***********************************************************

Consider a money system consisting of n coins. Each coin has a positive integer value. 
Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.

For example, if the coins are {1,5,7} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.

Input

The first input line has two integers n and x: the number of coins and the desired sum of money.

The second line has n distinct integers c1,c2,…,cn: the value of each coin.

Output

Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print −1.



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

int MOD=1e9+7;

vector<vector<ll>> dp;
ll ans = 0;

void df(int i, vector<int> &ar, int x){
    if(i>x) return;
    if(i==x) { ans++; return; }
    for(auto z: ar){
        df(i+z,ar,x);
    }
}

int main() {
	fast_io;
    int t=1,w = 1;
    // cin >> t;
    while(t >= (w)){
        int n,x;
        cin >> n >> x;
        vector<int> ar(n);
        FOR(i,n) cin >> ar[i];
        // dp.resize(n+1,vector<ll>(x+1,0));
        // for(int i = 0; i < n; i++){
        //     dp[1][ar[i]] = 1;
        // }
        // bool f = true;
        // while(f){
        //     bool k = false;
        //     for(int j = 1; j <= x; j++){
        //         for(int i = 0; i < n; i++){
        //             if(j - ar[i] > 0){
        //                 dp[i][j] = 1 + dp[i-1][j-ar[i]];
        //                 k = true;
        //             }
        //         }
        //     }
        //     if(!k) f = false;
        // }
        // ll ans  = 0;
        // for(int i = 0; i < n; i++){ ans += dp[i][x]; }
        df(0,ar,x);
        cout << ans <<"\n";
        w++;
    }
}
