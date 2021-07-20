

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Vanya walks late at night along a straight street of length l, lit by n lanterns. Consider the coordinate system with the beginning of the street corresponding to the point 0, and its end corresponding to the point l. Then the i-th lantern is at the point ai. The lantern lights all points of the street that are at the distance of at most d from it, where d is some positive number, common for all lanterns.

Vanya wonders: what is the minimum light radius d should the lanterns have to light the whole street?

Input
The first line contains two integers n, l (1 ≤ n ≤ 1000, 1 ≤ l ≤ 10^9) — the number of lanterns and the length of the street respectively.

The next line contains n integers ai (0 ≤ a(i) ≤ l). Multiple lanterns can be located at the same point. The lanterns may be located at the ends of the street.

Output
Print the minimum light radius d, needed to light the whole street. The answer will be considered correct if its absolute or relative error doesn't exceed 10^-9.



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

double ar[1000];

int main()
{
	fast_io;
    // int t;
    // cin >> t;
    // while(t--) {
        int n,l;
        cin >> n >> l;
        FOR(i,n) cin >> ar[i];
        sort(ar,ar+n);
        double max_diff = ar[0];
        for(int i = 1; i< n; i++){
            if((ar[i]-ar[i-1])/2 > max_diff) max_diff = (ar[i]-ar[i-1])/2; 
        }
        if(l-ar[n-1] > max_diff) max_diff = l-ar[n-1];
        cout << setprecision(10) << fixed << max_diff;
    // }
}
