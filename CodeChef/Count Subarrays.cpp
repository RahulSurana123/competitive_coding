

/* 

    Solution by Rahul Surana

    ***********************************************************

Given an array A1,A2,...,AN, count the number of subarrays of array A which are non-decreasing.
A subarray A[i,j], where 1≤i≤j≤N is a sequence of integers Ai,Ai+1,...,Aj.

A subarray A[i,j] is non-decreasing if Ai≤Ai+1≤Ai+2≤...≤Aj. You have to count the total number of such subarrays.

Input

The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the size of array.
The second line contains N space-separated integers A1, A2, …, AN denoting the elements of the array.

Output

For each test case, output in a single line the required answer.



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


ll ar[100001];

int main()
{
    fast_io;

    int t;
    cin >> t;
    
    while(t--) {

        ll n;
        cin >> n;
        
        FOR(i,n) cin >> ar[i];
        vl c;
        ll ans = n;
        ll count = 1;
        for (int i = 1; i < n; i++ ){
            if(ar[i-1] <= ar[i]) count++;
            else c.pb(count), count = 1; 
        }
        if(count>1) c.pb(count);

        FOR(i,c.size()) if(c[i] != 1) ans += ((c[i] * (c[i]-1)) /2);
        cout << ans << "\n";
        
    }
} 