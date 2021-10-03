


/* 
    Solution by Rahul Surana
    
    ***********************************************************

    
You are given 2 integers N and M. Let g(i) denotes the number of divisors of i, that is count of positive numbers dividing i. Your task is to find the sum:
 
        ∑ [i -> (1,N)] i^M g(i)


Since the answer can be very large, you are required to print it modulo  10^9 + 7.

Input format:

The first line contains a single integer  denoting the number of test cases.
For each test case:
The first and only line contains 2 space-separated integers  and .

Output format:

For each test case, print the sum modulo   in a separate line.


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
#define fast_io 	std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define MOD 1000000007 

using namespace std;

const int mod = 1e9 + 7;
const int B = 1e6 + 10;
int sum[B];
int n, k;
 
int add(int a, int b) {
  return a+b<mod?a+b:a+b-mod;
}
 
using ll = long long;
int mul(ll a, ll b) {
  return a*b%mod;
}
 
int ex(int a, int b) {
  int r = 1;
  while (b > 0) {
    if (b&1) r = mul(r, a);
    a = mul(a, a);
    b >>= 1;
  }
  return r;
}
 
int f[1010], fn[1010], ri[1010];
void prep() {
  for (int i = 1; i < B; ++i) {
    sum[i] = add(sum[i-1], ex(i, k));
  }
  f[0] = fn[0] = 1;
  ri[1] = 1;
  for (int i = 1; i < k + 5; ++i) {
    if (i > 1) ri[i] = mul(ri[mod%i], mod-mod/i);
    f[i] = mul(f[i-1], ri[i]);
    fn[i] = mul(fn[i-1], mod - ri[i]);
  }
}
 
int l[1010], r[1010];
int sum_n(int n) {
  if (n < B) return sum[n];
  l[0] = 1;
  for (int i = 1; i <= k+2; ++i) {
    l[i] = mul(l[i-1], add(n, mod - i + 1));
  }
  r[k+3] = 1;
  for (int i = k+2; i >= 1; --i) {
    r[i] = mul(r[i+1], add(n, mod - i + 1));
  }
  int ans = 0;
  for (int i = 1; i <= k+2; ++i) {
    int tmp = sum[i-1];
    tmp = mul(tmp, l[i-1]);
    tmp = mul(tmp, r[i+1]);
    tmp = mul(tmp, f[i-1]);
    tmp = mul(tmp, fn[k+2-i]);
    ans = add(ans, tmp);
  }
  return ans;
}
 
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    prep();
    int ans = 0;
    for (int i = 1, la; i <= n; i = la + 1) {
      la = n / (n / i);
      //n / x yields the same value for i <= x <= la.
      ans = add(ans, mul(sum_n(n/i), add(sum_n(la), mod - sum_n(i-1))));
    }
    cout << ans << endl;
  }
  return 0;
}