










/* 
    Solution by Rahul Surana
    
    ***********************************************************


Hash functions are primarily used to generate fixed-length output data that acts as a shortened reference to the original data. This is useful when the original data is too cumbersome to use in its entirety. 
One practical use is a data structure called a hash table where the data is stored associatively. Searching linearly for a person's name in a list becomes cumbersome as the length of the list increases, 
but the hashed value can be used to store a reference to the original data and retrieve constant time (barring collisions).

It involves mapping an element into a numerical value using some mathematical function. In this problem we will consider a simple hash system. 
It involves assigning numerical value to the alphabets and summing these values of the characters.

For example, the string “acm” is mapped to 1+3+13=17. Unfortunately, this method does not give one-to-one mapping. The string “adl” also maps to 17 (1+4+12). 
This is called collision.

In this problem you will have to find the number of strings of length L, which maps to an integer S, using the above hash function. 
You have to consider strings that have only lowercase letters and uppercase letters in strictly ascending order.

NB: all lowercase letters are smaller than all uppercase letters: Example: ‘z’ < ‘A’
Suppose L=3 and S=10, there are 4 such strings:(abg , acf , ade , bce )
agb also produces 10 but the letters are not strictly in ascending order.
bh also produces 10 but it has 2 letters.

Input

The first line of input contains a integer T, (T≤100) which denotes the number of test case.
Each case consists of 2 integers L and S (0<L,S<100000)

Output

For each case, print the case number followed by the expected answer.



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
