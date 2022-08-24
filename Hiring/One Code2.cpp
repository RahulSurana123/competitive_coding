#include<bits/stdc++.h>

using namespace std;

int main(){
	vector<int> ar = {11, 15, 6, 8, 9, 10, 1};
	int x = 16;

	set<int> s;
	s.insert(ar[0]);
	bool f = false;
	for(int i = 1; i < ar.size(); i++){
		if(s.count(x-ar[i])){
			cout << "true";
			f = true;
			break;
		}
		s.insert(ar[i]);
	}
	if(!f)
	cout <<"false";
}