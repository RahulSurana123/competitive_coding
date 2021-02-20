

/* 

    Solution by Rahul Surana

    ***********************************************************


M as a prisoner loves playing with his array a, he can do following operation as much as he wants:

Choose two integers i,j that 1 <= i , j <= 2*10^5 and |ai-aj|==1 and also ai >=2.
Then add 1 to  ith() and subtract 2 from  jth().
M thinks beautifulness of an array is maximum value of it max(a).

What is the maximum value of beautifulness that M can get after doing above operation as much as he wants?

Input

First line contains only n, length of array.

Second line contains the array elements separated by space.



Output

The only line of output contains an integer, maximum beautifulness value that M can get.

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
 
using namespace std;
int inf=1e9+7,MOD=1e9+7;
int ar[200000],s[200000],sa[200000];
int main()
{
	fast_io;
    int n,ans=0,ma=0;
    cin >> n;
    FOR(i,n) cin >> ar[i];
    sa[0]=ar[0]+ar[1]/2;
    for(int i = 1; i < n-1; i++){sa[i]= ar[i+1]/2+ar[i]+ar[i-1]/2;}
    sa[n-1]=ar[n-1]+ar[n-2]/2;
    FOR(i,n) if (sa[ma] <= sa[i]) {if(sa[ma]==sa[i]){if(ar[i]>ar[ma])ma = i;}else ma=i;};
    // cout << ma<<"\n";
    // FOR(i,n) cout << sa[i]<<" ";
    s[0] = ar[0];
    s[n-1] = ar[n-1];
    // cout << ma<<"\n";
    for(int i = 1; i <= ma; i++) s[i]+= s[i-1]/2 + ar[i];
    s[ma] -=ar[ma]; 
    for(int i = n-1; i > ma; i--) s[i-1]+= s[i]/2 + ar[i-1];
    // FOR(i,n) cout << s[i]<<" ";
    FOR(i,n) if (ans < s[i]) ans = s[i];
    cout << ans;
}