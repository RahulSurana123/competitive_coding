
/* 

    Solution by Rahul Surana

    ***********************************************************

You are given an integer n. On each step, you may subtract one of the digits from the number.

How many steps are required to make the number equal to 0?

Input

The only input line has an integer n.

Output

Print one integer: the minimum number of steps.


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
#define fast_io 	std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;

vector<int> dp;

int df(int x){
    if(x < 10) return 1;
    if(dp[x] != -1) return dp[x];
    int n = x;
    int ans = 1e9;
    while(n>0){
        int z = (x - (n%10));
        if(z != x)
        ans = min(1 + df(z), ans);
        n/=10;
    }
    return dp[x] = ans;
}

int main() {
	fast_io;
    int n;
    cin >> n;
    dp.resize(n+1, -1);
    cout << df(n) <<"\n";
}
