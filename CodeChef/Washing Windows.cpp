


/* 
    Solution by Rahul Surana
    
    ***********************************************************


There is a building with N floors (numbered 1 through N from bottom to top); on each floor, there are M windows (numbered 1 through M from left to right). Let's denote the j-th window on the i-th floor by (i,j).

All windows in the building need to be cleaned one by one in a specific order. You are given this order as a matrix A with N rows and M columns; for each valid i and j, the window (i,j) must be cleaned on the AN−i+1,j-th turn.

Whenever we clean a window (i,j), it becomes clean, but the dirty water used for cleaning it flows down to windows (i−1,j−1), (i−1,j) and (i−1,j+1) (more precisely, to all of these windows which exist), so these windows become dirty again. Then, the water flows further down, so the same applies for other windows below: whenever a window (i,j) becomes dirty, windows (i−1,j−1), (i−1,j) and (i−1,j+1) become dirty as well. For example, cleaning a window (5,3) will make the window (3,2) dirty. The next window is cleaned only after water flows down completely. Note that each window is cleaned only once and there may be dirty windows at the end.

For each window, determine whether it will be clean after the cleaning process ends.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and M.
N lines follow. For each i (1≤i≤N), the i-th of these lines contains M space-separated integers Ai,1,Ai,2,…,Ai,M.
Output
For each test case, print N lines; each of them should contain a string with length M. For each valid i and j, the j-th character on the i-th line should be '1' if the window (N−i+1,j) is clean or '0' if it is dirty.



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

int main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        vector<vector<int>> ar(n+2,vector<int>(m+2,0)), ans(n+2,vector<int>(m+2,1)); 
        FOR(i,n) FOR(j,m) { cin >> ar[i+1][j+1];  ans[i+1][j+1] = 1; } 
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int a = max(ar[i-1][j-1],max(ar[i-1][j],ar[i-1][j+1]));
                if(a>ar[i][j]) {
                    ar[i][j] = a;
                    ans[i][j] = 0;
                }
            }            
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cout<< ans[i][j];
            }      
            cout << "\n";      
        }

    }
}
