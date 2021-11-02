#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll fac[1000000];

ll fact(ll a){
	if( a <= 1) return 1;
	if(fac[a] != -1) return fac[a]%MOD;
	return fac[a] = ((a%MOD) *(fact(a-1)% MOD))%MOD;
}

ll nCr(ll n, ll r){
	return ((fact(n)%MOD/(fact(r)%MOD * fact(n-r)%MOD)%MOD)%MOD);
}

int main() {

	ll n,m;
	cin >> n >> m;
	ll ar[n];
	ll r = m;
	for(ll i = 0; i< 1000000;i++) fac[i] = -1;
	for(int i =0;i<n;i++){
		cin>>ar[i];
		r-=ar[i];
	}
	if(r<=0) cout << 0;
	else {
		ll ans = 0;
		for(int i = 1; i <= r; i++){
			ans += nCr(n,r);
		}
		cout << ans;
	}
	return 0;
}
