

/* 

    Solution by Rahul Surana

    ***********************************************************

Chef started solving a lot of mathematics problems during the lockdown period.

He was recently trying a problem related to square numbers but couldn't solve it, so needs your help.

He has a positive number N, he wants to find out the smallest perfect square X which when added to N yields another perfect square number.

Input:

First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, the integer N.

Output:

For each testcase, output in a single line containing the number X. If no such number exists, print −1.



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


bool perfectSquare(ll a){
    return ceil(sqrt((double) a)) == floor(sqrt((double) a));
}


int main()
{
    fast_io;

    int t;
    cin >> t;
    
    while(t--) {

        ll n;
        cin >> n;
        
        ll minsquare = LONG_MAX;
        for (int i = 1; i*i < n; i++ ){
            if(n%i) continue;
            ll b = n/i;
            ll x = (b-i)/2;
            if((b+i)%2) continue;
            minsquare = min(minsquare, x*x);
        }
        if(minsquare == LONG_MAX) cout << -1 << "\n";
        else cout << minsquare << "\n";
        
    }
} 