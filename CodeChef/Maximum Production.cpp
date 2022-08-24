

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Chefland has 7 days in a week. Chef is very conscious about his work done during the week.

There are two ways he can spend his energy during the week. The first way is to do x units of work every day and the second way is to do y (>x) units 
of work for the first d (<7) days and to do z (<x) units of work thereafter since he will get tired of working more in the initial few days.

Find the maximum amount of work he can do during the week if he is free to choose either of the two strategies.

Input

The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, four integers d, x, y, z.

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
#define fast_io 	std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;


int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--) {
        int d,x,y,z;
        cin >> d>>x>>y>>z;
        int ans = max(y*d+z*(7-d),7*x);
        cout << ans << "\n";
    }
}
