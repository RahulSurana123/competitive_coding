

/* 

    Solution by Rahul Surana

    ***********************************************************

Chef is playing a game where he has an array A of N integers, and an integer K. He looks at every subarray of length K, and writes its sum on a piece of paper. 
If a number appears as the sum of multiple subarrays of length K, then he only writes down that number once.

Chef is lazy and doesn't like to write numbers. You, being a friend of Chef, want to modify the array such that Chef will only write one number on his paper. 
In one modification you can choose any index i and replace Ai with any integer.

You need to find the minimum number of modifications required.

Input

The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains two lines of input.
The first line contains two space-separated integers N, K.
The second line contains N space-separated integers A1,A2,…,AN.

Output

For each test case, output the answer in a single line.


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

int ar[100001];

int main()
{
    fast_io;
    
    
    ll t;
    cin >> t;
    
    while(t--) {

        ll n, k,ans = 0;
        cin >> n >> k;
        FOR(i,n) cin >> ar[i];
        for(int i = 0; i <k; i++){
            map<int,int> m;
            m[ar[i]]++;
            int j = i;
            ll count = 1;
            while(j+k<n) { m[ar[j+k]]++; j+=k; count++; }
            int c = 0;
            for(auto x : m){
                c = max(c,x.S);
            }
            ans += (count-c);
        }
        cout << ans << "\n";
    }
} 