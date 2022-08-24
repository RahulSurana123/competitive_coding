
/* 

    Solution by Rahul Surana

    ***********************************************************

You have D dollars with you. You want to put it into a Bank, namely Picu Bank. 
This bank has a peculiar behavior for interest. 
Regardless of the Bank deposit amount, every month it adds A dollars to your bank account and this continues till M months. 
Exaxtly on (M+1)th months, it adds B dollars  to your bank account. 
This scanario repeats again in same manner.( i.e (M+2)th on the  month A dollars are added, and so on.. ). 
Your task is to find out how many months does it take for the dollar amount to reach at least X, in the bank account .    



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
int inf=1e9+7,MOD=1e9+7;

int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--){
        long long int d,a,m,b,x,c=0;
        
        cin >> d >> a >> m >> b >> x;
        int k = (x-d)/(a*m+b);
        
        long long int diff = (x-d)%(a*m+b);
        c += (diff/a) + (k*(m+1));
        
        if (diff%a!=0) c+=1;
        
        cout << c <<endl;
    }
}