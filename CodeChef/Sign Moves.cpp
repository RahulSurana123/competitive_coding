

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Initially, Chef is at coordinate 0 on X-axis. For each i=1,2,…,N in order, Chef does the following:

If Chef is at a non-negative coordinate, he moves i steps backward (i.e, his position's coordinate decreases by i), otherwise he moves i steps forward (i.e, his position's coordinate increases by i).
You are given the integer N. Find the final position of Chef on the X-axis after N operations.

Input Format
The first line of input contains an integer T, denoting the number of test cases. The T test cases then follow:
The first and only line of each test case contains an integer N.
Output Format
For each test case, output in a single line the final position of Chef on the X-axis after N operations.



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

vector<int> dp;

int main()
{
    fast_io;
    int t;
    cin >> t;
    // ll x = 0;
    // ll z = 1;
    while(t--) {
        int n;
        cin >> n;
        ll ans = n/2 + n%2 ;
        if(n%2) ans*=-1;
        cout << ans <<"\n";
        // cout << ans <<"\n";
    }
}
