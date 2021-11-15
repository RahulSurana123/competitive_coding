#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;
	int ar[n+1];
	for(int i = 1 ; i <= n ; i++ ){
		cin >> ar[i];
		// cout << ar[i] <<" ";
	}
	// cout<<"\n";
	int ans[n+1];
	for(int i = 1;i <= n; i++){
		int  x = ar[i];
		int j = i+1;
		while(j <= n && ar[j]<x) j++;
		// cout << j <<" ";
		if(j == n+1) ans[i] = -1;
		else ans[i] = j;
	}
	for(int i = 1; i < n+1 ;i++){
		cout << ans[i]<<" ";
	}

	return 0;
}
