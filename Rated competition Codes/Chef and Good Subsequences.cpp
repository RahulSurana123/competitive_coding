

/* 

    Solution by Rahul Surana

    ***********************************************************

Chef is given a sequence of prime numbers A1,A2,…,AN. This sequence has exactly 2N subsequences. A subsequence of A is good if it does not contain any two identical numbers; 
in particular, the empty sequence is good.

Chef has to find the number of good subsequences which contain at most K numbers. Since he does not know much about subsequences, help him find the answer. 
This number could be very large, so compute it modulo 1,000,000,007.

Input
The first line of the input contains two space-separated integers N and K.
The second line contains N space-separated integers A1,A2,…,AN.
Output
Print a single line containing one integer ― the number of good subsequences with size at most K, modulo 1,000,000,007.


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

vector<ll> primes;
map<ll , ll> ar;
vector<vector<ll>> dp;

int main()
{
    fast_io;
    
    // int t;
    // cin >> t;
    
    // while(t--) {

    ll n,k; 
    cin >> n >> k; 
    FOR(i,n) { int x; cin >> x; ar[x]++; if(ar[x] == 1) primes.pb(x); }
    ll ans = 0;
    
    k = min(k,1120);
    dp.resize(n+1,vector<ll>(k+1,0));
    FOR(i,ar.size()+1) dp[i][0] = 1;
    
    for(int i = 1; i <= ar.size();i++){
        for(int j = 1; j <= k; j++){
            dp[i][j] = (dp[i-1][j]%MOD + (ar[primes[i-1]]%MOD * dp[i-1][j-1]%MOD))%MOD;
        }
    }
    FOR(i, k+1) ans = (ans%MOD+ dp[ar.size()][i]%MOD)%MOD;
    cout << ans%MOD << "";

}