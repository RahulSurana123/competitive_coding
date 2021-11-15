#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int ar[200001];
vector<int> dp;

int tfs(int i, int n, int m, int s,vector<int> takens){
    if(i>=n) return 0;
    if(dp[i] != -1) return dp[i];
    vector<int> x(takens.begin(),takens.end());
    int k = s;
    if(x.size()>m) k-=x[0];
    x.erase(x.begin());
    x.push_back(ar[i]);
    int a = tfs(i+1,n,m,k+ar[i],x);
    if(s < ar[i]) return a;
    int b = tfs(i+1,n,m,s,takens);
    int ans = min(a,b);
    return dp[i]=ans;
}

int main() {

    int t ;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n>>m;
        dp.resize(n,-1);
        for(int i = 0; i < n ; i++){
            cin >> ar[i];
        }
        int ans = tfs(0,n,m,0,{}); 
        if(ans > INT_MAX-10000) cout<<-1<<"\n";
        else cout << ans <<"\n";
    }

    return 0;
}
