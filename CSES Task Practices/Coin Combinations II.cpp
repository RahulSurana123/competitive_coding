
/* 

    Solution by Rahul Surana

    ***********************************************************

Consider a money system consisting of n coins. Each coin has a positive integer value. 
Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.

For example, if the coins are {1,5,7} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.

Input

The first input line has two integers n and x: the number of coins and the desired sum of money.

The second line has n distinct integers c1,c2,…,cn: the value of each coin.

Output

Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print −1.



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

int MOD=1e9+7;

int main() {
	fast_io;

    int n,x;
    cin >> n >> x;
    vector<int> ar(n);
    for(auto& v:ar) { 
        cin >> v;
    }
    // cout <<"hi\n";
    vector<int> dp(x+1,0);
    dp[0] = 1;
    // sort(ar.begin(),ar.end(),greater<int>());
    // dp.resize(n,vector<int>(x+1,-1));
    for(int j = 0; j < ar.size(); j++){
        vector<int> temp(x+1,0);
        for(int i = 0; i < x+1; i++){
            temp[i] = dp[i];
            if( i >= ar[j]){
                temp[i] += temp[i-ar[j]];
            }
            if(temp[i] >= MOD) temp[i] -= MOD;
            // cout<< temp[i] <<" ";
        }
        // cout <<"\n";
        dp = temp;
    }
    // cout << dp[x] <<"\n";
    cout << dp[x]<<"\n";
}
