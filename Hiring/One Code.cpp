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

vector<int> dp(1001,-1);

int df(int i,vector<int> &ar, int n){
    if(i >= n || i <=0) return 1e9;
    if(dp[i] != -1) return dp[i];
    if(ar[i] == 0) return 0;
    int m = min(df(i+ar[i],ar,n),df(i-ar[i],ar,n)) + 1;
    return dp[i] = m;

}



int main()
{    
	// memset(dp,-1,sizeof(dp));
	vector<int> ar = {4,2,3,0,3,1,2};
	int start = 5;
	// df(,ar,8);
	// cout << ar[3]<<" ";
	cout << df(start,ar,ar.size()) << " ";
}
