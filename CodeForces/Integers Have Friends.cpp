


/* 
    Solution by Rahul Surana
    
    ***********************************************************


Ann has recently started commuting by subway. We know that a one ride subway ticket costs a rubles. Besides, Ann found out that she can buy a special ticket for m rides (she can buy it several times). It costs b rubles. Ann did the math; she will need to use subway n times. Help Ann, tell her what is the minimum sum of money she will have to spend to make n rides?

Input
The single line contains four space-separated integers n, m, a, b (1 ≤ n, m, a, b ≤ 1000) — the number of rides Ann has planned, the number of rides covered by the m ride ticket, the price of a one ride ticket and the price of an m ride ticket.

Output
Print a single integer — the minimum sum in rubles that Ann will need to spend.



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


int getMaxLength(int arr[], int N)
{
 
    int res = 2;
    int dist = 2;
 
    int curradj = (arr[1] - arr[0]);
 
    int prevadj = (arr[1] - arr[0]);
    for (int i = 2; i < N; i++) {
        curradj = arr[i] - arr[i - 1];
 
        if (curradj == prevadj) {
 
            dist++;
        }
 
        else {
            prevadj = curradj;
 
            res = max(res, dist);
            dist = 2;
        }
    }
 
    res = max(res, dist);
 
    return res;
}


int main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n ;
        int ar[n];
        FOR(i,n) cin >>ar[i];
        sort(ar,ar+n);
        if(n == 1) {cout << "1\n"; continue;}
        int ans = getMaxLength(ar,n);
        cout << ans << "\n";

    }
}
