

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
#define fast_io     std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;


int main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--) {
        ll x, a,b;
        cin >> x >> a >> b;
        // if(x%a != 0) { cout << "-1\n"; continue; }
        // auto z = [&](int g){
        //     int s = 0;
        //     double q = 0.0;
        //     for(int k = 1; k <= ceil(g/2); k++){
        //         if(g%k == 0) {
        //             s+= (k) + (g/k);
        //             q += (double)(1/(double)k) + (double)((double)k/g);
        //         }
        //     }
        //     // cout << g <<" "<< s <<" " << (double)q <<"\n";
        //     if(s == x && q == ((double)a/b)) return true;
        //     return false;
        // };
        // int ans = -1;
        // for(int i = 1; i < x; i++){
        //     // cout << z(i) <<" ";
        //     if(z(i)) {
        //         ans = i;
        //         break;
        //     }
        // }
        // cout << ans <<"\n";
        if(x%a != 0) { cout << "-1\n"; continue; }
        ll z = x/a;
        ll d = z*b;
        ll s = 0;
        for(int i = 1; i <= sqrtl(d); i++){
            if(s > x) break;
                // cout << z*a<< " "<< i + (b/i)<<" ";
            if(d%i == 0) {
                s += i;
                if((d/i) != i) s += (d/i) ;
             }
        }
        if(s!=x) cout << "-1\n";
        else cout << d << "\n"; 
    }
}
