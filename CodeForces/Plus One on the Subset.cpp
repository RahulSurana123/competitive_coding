

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Polycarp got an array of integers a[1…n] as a gift. Now he wants to perform a certain number of operations (possibly zero) so that all elements of the array become the same (that is, to become a1=a2=⋯=an).

In one operation, he can take some indices in the array and increase the elements of the array at those indices by 1.
For example, let a=[4,2,1,6,2]. He can perform the following operation: select indices 1, 2, and 4 and increase elements of the array in those indices by 1. As a result, in one operation, he can get a new state of the array a=[5,3,1,7,2].

What is the minimum number of operations it can take so that all elements of the array become equal to each other (that is, to become a1=a2=⋯=an)?

Input
The first line of the input contains a single integer t (1≤t≤104)  — the number of test cases in the test.

The following are descriptions of the input test cases.

The first line of the description of each test case contains one integer n (1≤n≤50)  — the array a.

The second line of the description of each test case contains n integers a1,a2,…,an (1≤ai≤109)  — elements of the array a.

Output
For each test case, print one integer  — the minimum number of operations to make all elements of the array a equal.



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
        int n;
        cin >> n;
        vector<int> ar(n);
        int ma = -1;
        int mi = INT_MAX;
        FOR(i,n) { cin >> ar[i]; ma = max(ma,ar[i]); mi = min(mi,ar[i]); }
        cout << (ma-mi) <<"\n";
    }
}
