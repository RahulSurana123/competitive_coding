

/*

Solution by Rahul Surana

    ***********************************************************




Traffic Lights: Shortest Route

You are given a roadmap of a country consisting of N cities and M roads. Each city has a traffic light. 
The traffic light has only 2 colors, Green and Red. 
All the traffic lights will switch their color from Green to Red and vice versa after every T seconds. 
You can cross a city only when the traffic light in the city is Green. Initially, all the traffic lights are Green. 
In a city, if the traffic light is Red, you have to wait for it to switch its color to Green. 
The time taken to travel through any road is C seconds. 
Find the route which will take the minimum amount of time (in seconds) required to move from city 1 to city N

It is guaranteed that the given roadmap will be connected. Graph won’t contain multiple edges and self-loops.

Note: Custom input is disabled for this contest.

Sample input 1

5 5 3 51 21 32 41 42 5

Sample output 1

31 2 5

Explanation

Input

The first line contains 4 space separated integers, N , M , T  and C  Next M lines contains two integers each, U and V denoting that there is a bidirectional road between U and V

Output

Print the minimum amount of time (in seconds) required to move from city 1 to city N


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

vector<vector<int>> adj;
int iNV(int target, vector<int>& path)
{
    int size = path.size();
    for (int i = 0; i < size; i++)
        if (path[i] == target)
            return 0;
    return 1;
}

vector<int> findPath(int s, int d, int t, int c){

    queue<vector<int>> q;
    vector<int> p;
    p.pb(s);
    q.push(p);
    while (!q.empty()) {
        p = q.front();
        q.pop();
        int last = p[p.size() - 1];
        
        if (last == d){
            return p;
        }       
        for (int i = 0; i < adj[last].size(); i++) {
            if (iNV(adj[last][i], p)) {
                vector<int> np(p);
                np.pb(adj[last][i]);
                q.push(np);
            }
        }
    }
    return vector<int>();
}

int main()
{
    fast_io;
    int n,e,t,c;
    cin >> n>>e>>t>>c;
    adj.resize(n+1,vector<int>());
    // FOR(i,n) { v[f] = false; }
    FOR(i,e) {
        int a,b;
        cin >> a >> b; 
        adj[a].pb(b);
        adj[b].pb(a); 
    }

    vector<int> path = findPath(1,n,t,c);
    // sort(path.begin(),path.end());
    int ans = 0;
    // ans += ((ans/t)*t);
    for(int i = 0; i < path.size()-1;i++){
        ans += c;
        if(i != path.size()-2)
        ans += (t-(ans % t));
    } 
    cout << ans << "\n";
    // for(auto x: path){
    //     cout << x <<" ";
    // }
    // cout << "\n";
}