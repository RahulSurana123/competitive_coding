

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array a of n integers, and another integer k such that 2k≤n.

You have to perform exactly k operations with this array. In one operation, you have to choose two elements of the array (let them be ai and aj; they can be equal or different, but their positions in the array must not be the same), remove them from the array, and add ⌊aiaj⌋ to your score, where ⌊xy⌋ is the maximum integer not exceeding xy.

Initially, your score is 0. After you perform exactly k operations, you add all the remaining elements of the array to the score.

Calculate the minimum possible score you can get.

Input:

The first line of the input contains one integer t (1≤t≤500) — the number of test cases.
Each test case consists of two lines. The first line contains two integers n and k (1≤n≤100; 0≤k≤⌊n2⌋).
The second line contains n integers a1,a2,…,an (1≤ai≤2⋅105).

Output:

Print one integer — the minimum possible score you can get.



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
        int n,k;
        cin >> n>>k;
        vector<int> ar(n);
        // ,vector<int>,greater<int>>
        // priority_queue<int> q;
        FOR(i,n)  { 
            cin >> ar[i]; 
            // q.push(ar[i]); 
        }
        sort(ar.begin(),ar.end());
        ll ans = 0;
        for(int i = n-1; i > n-k-1; i--) ans += (ar[i-k]/ar[i]);
        for(int i = n-(2*k)-1; i>=0; i--) ans+=ar[i];
        cout << ans << "\n";
    }
}
