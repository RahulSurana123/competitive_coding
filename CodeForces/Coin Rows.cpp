

/* 
    Solution by Rahul Surana
    
    ***********************************************************





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


// int coin(int i, int m){
//     if(i >= m) return 0;
//     return max(coin(i+1,m)+ar[0][i],coin(i+1,m)+ar[1][i]);
// }

int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--) {
        int m;
        cin >> m;

        vector<vector<int>> ar(2,vector<int>(m,0));
        
        FOR(i,m) { cin >> ar[0][i]; }
        FOR(i,m) { cin >> ar[1][i]; }
        if(m == 1) { cout << "0\n"; continue; }
        vector<vector<int>> dp(2,vector<int>(m,0));
        dp[0][0] = ar[0][0];
        dp[1][m-1] = ar[1][m-1];
        FOR(i,m-1) { dp[0][i+1] = dp[0][i] + ar[0][i+1]; }
        for(int i = m-1;i>0;i--) { dp[1][i-1] = dp[1][i]+ar[1][i-1]; }
        
        // FOR(i,2) { FOR(j,m) cout << dp[i][j] <<" "; cout << "\n"; }
            int ans = INT_MAX;
            for(int i = 0; i < m; i++){
                if(i==0){
                    ans = min(ans,dp[0][m-1]-dp[0][i]);
                }
                else if(i == m-1) ans = min(ans,dp[1][0]-dp[1][i]);
                else{
                ans = min(ans,max(dp[1][0]-dp[1][i],dp[0][m-1]-dp[0][i]));}
            }
            cout << ans << "\n";
    }
}