

/* 

    Solution by Rahul Surana

    ***********************************************************

The Fibonacci sequence F0,F1,… is a special infinite sequence of non-negative integers, where F0=0, F1=1 and for each integer n≥2, Fn=Fn−1+Fn−2.

Consider the sequence D of the last decimal digits of the first N Fibonacci numbers, i.e. D=(F0%10,F1%10,…,FN−1%10). 
Now, you should perform the following process:

Let D=(D1,D2,…,Dl).
If l=1, the process ends.
Create a new sequence E=(D2,D4,…,D2⌊l/2⌋). In other words, E is the sequence created by removing all odd-indexed elements from D.
Change D to E.
When this process terminates, the sequence D contains only one number. You have to find this number.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single integer N.

Output

For each test case, print a single line containing one integer ― the last remaining number.


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


// ll pow(ll a){
//     ll b = 2;
//     ll ans = 1;
//     while(a>0){
//         if(a&1) ans = ans*b;
//         b*=b;
//         a>>=1; 
//     }
//     return ans;
// }

ll ar[60];

int main()
{
    fast_io;
    ar[0] = 0;
    ar[1] = 1;
    for(ll i = 2; i < 60; i++){
        ar[i] = (ar[i-2]+ar[i-1])%10;
    }
    // FOR(i,60) cout << ar[i]<<" ";

    ll t;
    cin >> t;
    
    while(t--) {

        ll n;
        cin >> n;
        ll pos = 0;
        while(n>>=1) pos++;
        ll c = floor(log2(n));
        ll x = ((ll)pow(2,pos)-1)%60;
        cout << ar[x] << "\n";

    }
} 