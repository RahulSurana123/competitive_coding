#include<iostream>
#include<vector>
#include <string>
//#include<bits/stdc++.h>
#include<stack>
#include<set>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
#define int long long
#define endl "\n"
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define read(v,n) for(int i=0;i<n;++i) cin>>v[i];
#define IOF ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define N 10000006
using namespace std;

void solution() {
    int n, k;
    cin >> n >> k; 
    map<int,int> mp;
    vector<int> v(n),st;
    rep(i, 0, n - 1) {
        cin >> v[i];
        mp[v[i]]++;
        if (mp[v[i]] == 1) st.push_back(v[i]);
    }
   // for (auto i : mp) cout << i.first << " " << i.second << endl;
    k = min(k, 1050LL);
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    
    
    int sz = (int)mp.size();
   
    for (int j = 0; j <= sz; ++j) dp[j][0] = 1;
    rep(i, 1, sz) {
        rep(j, 1, k) {
            dp[i][j] = dp[i - 1][j]%mod + dp[i - 1][j - 1] * mp[st[i - 1]]%mod;
            dp[i][j] %= mod;
        }
    }
    
    rep(i, 1, sz) {
        rep(j, 1, k) {
            cout << dp[i][j] << " ";
        }
        cout <<"\n";
    }

    // int ans = 0;
    // rep(j, 0, k) {
    //     ans+=dp[sz][j];
    //     ans%=mod;
    // }
    // cout << ans%mod<<"\n";
    
}

int32_t main() {

    IOF
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; ++i) {
        solution();
    }
}




