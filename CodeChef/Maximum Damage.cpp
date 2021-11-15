

/* 

    Solution by Rahul Surana

    ***********************************************************

Nasir and two of his henchmen are planning to attack N shops of the Qureshi clan. 
The shops are conveniently lined up, and numbered from 1 to N. The i-th shop contains Ai kg of coal.

For a given subarray of shops [AL,AL+1,…,AR], the bitwise and of this subarray is defined to be the 
bitwise AND of the coal contained in each of the shops, i.e, AL&AL+1&…&AR.

The damage caused when bombing the i-th shop is computed to be the maximum bitwise 
and over all subarrays containing shop i, and whose size is strictly larger than 1.

For each shop (1≤i≤N), find the damage caused when Nasir bombs it.

Input Format:

The first line of input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N, denoting the number of shops.
The second line of each test case contains N space-separated integers, 
the i-th of which is Ai, representing the amount of coal in the i-th shop.

Output Format:

For each test case, print a single line containing N integers d1,d2,…,dn 
where di represents the maximum damage that can be caused if the i-th shop is to be bombed.



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
#define MOD 1000000007 
using namespace std;


ll gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}


int main()
{
    fast_io;
    
    int t;
    cin >> t;
    
    while(t--) {

        int n;
        cin >> n ;
        int ar[n];
        int ans[n];
        FOR(i,n) cin >> ar[i];
        FOR(i,n){
            if(i==0) ans[i] = ar[i]&ar[i+1];
            else if(i==n-1) ans[i] = ar[i]&ar[i-1];
            else{
                ans[i] = max(ar[i]&ar[i-1],ar[i]&ar[i+1]);
            }
        }
        FOR(i,n) cout<< ans[i]<<" ";
        cout<<"\n";

    }
} 