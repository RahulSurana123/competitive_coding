

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

vector<int> ar;

bool p(int v, int i, int j, int k){
    FOR(s,i+1){
        FOR(t,j+1){
            if(s+2*t > v) continue;
            if((v-s-2*t)%3 != 0) continue;
            if((v-s-2*t)/3 <= k) return true;
        }
    }
    return false;
}

bool pp(int i, int j, int k){
    for(auto v: ar){
        if(!p(v,i,j,k)) return false;
    }
    return true;
}

int main()
{
	fast_io;
    int t=1;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int m = 0;
        int ans = 1e9;
        ar.resize(n);
        FOR(i,n) { cin >> ar[i]; m = max(ar[i],m); }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int k = max(0,(int)ceil((m-i-2*j)/3));
                if(pp(i,j,k)){
                    ans = min(ans,i+k+j);
                }
            }   
        }

        cout << ans <<"\n";
    }
}
