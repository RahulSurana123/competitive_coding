
/* 

    Solution by Rahul Surana

    ***********************************************************

You know that an array has n integers between 1 and  m, 
and the absolute difference between two adjacent values is at most 1.
Given a description of the array where some values may be unknown, 
your task is to count the number of arrays that match the description.

Input
The first input line has two integers n and m: the array size and the upper bound for each value.
The next line has n integers x_1, x_2, ..., x_n: the contents of the array. 
Value 0 denotes an unknown value.

Output
Print one integer: the number of arrays modulo 10^9+7.


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

#define MOD 1000000007

// #define TIME
#ifdef TIME
#include <chrono>
using namespace std::chrono;
#endif
using namespace std;

int main() {
	fast_io;
#ifdef TIME
    auto start = high_resolution_clock::now();
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    vector<int> p(n);
    FOR(i,n){
        cin >> p[i];
    }

    if(p[0] == 0){
        for(int i = 1; i <= m; i++) dp[0][i] = 1;
    }
    else dp[0][p[0]] = 1; 

    for(int i = 1; i < n; i++){
        if(p[i] != 0){
            dp[i][p[i]] = dp[i-1][p[i]]%MOD;
            if(p[i] > 1) dp[i][p[i]] = (dp[i][p[i]]%MOD + dp[i-1][p[i]-1]%MOD)%MOD;
            if(p[i] < m ) dp[i][p[i]] = (dp[i][p[i]] %MOD + dp[i-1][p[i]+1]%MOD)%MOD;
        }
        else{
            for(int j = 1; j <= m; j++){
                dp[i][j] = (dp[i][j]%MOD + dp[i-1][j]%MOD)%MOD;
                if(j > 1) dp[i][j] = ( dp[i][j]%MOD + dp[i-1][j-1]%MOD)%MOD;
                if(j < m) dp[i][j] = ( dp[i][j]%MOD + dp[i-1][j+1]%MOD)%MOD;
            }
        }
    }
    int ans = 0;
    
    if(p[n-1] == 0){
        for(int j = 1; j <= m; j++){
            ans = (ans%MOD + dp[n-1][j]%MOD)%MOD; 
        }
    }
    else ans = dp[n-1][p[n-1]]%MOD;

    cout << ans <<"\n";
#ifdef TIME
    cout << (duration_cast<milliseconds>(high_resolution_clock::now() - start).count()) <<"ms\n";
#endif
}
