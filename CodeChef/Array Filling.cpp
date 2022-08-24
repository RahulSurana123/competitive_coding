


/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array A of size N. Initially, the array is filled with 0-s.

There are M types of operations that you can perform on array A. The ith operation can be described by two integers (xi,yi). In this operation, you choose a set of indices S such that

1 ≤ j ≤ N,
(j % y(i) ) ≠ 0,
 A(j) = 0,
, then you set Aj=xi for all j∈S.

You can perform the operations in any order, but one type of operation can't be done more than once. What is the maximum sum of integers of the array A you obtain if you perform the M operations optimally?

For example, consider the array A=[0,0,0,0].

Suppose x=3,y=2. Here you can choose indices 1 and 3 and set A1=A3=3. So the array A becomes [3,0,3,0]. In this operation you can't choose the indices 2 and 4 because (2mod2)=0, (4mod2)=0.

Suppose x=5,y=3 and you set A2=5. So the array A becomes [3,5,3,0]. Here you can't choose index 1 because A1>0 and index 3 because (3mod3)=0 and A3>0. However, you could also set A4=5.

Suppose x=4,y=4. Now you can't choose any index because Aj>0 for all 1≤j≤3 and (4mod4)=0. So the array remains same.

Note: Since input-output is large, prefer using fast input-output methods.

Input Format:

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
Each testcase contains M+1 lines of input.
The first line of each test case contains two space-separated integers N,M.
M lines follow. For each valid i, the ith of these lines contains two space-separated integers xi,yi - parameters of the ith operation.

Output Format:

For each test case, output in a single line the maximum sum of integers of the array A after M operations.


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
        ll n,m;
        cin >> n>>m;
        vector<pi> q;
        FOR(i,m){
            ll x,y;
            cin >> x >> y;
            q.pb({x,y});
        }
        sort(q.begin(),q.end(),greater<pi>());
        ll remaining = n;
        ll lcm = 1;
        ll ans = 0;
        for(int i = 0; i < m && remaining >0;i++){
            ll a = q[i].F, b= q[i].S;
            lcm = lcm * b / __gcd(lcm,b);
            ans += (remaining - n/lcm)*a;
            remaining = n/lcm;
        }
        cout << ans << "\n";
    }
}
