

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array a of length n.

Let's define the eversion operation. Let x=an. Then array a is partitioned into two parts: left and right. The left part contains the elements of a that are not greater than x (≤x). The right part contains the elements of a that are strictly greater than x (>x). The order of elements in each part is kept the same as before the operation, i. e. the partition is stable. Then the array is replaced with the concatenation of the left and the right parts.

For example, if the array a is [2,4,1,5,3], the eversion goes like this: [2,4,1,5,3]→[2,1,3],[4,5]→[2,1,3,4,5].

We start with the array a and perform eversions on this array. We can prove that after several eversions the array a stops changing. Output the minimum number k such that the array stops changing after k eversions.

Input:

Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100). Description of the test cases follows.
The first line contains a single integer n (1≤n≤2⋅105).
The second line contains n integers a1,a2,…,an (1≤ai≤109).
It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output:

For each test case print a single integer k — the number of eversions after which the array stops changing.



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


int ar[200001];

int compare(int a, int b){
    return ar[a] < ar[b];
}

int main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        FOR(i,n)  cin >> ar[i]; 
        ll ans = 0;
        // j = in[j];
        // cout << ans << " " << c <<" "<< j <<"\n";
        // if(ar[n-1] == )
        ll maxx = ar[n-1];
        for(int j = n-1;j >=0; j--){
            if(ar[j] > maxx) {
                maxx = ar[j];
                ans++;
            } 
        }
        cout << ans <<"\n";
    }
}
