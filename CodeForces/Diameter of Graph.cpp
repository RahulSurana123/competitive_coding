

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


int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--) {
        ll n,m,k;
        cin >> n >> m >> k;
        k-=2;
        if(m < n-1 || k < 0) { cout << "NO\n"; continue; }
        if(m > ((n * (n-1))/2)) { cout << "NO\n"; continue; }
        if(n == 1) { cout << "YES\n"; continue; }
        if(k == 0 ) { cout << "NO\n"; continue; }
        if((n * (n-1)/2) == m) { cout << "YES\n"; continue; }
        else { if(k<=1) cout << "NO\n"; else cout << "YES\n"; }
        
        // ll ans = 0;
        
        // cout << ans << "\n";

    }
}
