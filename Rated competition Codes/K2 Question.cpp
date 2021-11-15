

/* 

    Solution by Rahul Surana

    ***********************************************************

Zack is a tailor by profession. He is famous for making square-shaped beautifully-cut and sewed handkerchieves.

The customers demand large-sized handkerchieves. So, now Zack is determined to get the maximum size out of the cloth. 
He has a rectangular piece of cloth of length 'L' and breadth 'B'.

His task is to divide it into 'N' square-shaped cloth pieces each of side length ‘S’. 
So he can make handkerchieves out of them of the maximum size.

Input:

The first line of the input contains T- the number of test cases. T lines follow. Each line of the test case contains L followed by B.

Output:

S -the maximum length of each square-shaped handkerchief.



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


ll gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}


int main()
{
    fast_io;
    
    // int t;
    // cin >> t;
    
    // while(t--) {
    string s;
    cin >> s;
    string ans;
    int i = 0;
    while(i<s.length()){
        string temp = "";
        while(i < s.length() && s[i] - '0' > 9 ) { temp += s[i]; i++; }
        int times = 0;
        while(i < s.length() && s[i] - '0' <= 9 ) { times*=10; times+=(s[i]-'0'); i++; }
        FOR(j,times) ans+= temp;
    }
    cout << ans << "\n";
    // }

    // }
} 