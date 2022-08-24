

/* 
    Solution by Rahul Surana
    
    ***********************************************************

Creatnx now wants to decorate his house by flower pots. He plans to buy exactly N ones. He can only buy them from Triracle's shop. 
There are only two kind of flower pots available in that shop. The shop is very strange. If you buy X flower pots of kind 1 then you must pay A * X * X and B * Y * Y 
if you buy Y flower pots of kind 2. Please help Creatnx buys exactly  flower pots that minimizes money he pays.

Input Format:

The first line contains a integer T denoting the number of test cases.
Each of test case is described in a single line containing three space-separated integers N A B.

Output Format:

For each test case, print a single line containing the answer.



    ***********************************************************
*/



#include <bits/stdc++.h>
#define ll          long long int
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


int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--) {
        ll n,a,b;
        cin >> n >> a >> b;
        // for(int i = 0; i <= n;i++){
        //     // cout << (a*i*i)+(b*(n-i)*(n-i)) << "\n";
        //     ans = min(ans,(a*i*i)+(b*(n-i)*(n-i)));
        // }
        ll x  = (b*n) / (a+b);
        ll y = (a*n) / (a+b);
        ll ans =  min(b*n*n,min(a*n*n,min((a*x*x)+(b*(n-x)*(n-x)),(b*y*y)+(a*(n-y)*(n-y)))));
        cout << ans <<"\n";
    }
}