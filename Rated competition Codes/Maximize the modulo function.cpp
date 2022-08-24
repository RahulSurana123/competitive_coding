
/* 

    Solution by Rahul Surana

    ***********************************************************

You are given an integer N that is represented in the form of string S of length M. 
You can remove at most 1 digit from the number after removing the rest of the digits that are arranged in the same order.

Example

For N = 2134, if you delete the digit 3, the new number is 214.

You are also given an integer K. Find the maximum possible value of (N mod K) after deleting at most 1 digit from number N.

Input format

The first line contains an integer T denoting the number of test cases.
The first line of each test case contains two space-separated integers M and K.
The second line of each test case contains string S.


Output format

For each test case, print the maximum possible value of the mod function in a new line.


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

ll expo(ll a, ll b,ll k) {
    ll ans = 1;
    while(b>0) {
        if(b&1) ans = (a*ans) % k;
        a = (a%k*a%k)%k;
        b>>=1;
    }
    return ans;
}

int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;

        ll current = 1;
        
        vi suf(n,0);

        for(int i = n - 1; i >= 0; i--) {
            suf[i] = ((s[i] - '0') * current) % k;
            current = (current * 10LL) % k ;
        }
        for(int i = n - 2; i >= 0; i--) suf[i] = (suf[i] + suf[i+1]) % k;
        ll ans = suf[0] %k;

        ll sum = 0;
        for(int i = 0; i < n; i++) {
            ll cur = 0;
            if(i+1 < n) cur = suf[i+1];
            if(i-1>=0) cur = (cur + sum) % k;
            ans = max(cur,ans);
            sum = sum + (s[i] - '0')*expo(10,n-2-i,k);
        }
        cout << ans << "\n";
    }
}
