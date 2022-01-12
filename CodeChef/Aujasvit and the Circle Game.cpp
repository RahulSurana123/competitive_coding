

/* 
    Solution by Rahul Surana
    
    ***********************************************************





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




int main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--) {
        int m,x;
        cin >> m >> x;
        m--;
        vector<int> ans(x);
        ans[0] = 1;
        
        for(int i = 1; i < x; i++){
            int z = (m%(i+1)) +1;
            if(ans[i-1]<z)ans[i] =ans[i-1];
            else ans[i] = ans[i-1]+1; 
        }
        for(int k = 0; k < x; k++) cout << ans[k] <<" ";
        cout <<"\n";
    }
}
