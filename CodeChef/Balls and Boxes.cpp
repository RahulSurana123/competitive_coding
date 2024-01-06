

/* 

    Solution by Rahul Surana

    ***********************************************************

You have NN balls and KK boxes. You want to divide the NN balls into KK boxes such that:

Each box contains \ge 1≥1 balls.
No two boxes contain the same number of balls.
Determine if it is possible to do so.

Input Format
The first line contains a single integer TT — the number of test cases. Then the test cases follow.
The first and only line of each test case contains two space-separated integers NN and KK — the number of balls and the number of boxes respectively.
Output Format
For each test case, output YES if it is possible to divide the NN balls into KK boxes such that the conditions are satisfied. Otherwise, output NO.

You may print each character of YES and NO in uppercase or lowercase (for example, yes, yEs, Yes will be considered identical).



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

        int n,k;
        cin >> n >> k;
        if(k > n || n < (k *(k+1))/2 ) cout << "NO\n";
        else cout << "YES\n";
        
    }
} 