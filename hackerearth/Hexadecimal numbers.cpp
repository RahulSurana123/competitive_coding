





/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a range [L, R]. You are required to find the number of integers X in the range such that GCD(X,F(X)) 
where F(X) is equal to the sum of digits of X in its hexadecimal (or base 16) representation.

For example, F(27) = 1 + B = 1 + 11 = 12 (27 in hexadecimal is written as 1B). You are asked T such questions. 

Input format

The first line contains a positive integer T denoting the number of questions that you are asked.
Each of the next T lines contain two integers L and R denoting the range of questions.
Output Format

For each test case, you are required to print exactly T numbers as the output. 



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
#define MOD 1000000007 
using namespace std;

int gcd(int a, int b){
    if(a==0) return b;
    if(b==0) return a;
    while(b>0){
        int temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}

int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--) {
        int l,r;
        cin >> l >> r;
        int ans = 0;
        for(int i = l; i <= r; i++){
            int v = 0;
            int x = i;
            while(x > 0) { v += x%16; x/=16;  }
            if(__gcd(v,i) > 1) { ans++; }
        }
        cout << ans <<"\n";
    }
}