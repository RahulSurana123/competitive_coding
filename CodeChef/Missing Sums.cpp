

/* 

    Solution by Rahul Surana

    ***********************************************************

Given a positive integer N, construct an array A containing N distinct elements such that the sum of any two elements in the array (not necessarily different) is not present in the array.

That is, there have to be no such i,j,k such that

1≤i,j,k≤N
Ai+Aj=Ak.
The elements of the array A should be in the range [1,105]. It is guaranteed that such an array always exists under given constraints.

Input Format
First line of the input contains T, the number of test cases. Then the test cases follow.
Each test case contains a single positive integer N, the size of the array A.
Output Format
For each test case, print N space-separated integers in a single line, describing the contents of the array A.



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



int main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >>n;
        int j = 1;
        for(int i = 0 ; i < n ; i++){
            cout << j <<" ";
            j+=2;
        }
        cout << "\n";
    }
    
} 