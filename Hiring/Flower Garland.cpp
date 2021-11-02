


/* 
    Solution by Rahul Surana
    
    ***********************************************************






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
 
using namespace std;


int s[100001];

vector<int> continous_blue_and_red;

int solve(int i, int a,int b){
	if(i >= continous_blue_and_red.size()) return 0;
	if(a > b*continous_blue_and_red[i]) return solve(i+2,a,b) + b*continous_blue_and_red[i];
	else{
		return solve(i+2,a,b) + a;
	}
}

int main()
{
	string g;
	cin >> g;
	int a,b;
	cin >> a>>b;
	FOR(i,g.length()){
		int c = 0;
		if(g[i] == 'B'){
			c = 1;
			while(i+c < g.length() && g[i+c] == 'B') c++;
			continous_blue_and_red.pb(c);
			i+=c-1;
		}
		if(g[i] == 'R'){
			c = 1;
			while(i+c < g.length() && g[i+c] == 'R') c++;
			continous_blue_and_red.pb(c);
			i+=c-1;	
		}
	}

	int ans =  solve(1,a,b);
	cout << ans; 

}
