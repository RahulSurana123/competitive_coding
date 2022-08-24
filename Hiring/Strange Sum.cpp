

/*


    Solution by Rahul Surana

    ***********************************************************

    You are given N find all pair of no from 1 to N ,
    which has bitwise and equals to 0 and print sum of product of those pair no

    Input format

    The first line contains an integer T denoting the number of test cases.
    The first line of each test case contains an integer N.

    Output format

    For each test case, print the sum of product of pairs.

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
#define MOD         1000000007
 
using namespace std;


inline ll mult(ll a,ll b){
    return (a%MOD * b%MOD )%MOD;
}

inline ll square_sum(ll N) {
    return ((N%MOD * (N-1)%MOD)/2)%MOD;
}

ll sop_for_po2(ll v){
    return mult(square_sum(v),v);
}

ll sop_for_npo2(ll v) {
    vl a;
    int c = 1;
    while(v > 0) { if(!(v&1)) a.pb(c); v = v >> 1; c++; }
    ll sum = 0;
    for(int i = 0; i < a.size(); i++) {
        sum += mult(a[i],a.size());
    }
    return sum;
}

int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--) {
        
        ll n;
        cin >> n;
        ll x = n;
        int ans = 0;

        for(ll i = 1; i <= n; i++) {
            if(!(i&(i-1))) {
                ans = (ans + sop_for_po2(i)) %MOD ;
            }
            else {
                ans += mult(sop_for_npo2(i),i);
            }
        }
        cout << ans << "\n";
    }
}
