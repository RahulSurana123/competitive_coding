

/* 
    Solution by Rahul Surana
    
    ***********************************************************

Sarthak got an empty magic grid of size N×N on his birthday. The grid can only be filled with positive integers such that the bitwise XOR of all numbers from any row, any column, or any of the two main diagonals must all be the same! Can you help Sarthak fill this grid using only positive integers no more than 109?

Input Format

The first line of each input contains T - the number of test cases. The test cases then follow.
The only line of each test case contains an integer N - the size of the grid.

Output Format

For each test case, output N lines, each containing N space-separated integers, such that the grid satisfies the condition given in the statement.

Each integer should be positive and ≤109.



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
        int n;
        cin >> n;
        FOR(i,n) { FOR(j,n){ cout << "1 "; } cout <<"\n"; }
    }
}
