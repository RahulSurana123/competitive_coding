

/* 
    Solution by Rahul Surana
    
    ***********************************************************


A total of n depots are located on a number line. Depot i lies at the point xi for 1≤i≤n.

You are a salesman with n bags of goods, attempting to deliver one bag to each of the n depots. You and the n bags are initially at the origin 0. You can carry up to k bags at a time. You must collect the required number of goods from the origin, deliver them to the respective depots, and then return to the origin to collect your next batch of goods.

Calculate the minimum distance you need to cover to deliver all the bags of goods to the depots. You do not have to return to the origin after you have delivered all the bags.

Input:

Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤10500). Description of the test cases follows.
The first line of each test case contains two integers n and k (1≤k≤n≤2⋅105).
The second line of each test case contains n integers x1,x2,…,xn (−109≤xi≤109). It is possible that some depots share the same position.
It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output:

For each test case, output a single integer denoting the minimum distance you need to cover to deliver all the bags of goods to the depots.



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

// vector<vector<int>> dp;
// int ans = 0;

int main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        int ar[n];
        FOR(i,n) cin >> ar[i];
        vector<int> a;
        vector<int> b;
        FOR(i,n) { if(ar[i] >= 0) a.pb(ar[i]); else b.pb(-ar[i]); }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        ll ans = 0;
        for(int i = a.size()-1; i >= 0; i-=k){
            ans += 2*a[i];
        }
        for(int i = b.size()-1; i >= 0; i-=k){
            ans += 2*b[i];
        }
        int maxx = 0;
        if(a.size()>0) maxx = max(maxx,a[a.size()-1]);
        if(b.size()>0) maxx = max(maxx,b[b.size()-1]);
        cout << ans-maxx <<"\n";
    }
}


