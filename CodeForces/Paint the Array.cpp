

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array a consisting of n positive integers. You have to choose a positive integer d and paint all elements into two colors. All elements which are divisible by d will be painted red, and all other elements will be painted blue.

The coloring is called beautiful if there are no pairs of adjacent elements with the same color in the array. Your task is to find any value of d which yields a beautiful coloring, or report that it is impossible.

Input:

The first line contains a single integer t (1≤t≤1000) — the number of testcases.
The first line of each testcase contains one integer n (2≤n≤100) — the number of elements of the array.
The second line of each testcase contains n integers a1,a2,…,an (1≤ai≤1018).

Output:

For each testcase print a single integer. If there is no such value of d that yields a beautiful coloring, print 0. Otherwise, print any suitable value of d (1≤d≤1018).



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
 
using namespace std;


// int ar[200001];

// int compare(int a, int b){
//     return ar[a] < ar[b];
// }

int main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> ar(n);
        FOR(i,n)  { cin >> ar[i]; }
        // if(n == 1) { cout << ar[0] <<"\n"; continue; } 
        // if(n == 2) { cout << max(ar[0],ar[1]) <<"\n"; continue; } 
        ll a = ar[0],b = ar[1];
        for(int i = 2; i < n; i++){
            if(i%2){
                b = __gcd(b,ar[i]);
            }
            else {
                a = __gcd(a,ar[i]);
            }
        }
        bool f1 = false,f2 = false;
        for(int i = 0; i < n; i+=2){
            if(ar[i] % b == 0) f1= true;
        }
        for(int i = 1; i < n; i+=2){
            if(ar[i] % a == 0) f2= true;
        }
        if(!f1) cout << b <<"\n";
        else if(!f2) cout << a <<"\n";
        else{
            cout <<"0\n"; 
        }
    }
}
