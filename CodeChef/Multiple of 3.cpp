

/* 

    Solution by Rahul Surana
    

    ***********************************************************


Consider a very long K-digit number N with digits d0, d1, ..., dK-1 (in decimal notation; d0 is the most significant and dK-1 the least significant digit). 
This number is so large that we can't give it to you on the input explicitly; instead, you are only given its starting digits and a way to construct the remainder of the number.

Specifically, you are given d0 and d1; for each i ≥ 2, di is the sum of all preceding (more significant) digits, modulo 10 — more formally, the following formula must hold: 

Determine if N is a multiple of 3.

Input:

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains three space-separated integers K, d0 and d1.

Output:

For each test case, print a single line containing the string "YES" (without quotes) if the number N is a multiple of 3 or "NO" (without quotes) otherwise.



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


int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    ll k,x,d0,d1;
	    cin>>k;
	    cin>>d0>>d1;
	    x=d0+d1;
	    k=k-2;
	    while(k>0){
	        x+=x%10;
	        k--;
	        if(k%12==0){
	            break;
	        }
	    }
	    if(x%3==0){
	        cout<<"YES"<<"\n";
	    }
	    else{
	        cout<<"NO"<<"\n";
	    }
	}
	return 0;
}