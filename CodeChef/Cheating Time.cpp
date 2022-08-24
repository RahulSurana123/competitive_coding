

/* 

    Solution by Rahul Surana

    ***********************************************************

Chef's college is conducting an online exam, where his camera will be monitored by one or more invigilators (supervisors). 
Once again, Chef failed to prepare for the exam on time and decided to google answers during it.

The exam starts at time 0 and ends at time F minutes. Chef needs a total of K minutes of googling during the exam in order to pass it. There are N invigilators (numbered 1 through N); 
for each valid i, the i-th invigilator monitors Chef's camera during the time interval starting at Si minutes since the start of the exam and ending at Ei minutes (where 0≤Si≤Ei≤F). 
He was resourceful enough to somehow get hold of these times and now he wants to know if he would be able to pass the exam if he googles the answers during the times when no one is looking at his camera.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains three space-separated integers N, K and F.
N lines follow. For each valid i, the i-th of these lines contains two space-separated integers Si and Ei.

Output

For each test case, print a single line containing the string "YES" if it is possible to pass the exam or "NO" if it is impossible.
You may print each character of each string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).


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


vector<pi> ti, final;

bool compare(pi a, pi b){
    if(a.F == b.F) {
        return a.S < b.S;
    }
    return a.F < b.F;
}

void mergeIntervals()
{
    stack<pi> s;
    s.push(ti[0]);
 
    for (int i = 1 ; i < ti.size(); i++)
    {
        pi top = s.top();
        if (top.S < ti[i].F)
            s.push(ti[i]);
         else if (top.S < ti[i].S)
        {
            top.S = ti[i].S;
            s.pop();
            s.push(top);
        }
    }
    while (!s.empty())
    {
        pi t = s.top();
        final.pb(t);
        s.pop();
    }
}

int main()
{
    fast_io;
    
    int t;
    cin >> t;
    
    while(t--) {

        ll n,k,f;
        cin >> n >> k >> f;
        ll c = 0;
        ti.clear();
        final.clear();
        FOR(i,n) { int a,b; cin >> a >> b; ti.pb({a,b}); }
        sort(ti.begin(),ti.end(),compare);
        mergeIntervals();
        sort(final.begin(),final.end(),compare);
        // FOR(i,final.size()) cout << final[i].F << " "<< final[i].S << "\n";
        for(int i = 1; i < final.size(); i++){
            // cout << ti[i].F << " " << ti[i-1].S<<"\n";
            if(final[i].F - final[i-1].S > 0) { c += final[i].F - final[i-1].S; }
        }
        if(f - final[final.size()-1].S > 0) {  c += f - final[final.size()-1].S; }
        if(final[0].F > 0) {  c += final[0].F; }
        if(c >= k) cout << "YES\n";
        else cout << "NO\n";
    }
} 