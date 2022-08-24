

/* 

    Solution by Rahul Surana

    ***********************************************************

For a given N, find the number of ways to choose an integer x from the range [0,2N−1] 
such that x⊕(x+1)=(x+2)⊕(x+3), where ⊕ denotes the bitwise XOR operator.

Since the number of valid x can be large, output it modulo 109+7.

Input

The first line contains an integer T, the number of test cases. Then the test cases follow.
The only line of each test case contains a single integer N.

Output

For each test case, output in a single line the answer to the problem modulo 10^9+7


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
        ll f;
        cin >> f;
        // cout << (16^15)<<" "<<  (18^17) <<"\n";
        
        // FOR(i,100) cout <<i << " ^ " << i+1 << " " << (i^(i+1))<< "\n";
        cout << pow((ll)2,f) <<"\n"; 
    }
}