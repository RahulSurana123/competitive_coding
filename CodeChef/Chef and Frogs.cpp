

/* 

    Solution by Rahul Surana

    ***********************************************************

Nobody knows, but N frogs live in Chef's garden.

Now they are siting on the X-axis and want to speak to each other. 
One frog can send a message to another one if the distance between them is less or equal to K.

Chef knows all P pairs of frogs, which want to send messages. Help him to define can they or not!

Note : More than 1 frog can be on the same point on the X-axis.

Input

The first line contains three integers N, K and P.
The second line contains N space-separated integers A1, A2, …, AN denoting the x-coordinates of frogs".
Each of the next P lines contains two integers A and B denoting the numbers of frogs according to the input.

Output

For each pair print "Yes" without a brackets if frogs can speak and "No" if they cannot.



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

int ar[100001];
int ind[100001];

int compare(int a, int b){
    return ar[a] < ar[b];
}

int main()
{
    fast_io;
    FOR(i,100001) ar[i] = 0, ind[i] = i;
    
    // FOR(i,ar.size()) cout << ar[i]<<" "; 
    
    // FOR(i,sop.size()) cout << sop[i]<<" ";  
    // int t;
    // cin >> t;
    
    // while(t--) {
    ll n,p,k;
    cin >> n >> k >> p;
    FOR(i,100001) cin >> ar[i];
    sort(ind,ind+n,compare);

    FOR(i,p) { int a,b; cin >> a >> b; if(abs(ar[a-1] -ar[b-1]) <= k) cout << "Yes\n"; else cout << "No\n"; } 
    
} 