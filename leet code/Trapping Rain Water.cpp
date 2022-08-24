


/* 

    Solution by Rahul Surana

    ***********************************************************

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:

    |            ___
    |    ___    |   |___     ___
    |   |   |~~~|       |~~~|   |
------------------------------------
    |

Input: height = [0,1,0,2,1,0,1]
Output: 2
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1]. In this case, 2 units of rain water (blue section) are being trapped.


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


int trap(vector<int>& height) {
    int n = height.size();
    if(n<=2) return 0;
    vector<int> prefix(n,0), suffix(n,0);
    prefix[0] = height[0];
    for(int i = 1; i < n; i++){
        prefix[i] = max(height[i],prefix[i-1]);
    }
    suffix[n-1] = height[n-1];
    for(int i = n-2; i >=0 ; i--){
        suffix[i] = max(height[i],suffix[i+1]);
    }
    int ans = 0;
    for(int i = 1; i < n-1; i++){
        ans+= min(prefix[i],suffix[i]) - height[i];
    }
     return ans;
}

int main()
{
    fast_io;
    int n;    
    vector<int> ar(n,0);
    FOR(i,n) cin >> ar[i];
    cout << trap(ar)<<"\n";

}