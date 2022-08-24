

/* 
    Solution by Rahul Surana
    
    ***********************************************************

    Not Complete Yet


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

int ar[401][401];

int df(int i,int j){
    int ans = 0;
    for(int x = i; x < i+4;x++) if(ar[x][j] == 0) ans++;

    // cout << ans <<" ";
    for(int x = i+1; x < i+5;x++) if(ar[x][j+3] == 0) ans++;
    
    // cout << ans <<" ";
    for(int x = j+1; x < j+3;x++) if(ar[i][x] == 0) ans++;
    // cout << ans <<" ";
    for(int x = j+1; x < j+3;x++) if(ar[i+4][x] == 0) ans++;
    // cout << ans <<" ";
    for(int x = i+1; x < i+4;x++) {
        for(int y = j+1; y < j+3;y++) {
            if(ar[x][y] == 1) ans++;
        }
    }
    // cout << ans <<" ";
    return ans;
}

int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        FOR(i,n){
            string s;
            cin >> s;
            for(int j = 0; j < s.length(); j++){
                ar[i][j] = (s[j] == '0')? 0:1; 
            }
        }
        // for(int i = 0; i < n;i++){
        //    for(int j = 0; j < m;j++){
        //         cout << ar[i][j] <<" ";
        //     }
        //     cout << "\n";
        // }
        int ans = INT_MAX;
        for(int i = 0; i <= n-5;i++){
           for(int j = 0; j <= m-4;j++){
                ans = min(ans,df(i,j));
            }
        }
        
        cout << ans << "\n";

    }
}
