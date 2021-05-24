/* 

    Solution by Rahul Surana

    ***********************************************************

You are given a array A with N no of element in it.
find the longest subarray with maximum bitwise and(&) value.

for example if you have array of [3,3,3] this array has max bitwise 
and value of 3 and subarray [3,3,3] has max bitwise and value this subarray has 3 value in it hence answer is 3.

Input:

The first line contains an integer T, the number of test cases. T testcases follow.
The first line of each test contains two integers N. No of elements in the array A.
The second line contains N space seprated value of array A.

Output:

Each Testcase will print in new line the length of the subarray with the above condition.

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

int ar[100000];

vector<int> c;

int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
    	int count = 1;
    	
    	for(int i = 1; i < n; i++){
    		if(s[i] == s[i+1]) {
    			count++;
    		}
            else {
                c.pb(count);
                count = 1;
            }
    	}
        if(count > 0) c.pb(count);
    	int ans = 1;
        for(int i = 0; i < c.size(); i++){

            ans = (ans%MOD * c[i]%MOD)%MOD;

        }

    	cout << ans << "\n";
    }
}