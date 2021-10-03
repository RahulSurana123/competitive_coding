


/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array of integers A, you need to find the maximum sum that can be obtained by picking some non-empty subset of the array. 
If there are many such non-empty subsets, choose the one with the maximum number of elements. Print the maximum sum and the number of elements in the chosen subset.

Input:

The first line contains an integer N, denoting the number of elements of the array. 
Next line contains N space-separated integers, denoting the elements of the array.

Output:

Print 2 space-separated integers, the maximum sum that can be obtained by choosing some subset 
and the maximum number of elements among all such subsets which have the same maximum sum.



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

ll ar[100001];

// int df(int i, int n,vector<int> x){
//     if(i >= n) return 0;
//     int y = df(i+1,n);
//     x.push_back(ar[i]);
//     int x = df(i+1,n,x)+ar[i];
    
//     if(x>=y) {  return x; }
//     else return y;
// }

int main()
{
	fast_io;
    // int t;
    // cin >> t;
    // while(t--) {
    int n;
    ll c = 0;
    cin >> n;
    ll ans = 0;
    FOR(i,n) cin >> ar[i];
    FOR(i,n) if(ar[i]>=0) { ans+=ar[i]; c++; }
    if(c==0){
        ans = INT_MIN;
        FOR(i,n) ans = max(ans,ar[i]);
        c++;
    }
    // int ans = df(0,n);
    cout << ans << " " << c << "\n";
    // }
}