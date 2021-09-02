


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

int pre[500002],suf[500002],ar[500002];
vector<vector<int>> ps;

int main()
{
	fast_io;
    int t;
    cin >> t;
    // mem(ar, ((1<<25) - 1));
    while(t--) {
        int n;
        cin >> n;
        FOR(i,n) { cin >>ar[i+1];}
        ll ans = 0;
        
        pre[1] = ar[1];
        FOR(i,n-1) { pre[i+2] = pre[i+1]&ar[i+2]; }
        suf[n] = ar[n];
        for(int i = n-1; i >= 1; i--) { suf[i] = suf[i+1]&ar[i]; }
        ps.resize(n+2,vector<int>(n+2,0));
        ps[1][1] = ar[1];
        for(int i = 1; i <= n; i++){
            int v = (1<<25) -1;
            for(int j = i; j <= n; j++){
                ps[i][j]= (ar[i] &v);
                v = (ar[i] &v);
                ans += ps[i][j];
            }
        }
        FOR(i,n){
        FOR(j,n) cout << ps[i+1][j+1] <<" ";
        cout <<"\n";}
        // ll ans = 0;
        // for(int i = 1; i <= n; i++){
        //     for(int j = i; j <= n; j++){
        //         if(i-1 == 0 && j+1 == n+1) continue;
        //         ans+= pre[i-1] & suf[j+1];
        //         // cout << i-1 << " " << j+1 << " " << (pre[i-1] & suf[j+1]) <<" \n";
        //     }   
        // }

        cout << ans <<"\n";

    }
}