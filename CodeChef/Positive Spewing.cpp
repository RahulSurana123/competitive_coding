




/* 

    Solution by Rahul Surana

    ***********************************************************

A circular array of length N is defined as follows: N integers A1,A2,…,AN are placed in a circle in such a way that for each 1≤i<N, Ai and Ai+1 are adjacent, and A1 and AN are also adjacent.

You are given a circular array A of length N. At the end of each second, the following changes are executed in the array: If Ai>0 then the elements which are adjacent to Ai, will get incremented by 1, for all 1≤i≤N.

For example, consider the array A=[0,0,0,2,0,0,0,5].

Initially A4 and A8 are greater than zero. So after one second, A3, A5, A1 and A7 will get incremented by 1. Hence the array will become A=[1,0,1,2,1,0,1,5].

After two seconds, the array becomes A=[2,2,2,4,2,2,2,7]. Note that the value of A4 has become 4, because both, A3 and A5 were greater than zero after one second.

What will be the sum of elements present in the array A after K seconds?

Input Format:

The first line will contain T, number of testcases. Then T testcases follow.
The first line of each testcase contains 2 space separated integers N and K.
The second line of each testcase line contains N integers A1,A2,…,AN.

Output Format:

For each testcase, output in a single line containing the sum of the all the elements present in the array A after K seconds.



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


int main(){
	fast_io;
    int t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >>n>>k;

        int ar[n];
        int count = 0;
        vector<int> p;
        for(int i=0;i<n;i++){ cin >> ar[i]; if(ar[i]>0) { p.pb(i); count++; }}
        // FOR(i,n) cout << ar[i+1] << " ";
        while(count != n && k > 0){
            k--;
            int m = p.size();
            for(int i = 0; i < m; i++) {
                int x = p[i];
                if(x==0){
                    if(ar[x+1]==0)
                    p.push_back(x+1);
                    if(ar[n-1]==0)
                    p.push_back(n-1);
                    count+=(ar[x+1]==0);
                    count+=(ar[n-1]==0);
                    ar[1]++;
                    ar[n-1]++;
                }
                else if(x==n-1){
                    if(ar[0]==0)
                    p.push_back(0);
                    if(ar[n-2]==0)
                    p.push_back(n-2);
                    count+=(ar[n-2]==0);
                    count+=(ar[0]==0);
                    ar[n-2]++;
                    ar[0]++;
                }
                else{
                    if(ar[x+1]==0)
                    p.push_back(x+1);
                    if(ar[x-1]==0)
                    p.push_back(x-1);
                    count+=(ar[x+1]==0);
                    count+=(ar[x-1]==0);
                    ar[x-1]++;
                    ar[x+1]++;
                }
                // cout << x <<" ";
            }
            // cout << "\n";
            // cout << "\n";
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans+=ar[i];
        }
        cout << ans + (n*2*k)<< "\n";
    }

} 