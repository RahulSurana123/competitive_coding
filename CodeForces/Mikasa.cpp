
/* 

    Solution by Rahul Surana

    ***********************************************************

You are given two integers n and m. Find the MEX of the sequence n⊕0,n⊕1,…,n⊕m. Here, ⊕ is the bitwise XOR operator.

MEX of the sequence of non-negative integers is the smallest non-negative integer that doesn't appear in this sequence. For example, MEX(0,1,2,4)=3, and MEX(1,2021)=0.

Input
The first line contains a single integer t (1≤t≤30000)  — the number of test cases.

The first and only line of each test case contains two integers n and m (0≤n,m≤109).

Output
For each test case, print a single integer  — the answer to the problem.



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
int inf=1e9+7,MOD=1e9+7;

int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        m++;
        if(m<n) cout<< "0\n";
        else{
            int ans = 0;
            for(int i = 31; i >= 0; i--){
                // cout << (m&bs) << !(n&bs) << " x \n";
                if((m&(1<<i)) != 0 && (n&(1<<i))==0) { ans|=(1<<i); }
                else if((n&(1<<i)) != 0 && (m&(1<<i))==0) { break; }
            }
            cout << ans << "\n";
        }
    }

}