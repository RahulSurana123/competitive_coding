

/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are given an array a consisting of n positive integers. You can perform operations on it.

In one operation you can replace any element of the array ai with ⌊ai2⌋, that is, by an integer part of dividing ai by 2 (rounding down).

See if you can apply the operation some number of times (possible 0) to make the array a become a permutation of numbers from 1 to n —that is, so that it contains all numbers from 1 to n, each exactly once.

For example, if a=[1,8,25,2], n=4, then the answer is yes. You could do the following:

Replace 8 with ⌊82⌋=4, then a=[1,4,25,2].
Replace 25 with ⌊252⌋=12, then a=[1,4,12,2].
Replace 12 with ⌊122⌋=6, then a=[1,4,6,2].
Replace 6 with ⌊62⌋=3, then a=[1,4,3,2].
Input
The first line of input data contains an integer t (1≤t≤104) —the number of test cases.

Each test case contains exactly two lines. The first one contains an integer n (1≤n≤50), the second one contains integers a1,a2,…,an (1≤ai≤109).

Output
For each test case, output on a separate line:

YES if you can make the array a become a permutation of numbers from 1 to n,
NO otherwise.
You can output YES and NO in any case (for example, strings yEs, yes, Yes and YES will be recognized as a positive response).



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
 
using namespace std;

int main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> ar(n);
        vector<int> f(n+1);
        // ll x = 0;
        FOR(i,n) { cin >> ar[i]; if(ar[i] < n+1 && f[ar[i]] != 1) { f[ar[i]] = 1; ar[i] = 0; } }
        bool fl = true;
        for(int i = 0; i < n; i++){
            while(ar[i] > n) ar[i] /= 2;
            while(ar[i] != 0 && f[ar[i]] == 1) ar[i] /= 2;
            if(ar[i] != 0 && f[ar[i]] == 0) f[ar[i]] = 1;
        }
        for(int i = 1; i < n+1; i++) if(f[i] == 0) fl= false;

        if(fl) cout << "YES\n";
        else cout << "NO\n";
    }
}
