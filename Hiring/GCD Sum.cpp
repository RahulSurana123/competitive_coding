

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Problem Statement

Alice gives Bob, two integers N and K.

Now, Bob makes sequences of integers of length N, having elements in the range 1 to K, both inclusive.

As we know, there could be K^N such sequences.

For all such sequences, Alice calculates the Greatest Common Divisor (GCD) of all elements in each sequence and adds them.

Print the final sum. Since this sum can be huge, print it modulo 1000000007.

For better understanding, refer to the explanation of test cases.

 

Constraints

• 2 ≤ N ≤ 10^5
• 1 ≤ K ≤ 10^5
 

Input Format

The only line contains two integers N and K, separated by space.

 

Output Format

An integer denoting the answer.

 

Sample Input

3 2

 

Sample Output

9

 

Explanation of Sample

Since K=2, Sequences can have only 1 and 2 as its element.

 

Possible sequences are:

1) [1, 1, 1] G.C.D = 1
2) [1, 1, 2] G.C.D = 1
3) [1, 2, 1] G.C.D = 1
4) [1, 2, 2] G.C.D = 1
5) [2, 1, 1] G.C.D = 1
6) [2, 1, 2] G.C.D = 1
7) [2, 2, 1] G.C.D = 1
8) [2, 2, 2] G.C.D = 2
 

Hence, sum = 1+1+1+1+1+1+1+2 = 9



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

int MOD = ((1e9) + 7);

int fac(int n){
    if(n<=1) return 1;
    return (n * (fac(n-1)%MOD))%MOD;
}

int nCr(int n,int r){
    if(r==0 || r== n) return 1;
    return ((fac(n)%MOD / fac(n-r)%MOD)%MOD);
}



// int df(int i, int j, int n, int k){

// }


int main()
{
	fast_io;
    int t=1;
    // cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> dp((1<<k+1),0);
        for(int i = 0; i <= k; i++ ){
            dp[(1<<i)] = ((1<<n) -1)%MOD;
            // cout << (1<<i)<<" "<<(1<<n) <<"\n"; 
        }
        for(int i = 1; i <= k;  i++){
            for(int j = 2; j < (1<<k+1); j++){
                if(!(j&(1<<i))){
                    int m = 0;
                    for(int z = 9; z >= 1; z--) { if((1<<z)&j) m++; }
                    if(m != 1) dp[(1<<i)||j] += dp[j] + nCr(n-m-1,m-1);
                    // cout<< ((1<<i)||j) <<" "<<dp[(1<<i)||j] <<"\n"; 
                // nCr(n-m,m);
                }
            }
        }
        // for(int i = 1; i < 1<<(k+1)-; i++)
        // cout << dp[i]<<" ";
        // cout << "\n";
        int ans = 0;
        for(int j = 1; j < (1<<(k)); j++){
            int m = 0;
            int gcd = 0;
            for(int z = 9; z >= 1; z--) { if(gcd == 0 && (1<<z)&j) gcd = z; if((1<<z)&j) gcd = __gcd(z,gcd); }
            ans += (dp[j]%MOD * gcd%MOD)%MOD;
                // cout<< j <<" "<< (1<<i) << dp[(1<<i)||j] <<"\n"; 
            // nCr(n-m,m);
        }


        cout << ans+2 <<" ";
    }
}
