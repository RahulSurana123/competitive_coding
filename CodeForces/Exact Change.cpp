

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array a1,a2,…,an consisting of integers from 0 to 9. A subarray al,al+1,al+2,…,ar−1,ar is good if the sum of elements of this subarray is equal to the length of this subarray (∑i=lrai=r−l+1).

For example, if a=[1,2,0], then there are 3 good subarrays: a1…1=[1],a2…3=[2,0] and a1…3=[1,2,0].

Calculate the number of good subarrays of the array a.

Input
The first line contains one integer t (1≤t≤1000) — the number of test cases.

The first line of each test case contains one integer n (1≤n≤105) — the length of the array a.

The second line of each test case contains a string consisting of n decimal digits, where the i-th digit is equal to the value of ai.

It is guaranteed that the sum of n over all test cases does not exceed 105.

Output
For each test case print one integer — the number of good subarrays of the array a.



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

vector<int> dp;

int df(vector<int>& n, int x, int y, int z){
    // if(n < 0) return INT_MAX;
    bool f = true;
    FOR(i,n.size()){
        if(x>0){
            if(n[i] % 3 == 2 && (y>0 || z > 1) ) f = false;
            if(n[i] % 3 == 1 && z<1) f = false;
        }
    }
    if(0 == n) return dp[n] = x+y+z;
    if(dp[n] != -1) return dp[n];
    int a = INT_MAX;
    a = min(a,df(n-3,x+1,y,z));
    a = min(a,df(n-2,x,y+1,z));
    a = min(a,df(n-1,x,y,z+1));
    return dp[n] = a;
}


int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> ar(n);
        int maxx = 0;
        FOR(i,n) { cin >> ar[i]; maxx = max(maxx,ar[i]); }
        dp.clear();
        dp.resize(maxx+1,-1);
        df(ar,0,0,0);
        cout << dp[0] <<"\n";
    }
}
