#include<bits/stdc++.h>
 
using namespace std;
#define ll long long int
 
int main()
{
    ll n;
    cin>>n;   
    vector<ll>dp(n+1,INT_MAX);
    dp[0] = 0;
    for(int i=1;i<n+1;i++)
    {
        for(char c:to_string(i))
        {
            dp[i] = min(dp[i],dp[i-(c-'0')]+1);
        }
    }
    cout<<dp[n]<<endl;
    
    return 0;
}
