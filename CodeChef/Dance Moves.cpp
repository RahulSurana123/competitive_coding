

/* 
    Solution by Rahul Surana
    
    ***********************************************************


This year Chef is participating in a Dancing competition. The dance performance will be done on a linear stage marked with integral positions. Initially, 
Chef is present at position X and Chef's dance partner is at position Y. Chef can perform two kinds of dance moves.

If Chef is currently at position k, Chef can:

Moonwalk to position k+2, or
Slide to position k−1
Chef wants to find the minimum number of moves required to reach his partner. Can you help him find this number?

Input Format:

First line will contain a single integer T, the number of testcases. Then the description of T testcases follows.
Each testcase contains a single line with two space-separated integers X,Y, representing the initial positions of Chef and his dance partner, respectively.

Output Format:

For each testcase, print in a separate line, a single integer, the minimum number of moves required by Chef to reach his dance partner.



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
    while(t--) {
        int x,y;
        cin >> x >> y;
        
        if(y<x) { cout << x-y <<"\n"; continue; }
        int ans = (ceil((double)(y-x)/2) + (y-x)%2);
        // ceil((double)(y-x)/2)<<" "<<(y-x)%2<<" "
        cout <<ans <<"\n";

    }
}
