
/* 

    Solution by Rahul Surana

    ***********************************************************


Not a long time ago Y wasn't a prisoner and he had a lot of friends (n friends). 
His friends are going to plan a date in upcoming 10^6 days as soon as possible 
in a day that none of them are busy in that day.

His ith friend is busy in m intervals of days:

His ith friend is busy from l1 th to r1 th day (includes both  l1th and  r1tth day), 
also he/she is busy from  l2 th to r2 th day also .... from th to th day.
.
What is the earliest day that none of his friends are busy?

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
int inf=1e9+7,MOD=1e9+7;
bool v[1000001],f;
vector<pi> ar;
vector<pi> act;
int main()
{
	fast_io;
    int n;
    cin >> n;
    mem(v,0);
    v[0] = true;
    FOR(i,n){
        int m;
        cin >> m;
        FOR(j,m){
            int a,b;
            cin>>a>>b;
            ar.pb({a,b});        
        }
    }
    sort(ar.begin(),ar.end());
    act.pb(ar[0]);
    for(int i = 1;i<ar.size();i++){
        if (act[act.size()-1].S<ar[i].F){
            act.pb(ar[i]);
            // cout << act[i].F <<" " << act[i].S<<"\n";
        }
        else if(act[act.size()-1].S<ar[i].S){
            act[act.size()-1].S = ar[i].S;
            // cout << act[act.size()-1].F <<" " << act[act.size()-1].S<<"\n";
        }
        else if(ar[i].F<=act[act.size()-1].S){
            act[act.size()-1].S = ar[i].S;
            // cout << act[i-1].F <<" " << act[i-1].S<<"\n";
        }
        
    }
    // cout << m.F <<" " << m.S<<"\n";
    for(pi m : act){  for(int k = m.F;k<=m.S;k++) v[k] = 1;}

    FOR(i,1000001) {if (!v[i]) {cout<<i; f=true; break;}} 
    if (!f) cout << -1;

}