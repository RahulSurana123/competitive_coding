
/*

Solution by Rahul Surana

    ***********************************************************


JS newbie “A” wants to learn React from “B” and wants to know in his network who can introduce him to B in the shortest time period.

 

INPUT FORMAT

Total Members in UI Friend Network = N

MemberId1 = N1

MemberId2 = N2

MemberId3 = N3

MemberIdN = Nn

 

Total Possible Edges = E

<Follower 1> <Following 1> <Time taken to send the message> = p1,q1,t1

<Follower 2> <Following 2> <Time taken to send the message> = p2,q2,t2

<Follower 3> <Following 3> <Time taken to send the message> = p3,q3,t3

<Follower N> <Following N> <Time taken to send the message> = pn,qn,tn 

Follower (Ninja A) = A

Following (JS expert B) = B 

 

OUTPUT FORMAT

Shortest Time A takes to reach B



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

map<int,vector<pi>> adj;

int minimumCostSimplePath(int s, int d)
{
    map<int,int> dist;
    for(auto z: adj){
        dist[z.F] = INT_MAX;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push(make_pair(0, s));
    dist[s] = 0;

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist[d];
}

int main()
{
    fast_io;
    int e,n;
    cin >> e;
    FOR(i,e) { int f; cin >>f; adj[f] = vector<pi>(); }
    cin >> n;
    FOR(i,n) {
        int a,b,t;
        cin >> a >> b >> t; 
        adj[a-1].pb({b-1,t}); 
    }
    int x,y;
    cin >> x >> y;
    cout << minimumCostSimplePath(x-1,y-1) << "\n";
}