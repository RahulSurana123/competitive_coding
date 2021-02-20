

/* 

    Solution by Rahul Surana

    ***********************************************************

Bishu went to fight for Coding Club. There were N soldiers with various powers. 
There will be Q rounds to fight and in each round Bishu's power will be varied. 
With power M, Bishu can kill all the soldiers whose power is less than or equal to M(<=M). 
After each round, All the soldiers who are dead in previous round will reborn.
Such that in each round there will be N soldiers to fight. As Bishu is weak in mathematics, 
help him to count the number of soldiers that he can kill in each round and total sum of their powers.

1<=N<=10000

1<=power of each soldier<=100

1<=Q<=10000

1<=power of bishu<=100

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
int n,s[10000];
vi ar;
int bs(int start, int end, int t){
    int mid;
    while(start<=end){
        mid = (start+end)>>1;
        if (ar[mid]==t) return mid;
        else if (ar[mid]>t) end = mid-1;
        else start = mid+1;
    }
    return mid;
}

int main()
{
	fast_io;
    int q;
    cin >> n;
    
    FOR(i,n) 
    {   int a;
        cin >> a;
        ar.pb(a); 
    }
    sort(ar.begin(),ar.end());
    FOR(i,n) 
    {
        s[i] = ar[i];
        if (i > 0) s[i] += s[i-1];    
    }
    cin>>q;
    FOR(i,q)
    {
        int z;
        cin>>z; 
        vi::iterator it = upper_bound(ar.begin(),ar.end(),z);
        // int index = bs(0,n-1,z); 
        cout << it-ar.begin()<<" "<<s[it-ar.begin()-1]<<"\n";
       
    }

}