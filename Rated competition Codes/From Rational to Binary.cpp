

/* 
    Solution by Rahul Surana
    
    ***********************************************************

Chef and Divyam are playing a game. They start with a rational number X, such that 0<X<1.

In each turn, Chef chooses a positive real number Y. Then Divyam either adds or subtracts Y to X. 
So X is replaced with either X+Y or X−Y. If this number becomes 0 or 1, then Chef wins. Otherwise, the game continues.

You are given X, and you have to determine whether Chef can win in a finite number of moves. 
More formally, does there exist a finite number N so that Chef has a strategy that is guaranteed to win in at most N moves?

Here, X will be given in the form AB, where A and B are positive integers, A<B and gcd(A,B)=1.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains two space-separated integers A and B.

Output

For each test case, print a single line containing the string "Yes" if Chef can win the game in a finite number of moves and "No" otherwise (without quotes). 
You can print "Yes" or "No" in any case.


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
    cin >> t;
    FOR(i,t) {
        ll a,b;
        cin >> a>>b;
        if(b&(b-1) == 0){
            cout << "Yes\n";
        }
        else{  
            cout << "No\n";
        }
    }
}
