

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Alice has an array A of length N. She is interested in finding the number of pairs (i,j) such that 1≤i<j≤N and Ai⊕Aj<Ai&Aj.

⊕ represents the Bitwise XOR operator. & represents the Bitwise AND operator.

Input Format
The first line of input will contain an integer T — number of test cases. Then the test cases follow.
Each test case contains two lines of input.
The first line of each test case contains an integer N, the length of the array A.
The second line of each test case contains N space-separated integers A1,A2,…,AN.
Output Format
For each test case, output the number of pairs (i,j) such that 1≤i<j≤N and Ai⊕Aj<Ai&Aj.



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

ll fac(ll n){
    if(n<=1) return n;
    return n + fac(n-1);
}

int main()
{
	fast_io;
    int t;
    // for(int i = 0; i <= 10; i++){
    //     FOR(j,11){
    //         cout << ((i^j) < (i&j)) <<" ";
    //     }
    //     cout << "\n";
    // }
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ll ar[n];
        FOR(i,n) cin >> ar[i];
        sort(ar,ar+n);
        int i = 0,j = 0;
        // while(i < n && ar[i] <= 1) i++;
        ll ans = 0;
        while(i < n){
            int z = (log2(ar[i]));
            int c = 1;
            // cout << i <<" ";
            while(i+c < n && ((int)log2(ar[i])==(int)log2(ar[i+c]))) { c++;}
            ans += fac(c-1);
            i+=c;
        }
        cout << ans <<"\n";
    }
        // cout << ans <<"\n";
}
