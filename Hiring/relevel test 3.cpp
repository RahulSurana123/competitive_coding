#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;


int main() {

	int t;
	cin >>t;
	while(t--){
		ll x,y;
		cin >> x >> y;
		ll diff = abs(x-y);
		if(diff == 0) { cout << "0\n"; continue; }
		int i = 1;
		ll ans = ceil((-1 + sqrt(1+8*diff)) /2 );
		// while(diff > 0){
		// 	diff -= i;
		// }
		cout << ans<<"\n";
	}
	return 0;
}
