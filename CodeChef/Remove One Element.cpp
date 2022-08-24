


/* 
    Solution by Rahul Surana
    
    ***********************************************************


Alice has an array A consisting of N distinct integers. Bob takes exactly N−1 elements from this array and adds a positive integer X (i.e. X>0) 
to each of these numbers and then shuffles them to form a new array B of length N−1.

You are given both arrays A and B. You have to identify the value of X chosen by Bob. If there are multiple possible values of X, print the smallest of them. 
It is guaranteed that for the given input, there exists at least one possible value of X.

Note: Since the input is large, prefer using fast input methods.

Input Format:

The first line of input contains a single integer T denoting the number of test cases. The description of T test cases follows.
Each test case contains 3 lines of input.
The first line contains an integer N - the length of array A.
The second line contains N space-separated integers A1,A2,…,AN, denoting the array A.
The third line contains N−1 space-separated integers B1,B2,…,BN−1, denoting the array B.

Output Format:

For each test case, output the value of X chosen by Bob. In case there are multiple possible values of X, print the smallest of them.



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

vector<int> a, b;

int main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        a.resize(n);
        b.resize(n-1);
        FOR(i,n) cin >> a[i];
        FOR(i,n-1) cin >> b[i];
        sort(a.begin(),a.end(), greater<int>());
        sort(b.begin(),b.end(), greater<int>());
        int d = b[0] - a[0];
        int ans = 0;
        if(d <= 0)  {  ans = b[0]-a[1]; }
        else{
            
        if(n <= 2) {
            if(a[0] > b[0])  ans = b[0] - a[1]; 
            else if(a[1]>b[0]) ans = b[0] - a[0]; 
            else ans = b[0] - max(a[0],a[1]);
            }
            else {
            if(d != b[1] - a[1] && d == b[1]-a[2]) {
                ans = d;
            }
            else if(d != b[1] - a[1] && b[1] - a[2] == b[0] - a[1]) ans = b[0] - a[1];
            else if(d == b[1] - a[1]) ans = d;
            }
        }
        // else {
        //     FOR(i,n-1){ 
        //         if(d == b[i] - a[j]) { ans = d; break; }
        //         d = b[i+1] -a[j-1];
        //         j++;
        //         // trace(d);
        //     }
        // }
        cout << ans << "\n";

    }
}
