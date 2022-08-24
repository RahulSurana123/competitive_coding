

/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are given an integer array A consisting of N elements. You can perform the following operations on array A:

  Choose any element and increase or decrease it by 3 for 1 coin.
  Choose any element and increase or decrease it by 2 for free.

You are required to spend the minimum number of coins in order to make all the elements in array A equal.

Input format

The first line contains an integer T denoting the number of test cases. 
The first line of each test case contains an integer N denoting the number of elements in array A.
The second line of each test case contains N space-separated integers of array A.


Output format

Print  lines. For each test case, print a single line denoting the minimum number of coins to make all elements equal.


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
        int n;
        cin >> n;
        int ar[n];
        int e=0,o=0;
        FOR(j,n) { cin >> ar[j]; if (ar[j]%2==0) e++; else o++; }
        if(o>e) cout << e << "\n"; 
        else cout << o << "\n";

    }
}
