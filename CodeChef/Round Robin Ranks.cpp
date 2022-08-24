

/* 
    Solution by Rahul Surana
    
    ***********************************************************


A round-robin tournament is being held in Chefland among N teams numbered 1,2,...,N. 
Every team play with all other teams exactly once. All games have only two possible results - win or loss. 
A win yields 2 points to the winning team while a loss yields no points. 
What is the maximum number of points a team finishing at the Kth position can score?

Note: If two teams have the same points then the team with the higher team number achieves the better rank.

Input Format
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains a single line of input, two space-separated integers N,K.
Output Format
For each testcase, output in a single line an integer - the maximum points the team 
ranked K in the round-robin tournament can score.



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
        ll n,k;
        cin >> n >> k;
        ll max = ((n) * (n-1)) /2;
        ll wk = ((n-k) * (n-k-1))/2;
        ll g = (max - wk)/k;
        // cout << max <<" "<< wk <<" "<<h<<"\n";
        ll ans = (g) * 2; 
        cout << ans << "\n";

    }
}
