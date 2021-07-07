

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array A of length N and an integer X. You need to find all the subarrays of minimum length with BITWISE OR  >=  (greater than or equal to) X.

Input


The first line of input contains an integer T , the number of test cases. The following lines describe the test cases.
The first line of each test case contains N and X. 
Second line of each test case contains N  space seperated integers. Each representing elements of array A

Output


For each test case, In first line print count of such subarrays (Let it be C). In next C lines print all the subarrays (in sorted order). 
(Note :- A subarray can be defined by 2 indexs L and R where L and R are starting and ending indexs of that subarray)



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

int ar[100001];

vector<pi> ans;

int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--) {
        ans.clear();
        int n,x;
        cin >> n >> x;
        FOR(i,n) cin >> ar[i];
        int minL = n+1;
        int start = 0,end = 0;
        int minl=-1,minr = -1;
        while(start<n){
            int sum = ar[start];
            end = start+1;
            while(sum < x && end < n && end-start<=minL){
                sum |= ar[end++]; 
            }
            end--;
            if(sum >= x){
                if(end - start == minL){
                    ans.pb({start+1,end+1});
                }
                if(end- start < minL){
                    ans.clear();
                    ans.pb({start+1,end+1});
                    minL = end-start;
                }
            }
            start++;
            if(start + minL >= n ) break;
        }
        cout << ans.size()<<"\n";
        sort(ans.begin(),ans.end());
        FOR(i,ans.size()) cout << ans[i].F << " "<<ans[i].S<<"\n";

    }
}