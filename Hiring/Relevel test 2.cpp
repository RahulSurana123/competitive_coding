#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;


int main() {

	ll n,k;
	cin >> n >> k;
	ll m = 0;
	k--;
	for(int i =0;i<n;i++){
		ll x;
		cin>>x;
		m = max(m,x); 
	}
	int ans = 0;
	while(m >= 0){
		if(m <= 0) break;
		m-=k;
		ans++;
	}
	cout << ans;
	return 0;
}
