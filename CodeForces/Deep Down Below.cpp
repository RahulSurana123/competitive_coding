


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

vector<int> ak;
pi m[100005];

bool compare(pi a, pi b){
    if(a.F==b.F) return a.S<b.S;
    return a.F < b.F;
}

int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ak.clear();
        ak.resize(n+2);
        FOR(i,n) { 
            int k; 
            cin >> k;   
            int v = 0;
            FOR(j,k) {
                int f; 
                cin >> f;  
                v = max(f - j+1,v);
                }
            m[i+1].F = v;
            m[i+1].S = k;
        }
        sort(m+1,m+n+1,compare);
        // for(int i = 1;i<=n; i++) cout << m[i].F << " " << m[i].S<<" ";
        int ans = m[1].F;
        int p = m[1].F + m[1].S;
        for(int i = 2;i<=n; i++){
            if(p > m[i].F) p += m[i].S; 
            else { ans+=m[i].F - p; p= m[i].F+m[i].S; }
            // if(ans - ak[i].size() <= m[i].F) ans = max(m[i].F - m[i].S+1, ans - ak[i].size());
        }
        cout << ans << "\n";
    }
}