

/* 

    Solution by Rahul Surana

    ***********************************************************

Chef has two numbers XX and YY. Chef wants to find three integers A, B,A,B, and CC such that:

-1000 < A, B, C < 1000    −1000 ≤ A , B, C ≤1000
mean([A, B, C]) = X       mean([A,B,C])=X
median([A, B, C]) = Y     median([A,B,C])=Y
Can you help Chef find such three integers?

As a reminder, mean([P, Q, R]) = {P + Q + R}/{3} and median([P, Q, R]) median([P,Q,R]) is the element at the 2nd (middle) position after we sort [P, Q, R] in non-decreasing order.

Input Format:
The first line contains a single integer T — the number of test cases. Then the test cases follow.
The first and only line of each test case contains two space-separated integers XX and YY — the required mean and median of the three integers.

Output Format:
For each test case, output three integers A, B, C which satisfy the given conditions.
It is guaranteed that an answer always exists under the given constraints.
If multiple answers exist, output any.



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

        int n,m;
        cin >> n>>m;
        vector<int> a(3,m);
        int s = n*3;
        if(s > 3*m) a[2] += (s-(3*m)); 
        else if(s < 3*m) a[0] += (s-(3*m)); 
       
        cout << a[0] <<" "<< a[1] << " "<< a[2] <<"\n";
    }
} 