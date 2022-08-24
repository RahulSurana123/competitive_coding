


/* 
    Solution by Rahul Surana
    
    ***********************************************************


In Olympics, the countries are ranked by the total number of medals won. 
You are given six integers G1, S1, B1, and G2, S2, B2, the number of gold, silver and bronze medals won by two different counties respectively. 
Determine which country is ranked better on the leaderboard. It is guaranteed that there will not be a tie between the two countries.

Input Format:

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains six space-separated integers G1, S1, B1, and G2, S2, B2.

Output Format:

For each test case, print "1" if the first country is ranked better or "2" otherwise. Output the answer without quotes.



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
        int g1,g2,s2,s1,b1,b2;
        cin >> g1>>s1>>b1 >>g2>> s2>>b2;
        int a = g1+s1+b1, b = g2+s2+b2;
        if(a>b) cout << "1 \n";
        else cout << "2 \n";

    }
}
