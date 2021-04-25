
/* 


    Solution by Rahul Surana
    
    
    ***********************************************************



You are given an array A of N integers. Find the smallest index i (1 <= i <= N - 1) such that:

 ->   mex(A[1], A[2], ..., A[i]) = mex(A[i+1], A[i+2], ..., A[N])

If no such index exists, print -1.

Input format

The first line contains an integer T denoting the number of test cases.
For each test case:-
The first line of each test case contains an integer N denoting the number of elements in array A.
The second line contains N space-separated integers denoting the elements of the array.
Output format

For each test case in a new line, print the smallest index satisfying the condition.

Note

->  1-based Indexing is followed.
->  mex of an array of elements is defined as the minimum non-negative number missing from the array.


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

int ar[100000];

int mes(int s, int e){
    set<int> tracker;
    for(int i = s; i <= e; i++){
        tracker.insert(ar[i]);
    }
    int x = 1;
    while(tracker.count(x)) x++;
    return x;
}

int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ml[n],mf[n];
        FOR(i,n) { cin >> ar[i]; ml[i] = 0 ; mf[i] = 0; }
        set<int> tracker;
        int x = 0;
        
        for(int i = 0; i < n-1; i++) {
            if(ar[i] > x) { tracker.insert(ar[i]); mf[i] = x; } 
            else if(ar[i] == x) {
                x+=1;
                while(tracker.count(x)) { tracker.erase(x); x+=1; }
                mf[i] = x;
            }
            else {
                mf[i] = x;
            }
            // cout << mf[i] << " ";
        }
        
        x = 0;
        tracker.clear();
        
        for(int i = n - 1; i > 0; i--) {
            if(ar[i] > x) { tracker.insert(ar[i]); ml[i] = x; } 
            else if(ar[i] == x) {
                x+=1;
                while(tracker.count(x)) { tracker.erase(x); x+=1; }
                ml[i] = x;
            }
            else {
                ml[i] = x;
            }
        }        
        // //  cout << "\n";
        // // FOR(i,n) cout << ml[i] << " ";
       
        int ans = -1; 
        for(int i = 0; i < n-1; i++) {
            if(mf[i] == ml[i+1]) { ans = i+1; break; }
        }
        // Attempt 2
        // for(int i = 0; i < n; i++){
        //     int x = 1;
        //     for(int j = 0; j < i+1; j++) {
        //         tracker.insert(ar[j]);
        //     }
        //     while(tracker.count(x)) x+=1;
        //     tracker.clear();
        //     int y = 1;
        //     for(int j = i+1; j < n; j++) {
        //         tracker.insert(ar[j]);
        //     }
        //     while(tracker.count(y)) y+=1;
        //     if(y == x) { ans = i+1; break; }
        //     tracker.clear();
        //     // cout << x <<" "<< y <<" ";
        // }
        cout << ans << "\n";
    }
}

