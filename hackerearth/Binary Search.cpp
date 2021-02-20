

/* 

    Solution by Rahul Surana

    ***********************************************************

You have been given an array A consisting of N integers. All the elements in this array A are unique. 
You have to answer some queries based on the elements of this array. 
Each query will consist of a single integer x. 
You need to print the rank based position of this element in this array considering that the array is 1 indexed. 
The rank based position of an element in an array is its position in the array when the array has been sorted in ascending order.

Note: It is guaranteed that all the elements in this array are unique and for each x belonging to a query,
value x shall exist in the array 

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

vi ar;

int bs(int start, int end, int target)
{
    int mid;
    while (start<=end)
    {
        mid = (start+end) >> 1;
        if (ar[mid]==target) return mid;
        else if (ar[mid]>target) end = mid - 1;
        else start = mid + 1; 
    }
    return -1; 
}



int main()
{
	fast_io;
    int n,q;
    
    
    cin >> n;
    
    FOR(i,n)
    { 
        int a;  
        cin >> a;
        ar.pb(a);
    }
    sort(ar.begin(),ar.end());
    cin >> q;
    
    FOR(i,q)
    {
        int t; 
        cin >> t;
        int x = bs(0,n-1,t);
        cout << x+1 <<"\n";
    }
}