
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
#define trace(x)    cerr<<#x<<" : "<<x<<endl;
#define trace2(x,y) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<" | "<<#z<<" : "<<z<<endl;
#define fast_io 	std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;

int MOD=1e9+7;

// vector<ll> dp;

// int df(vector<int> &ar,int n, int x){
    
//     queue<int> q;
//     map<int,bool> v;
//     q.push(0);
//     int c = 0;
//     while(!q.empty()){
//         int size = q.size();
//         while(size--){
//             int z = q.front();
//             q.pop();
//             if(v[z]) continue;
//             v[z] = true;
//             if(z > x) continue;
//             if(z==x) return c;
//             for(int i = 0; i < ar.size(); i++){
//                 if(z+ar[i]<=x)
//                 q.push(z+ar[i]);
//             }
//         }
//         c++;
//     }    
//     return -1;
// }


int main() {
	fast_io;
    int t=1,w = 1;
    // cin >> t;
    while(t >= (w)){
        ll n,x;
        cin >> n>>x;
        vector<int> ar(n);
        FOR(i,n) cin >> ar[i];
        sort(ar.begin(),ar.end());
        vector<int> dp(x+1,1e9);
        for(int i = 0; i < x+1; i++){
            if(i%ar[0] == 0){
                dp[i] = i/ar[0];
            }
        }
        for(int i = 1; i < n;i++){
            vector<int> temp(x+1,1e9);
            for(int j = 0; j < x+1; j++){
                temp[j] = dp[j];
                if(j-ar[i] >= 0)
                temp[j] = min(1+temp[j-ar[i]],temp[j]);
            }
            dp = temp;
        }  
        cout << (dp[x] == 1e9? -1:dp[x]) <<"\n";
        // cout << "Case #" << w << ": " << ans <<"\n";
        w++;
    }
}
