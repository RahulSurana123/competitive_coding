
/* 

    Solution by Rahul Surana

    ***********************************************************

Problem
While the most typical type of dice have 6 sides, each of which shows a different integer 1 through 6, there are many games that use other types. In particular, a dk is a die with k sides, each of which shows a different integer 1 through k. A d6 is a typical die, a d4 has four sides, and a d1000000 has one million sides.

Dice from sample case 1

In this problem, we start with a collection of N dice. The i-th die is a dSi, that is, it has Si sides showing integers 1 through Si. A straight of length ℓ starting at x is the list of integers x,x+1,…,x+(ℓ−1). We want to choose some of the dice (possibly all) and pick one number from each to form a straight. What is the longest straight we can form in this way?

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case is described in two lines. The first line of a test case contains a single integer N, the number of dice in the game. The second line contains N integers S1,S2,…,SN, each representing the number of sides of a different die.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the maximum number of input dice that can be put in a straight.


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
#define FOR(i,n) for(int i = 0; i < n; i++)
#define trace(x)    cerr<<#x<<" : "<<x<<endl;
#define trace2(x,y) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<" | "<<#z<<" : "<<z<<endl;
#define fast_io 	std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;

int MOD=1e9+7;


int main()
{
	fast_io;
    int t,w = 1;
    cin >> t;
    while(t >= (w)){
        int n;
        cin >> n;
        vector<int> ar(n);
        FOR(i,n) cin >> ar[i];
        sort(ar.begin(),ar.end());
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(ar[i] > ans) ans++;
        }
        // cout <<  c[0] <<" "<<c[1]<<" "<<c[2] <<" "<<c[3] <<"\n";
        // int ans = 1e6;
        // vector<int> p(4,0);
        cout << "Case #" << w << ": "<< ans <<"\n";
        // if(ans > 0) { p[0] = min(c[0],ans); ans -= p[0]; }
        // if(ans > 0) { p[1] = min(c[1],ans); ans -= p[1]; }
        // if(ans > 0) { p[2] = min(c[2],ans); ans -= p[2]; }
        // if(ans > 0) { p[3] = min(c[3],ans); ans -= p[3]; }
        // if(ans > 0) {
        //  	cout << "IMPOSSIBLE"<<"\n";
        // }
        // else{
        // 	cout << p[0] <<" "<<p[1]<<" "<<p[2] <<" "<<p[3] <<"\n";
        // }
        w++;
    }
        
}