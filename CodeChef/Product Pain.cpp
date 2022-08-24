

/* 

    Solution by Rahul Surana

    ***********************************************************

For a given array B1,B2,…,BM of length at least 3, let's define its weight as the largest value of 
(Bi−Bj)⋅(Bj−Bk) over all possible triples (i,j,k) with 1≤i,j,k≤M and i≠j,j≠k,k≠i.

You are given a sorted array A1,A2,…,AN (that is, A1≤A2≤…≤AN).

Calculate the sum of weights of all contiguous subarrays of A of length at least 3. 
That is, count the sum of weights of arrays [Ai,Ai+1,…,Aj] over all 1≤i<j≤N with j−i≥2.

Input Format:

The first line of input contains a single integer T denoting the number of test cases. 
The description of T test cases follows.
The first line of each test case contains an integer N.
The second line of each test case contains N space-separated integers A1,A2,…,AN.

Output Format:

For each test case, print a single line containing the sum of weights of all subarrays of A of length at least 3.



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

ll arr[3001];

int main(){
    fast_io;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >>n;
        FOR(i,n) cin >> arr[i];
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ll maxx = arr[i], minn = arr[i];
            set<ll> s;
            for(ll j=i;j<n;j++){
                s.insert(arr[j]);
                maxx=max(maxx,arr[j]);
                minn=min(minn,arr[j]);
                if(j-i<2)
                    continue;
                ll x=0;
                auto pos=s.lower_bound((maxx+minn)/2);
                if(pos!=s.end()){
                    x=max(x,(maxx-(*pos))*((*pos)-minn));
                }
                if(pos!=s.begin()){
                    pos--;
                    x=max(x,(maxx-(*pos))*((*pos)-minn));
                }
                ans+=x;
            }
        }
        cout << ans << "\n";

    }
    
} 