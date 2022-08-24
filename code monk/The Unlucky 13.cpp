


/* 

    Solution by Rahul Surana

    ***********************************************************

Write a program to calculate the total number of strings that are made of exactly N characters.
None of the strings can have "13" as a substring.
The strings may contain any integer from 0 - 9, repeated any number of times.

Input Format:

First line: T, the number of test cases.
Next T lines: Each contain an integer N.

Output Format:

Print the result of each query mod 10^9.
Answer for each test case should come in a new line.

    ***********************************************************

*/


#include <bits/stdc++.h>
#define int          long long
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
 
void io()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("/home/kashif/cp/input.txt","r",stdin);
		
		freopen("/home/kashif/cp/output.txt","w",stdout);
	#endif
 
}
int i,j,k;
int M[4][4] = {{0,99,-10,2},{1,0,0,0},{0,1,0,0},{0,0,0,10}};
int p;
void multiply(int a[4][4],int b[4][4])
{
 
	int mul[4][4]={0};	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				
				p=(a[i][k]*b[k][j]);
				mul[i][j]=(mul[i][j]+p);
			
			}
		}
	}
	
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			a[i][j]=mul[i][j]%mod;
	}
 
}
void power(int a[4][4],int n) 
{ 
    if(n==1 || n==0)
    	return;
    power(a,n/2); 
    multiply(a,a); 
    if (n%2 != 0) 
        multiply(a,M); 
}
 
int32_t main() 
{
	
	fastio();
	io();
	int t,n,ans;
	cin>>t;
	while(t--)
	{
		
		cin>>n;
		if(n==0)
			printf("%d\n",1);
		else if(n==1)
			printf("%d\n",10);
		else if(n==2)
			printf("%d\n",99);
		else if(n==3)
			printf("%d\n",980);
		else
		{
			int a[4][4]={{0,99,-10,2},{1,0,0,0},{0,1,0,0},{0,0,0,10}};
			power(a,n-3);
			p=(a[3][3]*1000);
			k=(a[0][0]*20+a[0][1]+100*a[0][3])%mod;
			ans=(p-k+mod)%mod;
			printf("%lld\n",ans);
		}	
	}	
}
