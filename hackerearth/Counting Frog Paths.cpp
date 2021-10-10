

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

vector<vector<int>> v;

int df(int x,int y,int s, int t, int i, int j){
    if(t == -1) return 0;
    if(i > x+s || j > y+s) return 0;
    if(v[i][j]) return 0;
    v[i][j] = 1;
    int ans = 0;
    ans += df(x,y,s,t-1,i+1,j);
    ans += df(x,y,s,t-1,i,j+1);
    if(i >= x && i <= x+s && j >=y && j <= y+s) ans++;
    // ans += df(x,y,s,t,i+1,j);
    return ans;
}


int main()
{
    fast_io;
    int t,s,x,y;
    cin >> x>>y>>s>>t;
    v.resize(x+s+1,vector<int>(y+s+1,0));
    // if((s+1)*(s+1) < t) cout << (s+1)*(s+1) <<"\n";
    // else if(s == 0 || t == 0) cout << "1\n";
    // else cout << t <<"\n";
    // while(t--) {
    //     int n,k;
    //     cin >> n >> k;
    cout << df(x,y,s,t,0,0)<<"\n";
    // }
}