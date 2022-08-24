

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Petya has got an interesting flower. Petya is a busy person, so he sometimes forgets to water it. You are given n days from Petya's live and you have to determine what happened with his flower in the end.

The flower grows as follows:

If the flower isn't watered for two days in a row, it dies.
If the flower is watered in the i-th day, it grows by 1 centimeter.
If the flower is watered in the i-th and in the (i−1)-th day (i>1), then it grows by 5 centimeters instead of 1.
If the flower is not watered in the i-th day, it does not grow.
At the beginning of the 1-st day the flower is 1 centimeter tall. What is its height after n days?

Input:

Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100). Description of the test cases follows.
The first line of each test case contains the only integer n (1≤n≤100).
The second line of each test case contains n integers a1,a2,…,an (ai=0 or ai=1). If ai=1, the flower is watered in the i-th day, otherwise it is not watered.

Output:

For each test case print a single integer k — the flower's height after n days, or −1, if the flower dies.



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
        int n;
        cin >> n;
        int ar[n];
        FOR(i,n) cin >> ar[i];
        ll ans = (ar[0] == 1 ? 2 : 1);
        for(int i = 1; i < n; i++){
            if(ar[i] == 1 && ar[i-1] == 1) ans+=5;
            else if(ar[i] == 1) ans+=1;
            else if(ar[i-1] == 0 && ar[i]== 0 ) { ans = -1; break; }
            
        }
        cout << ans <<"\n";
    }
}


