

/* 

    Solution by Rahul Surana

    ***********************************************************


You are given an integer N. To solve the problem, 
you must find the minimum number of elements that must be removed from the set S = { 1, 2, ..., N } such that the bitwise XOR of the remaining elements is 0.

Input

The first line contains an integer t (1 <= t <= 10^5) representing the number of test cases.
The first and only line of each test case contains an integer N (1 <= N <= 10^9) representing the number presented to you.

Output

For each test case, print a single line. With total no of element removed followed by the no to be removed in descending order.


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

// int ar[1000000001];

// bool isPowerOfTwo(int n)
// {
//    if(n==0)
//    return false;
 
//    return (ceil(log2(n)) == floor(log2(n)));
// }

// bool stopprint(int n){
//     if(n < 3) return false;
//     return isPowerOfTwo(n-1);
// }

int main()
{
	fast_io;
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ans;
        switch(n%4){
            case 0:
                ans = n;
                cout << 1 <<" ";
                break;
            case 1:
                ans = 1;
                cout << 1 <<" ";
                break;
            case 2:
                ans = n+1;
                cout << 2 <<" ";
                break;
            case 3:
                ans = 0;
                cout << 0 <<" ";
                break;
        } 
        int m = n;
        while(ans > 0){
            if(ans<n) { cout << ans << " "; ans -= ans; }
            else {
                cout << m << " ";
                ans -= m;

            }
        }
        cout << "\n";
    }
}