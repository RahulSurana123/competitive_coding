


/* 
    Solution by Rahul Surana
    
    ***********************************************************

You have prepared four problems. The difficulty levels of the problems are A1,A2,A3,A4 respectively. 
A problem set comprises at least two problems and no two problems in a problem set should have the same difficulty level. A problem can belong to at most one problem set. 
Output the maximum number of problem sets you can create using the four problems.

Input Format:

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains four space-separated integers A1, A2, A3, A4, denoting the difficulty level of four problems.

Output Format:

For each test case, print a single line containing one integer - the maximum number of problem sets you can create using the four problems.



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
        int ar[4];
        int s[11];
        FOR(i,11) s[i] = 0;
        FOR(i,4) { cin >>ar[i]; s[ar[i]]++; }
        int ans = 2;
        int count = 0;
        for(int i = 1; i < 11; i++){
            if(s[i] == 4) { ans = 0; break; }
            if(s[i] == 2) count++;
            if(count == 2) { ans = 2; break; }
            if(s[i] == 3) { ans= 1; break; }
            // cout << ans << " ";
        }
        // FOR(i,11) { trace(s[ar[i]]); }

        cout << ans <<"\n";

    }
}