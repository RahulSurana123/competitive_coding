

/* 

    Solution by Rahul Surana

    ***********************************************************

Chef is a very lazy person. Whatever work is supposed to be finished in x units of time, he finishes it in m∗x units of time. 
But there is always a limit to laziness, so he delays the work by at max d units of time. 
Given x,m,d, find the maximum time taken by Chef to complete the work.

Input:

First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains a single line of input, three integers x,m,d.

Output:

For each testcase, output in a single line answer to the problem.


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

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    fast_io;
    
    int t;
    cin >> t;
    
    while(t--) {

        ll x,m,d;
        cin >> x >> m >> d;
        ll ans  = x*m;
        if(x+d < ans) ans  = x+d;
        cout << ans << "\n";

    }
} 