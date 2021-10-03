

/* 
    Solution by Rahul Surana
    
    ***********************************************************

    
    Question Not Available
    

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

vector<int> ar;
vector<vector<int>> dp;

int update(int l,int r){
    if(dp[l][r] != -1) return dp[l][r];
    int count = 0;
    for(int i = l; i <= r; i++){
        int sum = ar[i];
        if(sum %2==0) count++;
        for(int j = i+1; j <= r; j++){
            sum += ar[j];
            if(sum%2==0) count++;
        }
    }
    return dp[l][r] = count;
}

int main()
{
	fast_io;
    int n,q;
    cin >> n;
    ar.resize(n);
    dp.resize(n+2,vector<int>(n+2,-1));
    for(int i = 0; i < n; i++) cin >> ar[i];
    cin >> q;
    while(q--){
        int l,r;
        cin >> l>>r;
        cout << update(l,r) << "\n";
    }
}
