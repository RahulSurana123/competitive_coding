
/* 


    Solution by Rahul Surana
    
    ***********************************************************

    You are given an array A of length N and can perform the following operation on the array:

Select a subarray from array A having the same value of elements and decrease the value of all the elements in that subarray by any positive integer x.
Find the minimum number of operations required to make all the elements of array A equal to zero.

Input format

The first line contains an integer N denoting the number of elements in the array.
The next line contains space-separated integers denoting the elements of array A.
Output format

Print the minimum number of operations required to make all the elements of array A equal to zero.



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
    int n;
    cin >> n;
    
    int ar[n];
    FOR(i,n) cin >> ar[i];
    int count = 1;
    for(int i = 1; i < n; i++) {
        if(ar[i-1] != ar[i]) count++;
    }
    cout << count;
}
