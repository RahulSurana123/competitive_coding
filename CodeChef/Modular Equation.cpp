
/* 

    Solution by Rahul Surana

    ***********************************************************

Given integers N and M, find the number of ordered pairs (a,b) such that 1≤a<b≤N and ((M mod a) mod b)=((M mod b) mod a).

Input

The first line contains an integer T, the number of test cases. Then the test cases follow.
The only line of each test case contains two integers N, M.

Output

For each testcase, output in a single line the answer to the problem.

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


int main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        ll ans=0;
        for (int i = 1;i < n; i++) 
            for(int j = i+1;j <= n; j++) 
                if((((m%i)%j) == ((m%j)%i))) ans++;
        cout << ans << "\n";
    }
}