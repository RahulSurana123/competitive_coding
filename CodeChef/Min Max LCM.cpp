

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given two positive integers X and K.

You have to output the minimum and maximum value of LCM(i,j) where X≤i<j≤X⋅K.

We define LCM(i,j) for two positive integers i and j as the minimum positive integer y such that both i and j divide y without remainder.

Input Format
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, two space separated integers X and K.
Output Format
For each testcase, output two space separated integers - the minimum and maximum possible value respectively of LCM(i,j) where X≤i<j≤X⋅K.



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
        ll x,k;
        cin >> x >> k;
        ll ans = 2*x;
        ll ans2 = (x*(k))*((k*x)-1);
        cout << ans <<" "<<ans2<< "\n";

    }
}
