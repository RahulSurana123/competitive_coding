

/* 

    Solution by Rahul Surana

    ***********************************************************


Number 1 is written on the whiteboard. Perform exactly c operations on the written number. 
In each step, you can do one of the following operations: 
	-> Multiply the number on the board by a
	-> Add b to the number on the board

Determine the maximum number you can reach after exactly c operations.

Input

The first line of input contains a, b, c respectively.

Note : a is a decimal number and b and c are integers.

Output

If the correct answer of the problem is Ans, then you must print log2(Ans). If your answer is O, then your answer is considered correct if ((log2(Ans) - O )/log2(Ans)) <= 10^{-6}.

Note : The output should only consist of digits and dot. For example 235653455.5277 is correct and 2.356534555277e+8& is not correct.

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

int main()
{
	fast_io;
    long double a,ans=0;
    ll b,c,temp=1;
    cin >> a >> b >> c;
    if(a>1) {
    while(temp + b > temp * a){
        temp += b; 
        c--;
    }
    ans += log2(temp);
    ans += c*log2(a);
    cout << setprecision(7) << ans;
    }
    else{
        ans = log2(c) + log2(b);
        cout << setprecision(7) << ans;
    }
}