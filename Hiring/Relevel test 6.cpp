#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int ar[1001];
vector<int> dp;
long long ans = 0;

void aps(int i, int n,set<int> s,vector<int> v, int k){
	// if(i > n) return;
	if(v.size() > k) return;
	if(i>n) return;
	// s.reunique(s.begin(),s.end());
	// cout<<s.size()<<" "<<v.size() <<"\n";
	if(v.size()==k && s.size() >= k-1) {ans++;
	// set<int> x(s.begin(),s.end());
	// for(auto m: v){cout << m<<" ";}
	// cout<<"\n";
	}
	else {
		aps(i+1,n,s,v,k);
	}
	// vector<int> p(v.begin(),v.end());
	
	v.push_back(i);
	s.insert(ar[i]);
	aps(i+1,n,s,v,k); 
}

int main() {

	int n,k;
	cin >> n>>k;
	// cout<<n<<" "<<k<<" ";
	dp.resize(n,-1);
	for(int i = 0 ; i < n ; i++ ){
		cin >> ar[i];
		// cout << ar[i] <<" ";
	}
	aps(0,n,{},{},k);
	cout << (ans)%1000000007;
	return 0;
}
