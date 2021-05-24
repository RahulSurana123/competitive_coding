

/* 

    Solution by Rahul Surana

    ***********************************************************

Chefland is holding a virtual marathon for the categories 10 km, 21 km and 42 km having prizes A,B,C (A<B<C) respectively to promote physical fitness. 
In order to claim the prize in a particular category the person must cover the total distance for that category within D days. 
Also a single person cannot apply in multiple categories.

Given the maximum distance d km that Chef can cover in a single day, find the maximum prize that Chef can win at the end of D days. 
If Chef can't win any prize, print 0.

Input

The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, five integers D,d,A,B,C.

Output

For each test case, output in a single line the answer to the problem.


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


ll pow(ll x,ll a){
    ll res = 1;
    a--;
    while(a>0){
        if(a&1) res = ((x%MOD) * (res%MOD))%MOD;
        x=((x%MOD) * (x%MOD))%MOD ;
        a = a >> 1;
    }
    return res%MOD;
}

int main()
{
    fast_io;
    
    int t;
    cin >> t;
    
    while(t--) {

        ll D,d,a,b,c; 
        cin >> D >> d >> a >> b >> c; 
        ll dist = D *d;
        ll ans = 0;
        if(dist >= 42) ans+=c;
        else if(dist >= 21) ans+=b;
        else if(dist >= 10) ans+=a;
        cout << ans<<"\n";

    }
}