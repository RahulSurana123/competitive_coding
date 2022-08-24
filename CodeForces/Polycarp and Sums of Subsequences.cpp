

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Polycarp had an array a of 3 positive integers. He wrote out the sums of all non-empty subsequences of this array, sorted them in non-decreasing order, and got an array b of 7 integers.

For example, if a={1,4,3}, then Polycarp wrote out 1, 4, 3, 1+4=5, 1+3=4, 4+3=7, 1+4+3=8. After sorting, he got an array b={1,3,4,4,5,7,8}.
Unfortunately, Polycarp lost the array a. He only has the array b left. Help him to restore the array a.

Input:

The first line contains one integer t (1≤t≤5000) — the number of test cases.
Each test case consists of one line which contains 7 integers b1,b2,…,b7 (1≤bi≤109; bi≤bi+1).
Additional constraint on the input: there exists at least one array a which yields this array b as described in the statement.

Output:

For each test case, print 3 integers — a1, a2 and a3. If there can be several answers, print any of them.



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
        // int n;
        // cin >> n;
        ll ar[7];
        FOR(i,7)  { cin >> ar[i]; }
        ll a = ar[0],c = ar[1];
        ll b = ar[6] - a - c;
        cout << a <<" "<<b<<" "<<c <<"\n";
    }
}
