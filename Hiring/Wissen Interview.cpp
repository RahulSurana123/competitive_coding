
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

int ar[100000];

int countf(int k,int n) {
	sort(ar,ar+6);
	int i = 0;
	int j = 0;
	int ans = 0;
	while(i<n && j <n){
		while(j<n && ar[j]<ar[i]+k) j++;
		int c = 1;
		// cout << i << " i "<<j <<" j";
		while( i+1< n && ar[i] == ar[i+1]) {
		c++; 
		i++; 
		}
		int d = 0;
		if(ar[j] == ar[i]+k){
			d =1;
		while(j+1 < n && ar[j] == ar[j+1]) { j++; d++; }
		}
	// 	cout << i << " i "<<j <<" j";
	// cout << c << " "<<d <<" ";
	ans += c*d;
	i++;
	j++;
	}
	return ans;
}



int main() {

	ar[0] =1;
	ar[1] =2;
	ar[2] =3;
	ar[3] =4;
	ar[4] =5;
	ar[5] = 6;

string v = "abbdhkjfsl";
string p = "abcdef";

	int k =4;
	int n = 6;
	cout << countf(k,n)<<"\n";

}