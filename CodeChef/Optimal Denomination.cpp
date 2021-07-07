

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are the owner of a big company. You are so rich, that the government has allowed you to print as many notes as you want of any single value that you like. 
You also have peculiar behavioral traits and you often do things that look weird to a third person.

You have N employees, where the i-th employee has salary Ai. You want to pay them using a denomination that you create. 
You are also eco-friendly and wish to save paper. So, you wish to pay them using as few notes as possible. 
Find out the minimum number of notes required if you can alter the salary of at most one employee to any positive integer that you like, 
and choose the positive integer value that each note is worth (called its denomination).

Each employee must receive the exact value of his/her salary and no more.

Input

The first line contains an integer T, the number of test cases. Then the test cases follow.
The first line of each test case contains a single integer N.
The second line contains N integers A1,A2,…,AN, where Ai is the salary of the i-th employee.

Output

For each test case, output in a single line the answer to the problem.



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

int ar[100001];
vector<vector<int>> dp;

int gcd(int a,int b){
    if(a == 1 || b ==1) return 1;    
    
    while(a!=0){
        int temp = b%a;
        b = a;
        a = temp;    
    }
    
    return b;
}

int main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        FOR(i,n) cin >> ar[i];
        dp.resize(2,vector<int>(n,0));
        dp[0][0] = ar[0];
        dp[1][n-1] = ar[n-1];
        for(int i = 1; i < n;i++){
            dp[0][i] = gcd(dp[0][i-1], ar[i]);
            // cout << ar[i] << " "<<dp[0][i-1] << " "<<gcd(dp[0][i-1], ar[i])<<" ";
        }
        for(int i = n-2; i >=0 ;i--){
            dp[1][i] = gcd(dp[1][i+1], ar[i]);
        }
        int ignore = -1;
        int max_gcd = dp[0][n-1];
        for(int i=1; i < n-1; i++){
            int g = gcd(dp[0][i-1],dp[1][i+1]);
            if(max_gcd<=g) { if(max_gcd == g && ar[ignore] < ar[i]) ignore = i; max_gcd = g;  }
        }
        // FOR(i,n) break;
        // cout <<"\n";
        // FOR(i,n) cout << dp[1][i] << " ";
        // cout << "\n";
        if(dp[1][0] >= max_gcd) { if(max_gcd == dp[1][0] && ar[ignore] < ar[0]) ignore = 0; max_gcd = dp[1][0]; }
        if(dp[0][n-1] >= max_gcd) { if(max_gcd == dp[0][n-1] && ar[ignore] < ar[n-1]) ignore = n-1; max_gcd = dp[0][n-1]; }
        if(ignore != -1) ar[ignore] = max_gcd;
        ll count = 0;
        FOR(i,n){
            count += ar[i]/max_gcd;
        }
        // cout <<max_gcd << " ";
        cout << count <<"\n";
    }
}
