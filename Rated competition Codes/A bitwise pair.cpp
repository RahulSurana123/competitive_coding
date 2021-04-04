

/*

You are given an array A of N positive integers. Find the number of pairs (i,j) such that:

((A[i] | A[j])  - (A[i] & A[j]) = A[i] - A[j] ), where | is a bitwise OR operator and & is a bitwise AND operator.


Input format

The first line contains an integer T denoting the number of test cases.
The first line of each test case contains an integer N.
The second line of each test case contains N space-separated integer denoting array A .


Output format

For each test case, print the number of pairs, in a new line, satisfying the equation.

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
    int t,n;
    cin >> t;
    FOR(i,t) {
        cin >> n;
        int ans = 0;
        vi freq(1001,0);
        FOR(j,n) { int a; cin >> a; freq[a]++; }
        for(int j = 1;j<1001;j++) {
            for(int k = 1;k<1001;k++) { 
                if(k>j) break; 
                if((j^k) == (j - k)) ans+=(freq[j] * freq[k]);        
            }
        }
        cout << ans << "\n";
    }
}