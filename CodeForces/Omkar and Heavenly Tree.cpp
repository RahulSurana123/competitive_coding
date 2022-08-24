

/* 
    Solution by Rahul Surana
    
    ***********************************************************


In Chefland, the speed of light is c m/s, and acceleration due to gravity is g m/s2.

Find the smallest height (in meters) from which Chef should jump such that during his journey down only under the effect of gravity and independent 
of any air resistance, he achieves the speed of light and verifies Einstein's theory of special relativity.

Assume he jumps at zero velocity and at any time, his velocity (v) and depth of descent (H) are related as
v2=2⋅g⋅H.

Input

The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, two integers g, c.

Output

For each test case, output in a single line the answer to the problem. We can show that under the constraints, the answer is an integer.



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


int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n,e;
        cin >> n >> e;
        vector<bool> v(n+1,true);
        FOR(i,e) { int a,b,c; cin >>a>>b>>c; v[b]=false; }
        FOR(i,n)  if(v[i+1]) { FOR(j,n) if(i!=j) cout << i+1 << " " << j+1 <<"\n";  break; }
    }
}
