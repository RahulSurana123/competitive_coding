


/* 
    Solution by Rahul Surana
    
    ***********************************************************


Chef has an array A containing N integers. The integers of the array can be positive, negative, or even zero.

Chef allows you to choose at most K elements of the array and multiply them by −1.

Find the maximum sum of a subsequence you can obtain if you choose the elements of the subsequence optimally.

Note: A sequence a is a subsequence of a sequence b if a can be obtained from b by deletion of several (possibly, zero or all) elements. 
For example, [3,1] is a subsequence of [3,2,1] and [4,3,1], but not a subsequence of [1,3,3,7] and [3,10,4]. Note that empty sequence is also a subsequence.

Input Format:

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N,K.
The second line of each test case contains N space-separated integers A1,A2,...,AN

Output Format:

For each test case, print a single line containing one integer - the maximum sum of a subsequence you can obtain.



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

int ar[100001];

int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        FOR(i,n) cin >> ar[i];
        sort(ar,ar+n);
        int ans = 0;
        FOR(i,n) {
            if(ar[i] < 0 && k > 0) { ans += (ar[i] * -1); k--; }
            
            else if(ar[i] > 0){
                ans+= ar[i];
            }  
        }
        
        cout << ans << "\n";

    }
}
