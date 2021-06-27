

/* 

    Solution by Rahul Surana

    ***********************************************************

Chef is given a sequence of prime numbers A1,A2,…,AN. This sequence has exactly 2N subsequences. A subsequence of A is good if it does not contain any two identical numbers; 
in particular, the empty sequence is good.

Chef has to find the number of good subsequences which contain at most K numbers. Since he does not know much about subsequences, help him find the answer. 
This number could be very large, so compute it modulo 1,000,000,007.

Input
The first line of the input contains two space-separated integers N and K.
The second line contains N space-separated integers A1,A2,…,AN.
Output
Print a single line containing one integer ― the number of good subsequences with size at most K, modulo 1,000,000,007.


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

vector<int> ar(8001,0);
vector<int> primes;

void makeCombiUtil(vector<vector<int> >& ans,
    vector<int>& tmp, int n, int left, int k)
{
    if (k == 0) {
        ans.push_back(tmp);
        return;
    }

    for (int i = left; i < n; ++i)
    {
        tmp.push_back(i);
        makeCombiUtil(ans, tmp, n, i + 1, k - 1);
  
        // Popping out last inserted element
        // from the vector
        tmp.pop_back();
    }
}
  
// Prints all combinations of size k of numbers
// from 1 to n.
vector<vector<int> > makeCombi(int n, int k)
{
    vector<vector<int>> ans;
    vector<int> tmp;
    makeCombiUtil(ans, tmp, n, 0, k);
    return ans;
}

int main()
{
    fast_io;
    
    // int t;
    // cin >> t;
    
    // while(t--) {

    int n,k; 
    cin >> n >> k; 
    FOR(i,n) { int x; cin >> x; ar[x]++; }
    FOR(i,8001){ if(ar[i]>0) primes.pb(ar[i]); }
    ll ans = 1;
    for(int i = 1; i <= k; i++){
        vector<vector<int>> inds = makeCombi(primes.size(),i);
        FOR(j, inds.size()){
            ll s = 1;
            FOR(z,inds[j].size()){
                // cout << inds[j][z] << " ";
                s = (s%MOD * primes[inds[j][z]]%MOD) %MOD;
            }
            cout << "\n";
            ans = (ans%MOD + s%MOD) %MOD;
        }
    }
    cout << ans%MOD << "\n";
    // }

}