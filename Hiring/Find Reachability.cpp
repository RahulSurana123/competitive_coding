

/*

Solution by Rahul Surana

    ***********************************************************


JS newbie “A” wants to check if he can reach out to a React expert “B” using his network of React developers. If he can then return 1 else return 0.

INPUT FORMAT

Total members in React Developer Community = N

MemberId1 = N1

MemberId2 = N2

MemberId3 = N3

MemberIdN = Nn

 

Total possible edges = E

<follower 1 (member ID)> <following 1 (member ID)> = u1,v1

<follower 2 (member ID)> <following 2 (member ID)> = u2,v2

……………… 

<follower N> <following N> = un , vn 

Follower = A

Following = B

 

OUTPUT FORMAT

If A can reach B then output is 1, else 0.



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

map<int,vector<int>> adj;
map<int, bool> v;

bool dfs(int s, int d){
    v[s] = true;
    if(s == d) return true;
    else{
        bool f = false;
        for(auto m : adj[s]){
            if(!v[m]) f = dfs(m,d);
            if(f) break;
        }
        return f;
    }
}

int main()
{
    fast_io;
    int e,n;
    cin >> e;
    FOR(i,e) { int f; cin >>f; adj[f] = vector<int>(); v[f] = false; }
    cin >> n;
    FOR(i,n) {
        int a,b;
        cin >> a >> b; 
        adj[a-1].pb(b-1); 
    }
    
    // for(auto x: adj){
    //     sort(x.S.begin(),x.S.end(),compare);
    // }

    int x,y;
    cin >> x >> y;
    cout << dfs(x-1,y-1) << "\n";
}