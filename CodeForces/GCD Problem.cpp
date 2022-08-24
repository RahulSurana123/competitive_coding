

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a positive integer n. Find three distinct positive integers a, b, c such that a+b+c=n and gcd(a,b)=c, where gcd(x,y) denotes the greatest common divisor (GCD) of integers x and y.

Input
The input consists of multiple test cases. The first line contains a single integer t (1≤t≤105) — the number of test cases. Description of the test cases follows.

The first and only line of each test case contains a single integer n (10≤n≤109).

Output
For each test case, output three distinct positive integers a, b, c satisfying the requirements. If there are multiple solutions, you can print any. We can show that an answer always exists.


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

// int p[1000000007];

// void seive_of_erathros(){
//     p[0] = 1; 
//     for(int i = 2; i < 1000000007; i++){
//         for(int j = i*i; j<1000000007; j+=i){
//             p[j] = 1;
//         }
//     }
// }

int main()
{
    fast_io;
    int t=1;
    cin >> t;
    // seive_of_erathros();
    while(t--){
        
        ll n;
        cin >> n;
        ll b=-1,c=-1;
        if(n%2==0) { b = n-3; c = 2; }
        else if(n%4==1) { b = floor(n/2)+1; c = floor(n/2)-1; }
        else if(n%4==3) { b = floor(n/2)+2; c = floor(n/2)-2; }
        cout << b << " " << c << " 1\n";
    }
}