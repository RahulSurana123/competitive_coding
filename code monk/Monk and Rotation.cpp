

/* 

    Solution by Rahul Surana

    ***********************************************************

Monk loves to preform different operations on arrays, and so being the principal of Hackerearth School, he assigned a task to his new student Mishki. 
Mishki will be provided with an integer array A of size N and an integer K , where she needs to rotate the array in the right direction by K steps and then print the resultant array. 
As she is new to the school, please help her to complete the task.

Input:

The first line will consists of one integer T denoting the number of test cases.
For each test case:
1) The first line consists of two integers N and K, N being the number of elements in the array and K denotes the number of steps of rotation.
2) The next line consists of N space separated integers , denoting the elements of the array A.

Output:

Print the required array.

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
#define mod         1000000009

using namespace std;
 
 
int main()
{
	int T;
	cin>>T;
	while(T--)
	
	{
		long long int n,k;
		cin>>n>>k;
		k=k%n;
		long long int a[n];
		for(long long int i=0;i<n;i++)
		{
			long long int data;
			cin>>a[i];
		}
		for( int i=0;i<n;i++)
		{
			cout<<a[((n-k+i)%n)]<<" ";
		}
		cout<<"\n";}
}
