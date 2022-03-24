

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Chef was recently studying the Bitwise OR operation, and stumbled upon the following problem:

Let F(i)=1 | 2 | 3 | … | i, where | denotes bitwise OR.

You are given an integer N. Find the number of distinct i such that 2≤i≤N and F(i)=F(i−1).

Input Format
The first line of input will contain an integer T — the number of test cases. The description of T test cases follows.
The first and only line of each test case contains an integer N.
Output Format
For each test case, output the number of distinct i such that 2≤i≤N and F(i)=F(i−1).



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


int main()
{
	fast_io;
    int t;
    // int x = 1;
    cin >> t;
    // for(int i = 1; i < 10; i++){
    //     x |= i;
    //     cout << x <<" ";
    // }
    while(t--) {
        int n;
        cin >> n;
        ll ans = 0;
         // x = 1;
        // cout << (n&(-n)) <<" ";
        while(n>0){
            ans += (n-(n/2)-1);
            n /=2;
        }
        // if(x>n) ans+= (n-(x/2)-1);
        cout << ans <<"\n";
    }
        // cout << ans <<"\n";
}
