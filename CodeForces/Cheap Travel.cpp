


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
#define fast_io 	std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;


int minimu_cost_ride(int i,int m, int a,int b,int target){
	if(i == target) return 0;
	if(i+m > target) return min(((target-i) * a),b);
	int ans = 0;
	if(m*a > b) ans += minimu_cost_ride(i+m,m,a,b,target) + b;
	else ans += minimu_cost_ride(i+1,m,a,b,target) + a;
	return ans;
}


int main()
{
	fast_io;
    // int t;
    // cin >> t;
    // while(t--) {
        int a,b,n,m;
        cin >> n >> m >> a >> b;
        int ans = minimu_cost_ride(0,m,a,b,n);
        cout << ans << "\n";

    // }
}
