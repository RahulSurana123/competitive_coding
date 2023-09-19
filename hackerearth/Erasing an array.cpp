

/* 

    Solution by Rahul Surana

    ***********************************************************

You are given a binary array A of N elements. The array consists of 0's and 1's. 
You can perform the following operations as many times as possible:

Select a subarray starting from the first index that is inversion-free and delete it.
Determine the minimum number of operations to delete the entire array.

Inversion free: There are no two indices i and j in array A such that i < j and ( A[i] > A[j] ). 
Subarray: A subarray is an array obtained after deleting some elements from the beginning (prefix) possibly 0 
and deleting some elements from the end (suffix) possibly 0.

Input format:

The first line contains an integer T denoting the number of test cases. 
The first line of each test case contains an integer N denoting the number of elements in array A.
The second line contains N space-separated integers of array A.

Output Format:

Print T lines and for each test case:
Print the minimum number of operations to delete the entire array.


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
#define fast_io     std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define MOD 1000000007 
using namespace std;
 
int ar[200001];
 
int main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        FOR(i,n) cin >> ar[i];
        int start = 0;
        int count = 0;
        while(start < n){
            while(start < n && ar[start] == 0) start++;
            while(start < n && ar[start] == 1) start++;
 
            count++;
        }
        cout << count <<"\n";
    }
}