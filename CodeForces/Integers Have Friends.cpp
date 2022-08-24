

/* 

    Solution by Rahul Surana
    
    ***********************************************************


British mathematician John Littlewood once said about Indian mathematician Srinivasa Ramanujan that "every positive integer was one of his personal friends."

It turns out that positive integers can also be friends with each other! You are given an array a of distinct positive integers.

Define a subarray ai,ai+1,…,aj to be a friend group if and only if there exists an integer m≥2 such that aimodm=ai+1modm=…=ajmodm, where xmody denotes the remainder when x is divided by y.

Your friend Gregor wants to know the size of the largest friend group in a.

Input:

Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤2⋅104).
Each test case begins with a line containing the integer n (1≤n≤2⋅105), the size of the array a.
The next line contains n positive integers a1,a2,…,an (1≤ai≤1018), representing the contents of the array a. It is guaranteed that all the numbers in a are distinct.
It is guaranteed that the sum of n over all test cases is less than 2⋅105.

Output:

Your output should consist of t lines. Each line should consist of a single integer, the size of the largest friend group in a.



    ***********************************************************
*/



#include <bits/stdc++.h>
#define ll          signed long long
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

vector<ll> seg;

ll gcd(ll a, ll b)
{
    if (a==0)
    {
        return b;
    }
    return gcd(b%a, a);
}

void buildSegTree(vector<ll> &ar,ll v, ll tl, ll tr){
    if(tl==tr){
        seg[v] = ar[tl];
    }
    else{
        ll tm = (tl+tr)/2;
        buildSegTree(ar,2*v,tl,tm);
        buildSegTree(ar,2*v+1,tm+1,tr);
        seg[v] = gcd(seg[2*v],seg[2*v+1]);
    }
}

ll query(ll v, ll tl, ll tr, ll l, ll r){
    if(l>tr || r<tl) return -1;
    if(l == tl && r == tr) return seg[v];
    ll tm = (tl+tr)/2;
    ll v1 = query(2*v ,tl,tm, l, min(r,tm));
    ll v2 = query(2*v + 1,tm+1,tr, max(l,tm+1), r);
    if(v1 == -1) return v2;
    if(v2 == -1) return v1;
    return gcd(v1,v2);
}

int main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n ;  
        if (n==1)
        {
            ll x;
            cin >> x;
            cout << 1 << "\n";
            continue;
        }
        vector<ll> ar(n), di(n-1);
        seg.resize((4*n+4),0);
        FOR(i,n) { cin >>ar[i]; }
        for(int i = 0; i < n-1; i++){
            di[i] = abs(ar[i+1]-ar[i]);
        }
        buildSegTree(di,1,0,n-2);
        ll ans = 0;
        ll low=0,high=0;
        while(high<n-1){
            if(query(1,0,n-2,low,high) == 1){
                low++;
                high++;
            }
            else{
                ans = max(ans,high-low+1);
                high++;
            }
        }

        cout << ans + 1 << "\n";

    }
}
