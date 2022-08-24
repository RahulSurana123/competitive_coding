
/* 

    Solution by Rahul Surana

    ***********************************************************

You are given n integers a1,a2,…,an. Find the maximum value of max(al,al+1,…,ar)⋅min(al,al+1,…,ar) over all pairs (l,r) of integers for which 1≤l<r≤n.

Input:

The first line contains a single integer t (1≤t≤10000)  — the number of test cases.
The first line of each test case contains a single integer n (2≤n≤105).
The second line of each test case contains n integers a1,a2,…,an (1≤ai≤106).
It is guaranteed that the sum of n over all test cases doesn't exceed 3⋅105.

Output:

For each test case, print a single integer  — the maximum possible value of the product from the statement.


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

ll ar[100001];

int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--){
    int n;
    cin >> n;
    FOR(i,n) cin >> ar[i];
    // sort(ar,ar+n);
    if(n == 2) { cout << ar[0]*ar[1] <<"\n"; continue; }
    ll max = -1;
    for(int i = 1;i<n-1;i++){
        ll m = ar[i];        
        if(ar[i-1] > ar[i+1]){
            m*=ar[i-1];
        }
        else{
            m*=ar[i+1];
        }
        if(m>max) max = m;
    }
    cout << max<<"\n";
    }
    
}