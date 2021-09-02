


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
#define MOD 1000000007 

using namespace std;

ll fact[10007];

ll pow(ll a,ll b){
    ll ans = 1;
    while(b>0){
        if(b&1) ans = (ans%MOD *a%MOD)%MOD;
        a = (a%MOD * a%MOD)%MOD;
        b = b >> 1;
    }
    return ans;
}

void seieve_of_eratosthenese(){
    for(int i = 1; i < 1000000000; i++){
        for(int j = 2; j < )
    }
}

int main()
{
	fast_io;
    // seieve_of_eratosthenese();
    int t;
    cin >> t;
    while(t--) {
        ll n,m;
        cin >> n >> m;
        ll ans = 1;
        for(ll i = 2; i < n; i++){
            ans += ((pow(i,m)%MOD * 1) % MOD);
        }
        cout << ans << "\n";
    }
}