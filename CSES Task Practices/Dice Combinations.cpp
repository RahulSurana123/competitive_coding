
/* 

    Solution by Rahul Surana

    ***********************************************************

Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and 6.

For example, if n=3, there are 4 ways:
1+1+1
1+2
2+1
3
Input

The only input line has an integer n.

Output

Print the number of ways modulo 109+7.



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
#define trace(x)    cerr<<#x<<" : "<<x<<endl;
#define trace2(x,y) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<" | "<<#z<<" : "<<z<<endl;
#define fast_io 	std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;

int MOD=1e9+7;

vector<ll> dp;

ll df(ll s, ll n){
    if(s > n) return 0;
    if(s==n) return 1;
    if(dp[s] != -1) return dp[s]%MOD;
    cout << s <<" ";
    ll ans = 0;
    for(int i = 1; i <= 6; i++){
        ans = (ans%MOD + df(s+i,n)%MOD)%MOD;   
    }
    return dp[s] = ans%MOD;
}


int main() {
	fast_io;
    int t=1,w = 1;
    // cin >> t;
    while(t >= (w)){
        ll n;
        cin >> n;
        dp.resize(n+1,0);
        dp[1] = 1;
        dp[0] = 1;
        // for(int i = 1; i < 7; i++) dp[i] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <=6; j++){
                if(i-j >= 0)
                dp[i] = (dp[i]%MOD + dp[i-j]%MOD)%MOD;
            }
            // cout << dp[i] <<" ";
        }
        cout << dp[n]%MOD <<"\n";
        // cout << "Case #" << w << ": " << ans <<"\n";
        w++;
    }
}
