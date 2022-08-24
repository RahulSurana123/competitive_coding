




/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array  consisting of  positive integers. Your task is to find an array  of length  satisfying the following conditions:

 for all 
, for all 
 is divisible by  for all 
 is minimum
You are given  test cases.

Input format

The first line contains a single integer  denoting the number of test cases.
The first line of each test case contains a single integer  denoting the length of the array.
The second line of each test case contains  space-separated integers denoting the integer array .
Output format

For each test case (in a separate line), print  space-separated integers denoting . If there are multiple answers, you can print any of them. It is guaranteed that under the given constraints at least 1  exists.




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

ll ar[300000];

int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        FOR(i,n){ cin >> ar[i]; } 
        FOR(i,n-1){
        	if(ar[i] > ar[i+1]){
        		int a = ar[i+1];
        		int r = (a+ar[i]) % a;
        		if(r==0) ar[i+1] = 	ar[i];
        		else ar[i+1] = a+ar[i] - r;
        		// ar[i+1] = ar[i+1] - (ar[i+1]%ar[i]);
        		// ar[i+1] += a;
        		// while(ar[i+1]%a) ar[i+1]++;
        	}
        }
        FOR(i,n) cout << ar[i] <<" ";
        cout << "\n";
    }
}
