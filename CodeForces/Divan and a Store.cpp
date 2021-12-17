

/* 
    Solution by Rahul Surana
    
    ***********************************************************


There is a frog initially placed at the origin of the coordinate plane. In exactly 1 second, the frog can either move up 1 unit, move right 1 unit, or stay still. 
In other words, from position (X,Y), the frog can spend 1 second to move to:

-> (X,Y)
-> (X+1,Y)
-> (X,Y+1)

After T seconds, a villager who sees the frog reports that the frog lies on or inside a square of side-length S with coordinates (X,Y),(X+s,Y) ,(X,Y+S) ,(X+S,Y+S). 
Calculate how many points with integer coordinates on or inside this square could be the frog's position after exactly T seconds

Input Format:

The first and only line of input contains four space-separated integers: X, Y, S, and T.

Output Format:

Print the number of points with integer coordinates that could be the frog's position after T seconds.


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


int main()
{
    fast_io;
    int t=1;
    cin >> t;
    while(t--){
        
        int n,l,r,k;
        cin >> n>>l>>r>>k;
        int ar[n];
        FOR(i,n) cin >> ar[i];
        sort(ar,ar+n);
        int ans = 0;
        int s = 0;
        for(int i = 0;i < n;i++){
            if(ar[i]>=l && ar[i] <= r && s+ar[i] <= k) { 
                s+=ar[i]; 
                ans++; 
            }
        }

        cout << ans<<"\n";
    }
}