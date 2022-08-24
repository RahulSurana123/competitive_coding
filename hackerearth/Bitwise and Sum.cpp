


/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are given an array A consisting of N positive integers. Here, f(i,j) is defined as the bitwise AND of all elements of the array A 
after replacing all elements of A in range [i, j] (both inclusive) with (2^25 - 1). Your task is to find:
                                                           
                            -f(1,N) + ∑ [i -> (1,n)]  ∑ [j -> (1,n)] f(i,j)  

Note that after calculating the value f(i,j) for some (i,j) , the array is restored back to its original form. Therefore, calculating f(i,j) for each (i,j) pair is independent.

You are given T test cases.

Warning: Use FAST I/O Methods.

Input format:

The first line contains a single integer T denoting number of test cases.
For each test case:
The first line contains a single integer N denoting the length of the array.
The second line contains N space-separated integers denoting the integer array A.

Output format:

For each test case, print the required sum in a separate line.


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

int pre[500002],suf[500002],ar[500002];

int main()
{
    fast_io;
    int t;
    cin >> t;
    mem(ar, ((1<<25) - 1));
    while(t--) {
        int n;
        cin >> n;
        ar[0] = ar[n+1] = pre[0] = pre[n+1] = suf[0] = suf[n+1] = ((1<<25) - 1);
        FOR(i,n) { cin >>ar[i+1];}
        pre[1] = ar[1];
        FOR(i,n-1) { pre[i+2] = pre[i+1]&ar[i+2]; }
        suf[n] = ar[n];
        for(int i = n-1; i >= 1; i--) { suf[i] = suf[i+1]&ar[i]; }
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j++){
                if(i-1 == 0 && j+1 == n+1) continue;
                ans+= pre[i-1] & suf[j+1];
                // cout << i-1 << " " << j+1 << " " << (pre[i-1] & suf[j+1]) <<" \n";
            }   
        }

        cout << ans <<"\n";

    }
}