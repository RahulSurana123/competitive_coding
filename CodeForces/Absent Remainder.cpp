

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a sequence a1,a2,…,an consisting of n pairwise distinct positive integers.

Find ⌊n2⌋ different pairs of integers x and y such that:

x≠y;
x and y appear in a;
x mod y doesn't appear in a.
Note that some x or y can belong to multiple pairs.

⌊x⌋ denotes the floor function — the largest integer less than or equal to x. x mod y denotes the remainder from dividing x by y.

If there are multiple solutions, print any of them. It can be shown that at least one solution always exists.

Input
The first line contains a single integer t (1≤t≤104) — the number of testcases.

The first line of each testcase contains a single integer n (2≤n≤2⋅105) — the length of the sequence.

The second line of each testcase contains n integers a1,a2,…,an (1≤ai≤106).

All numbers in the sequence are pairwise distinct. The sum of n over all testcases doesn't exceed 2⋅105.

Output
The answer for each testcase should contain ⌊n2⌋ different pairs of integers x and y such that x≠y, x and y appear in a and x mod y doesn't appear in a. 
Print the pairs one after another.

You can print the pairs in any order. However, the order of numbers in the pair should be exactly such that the first number is x and the second number is y. 
All pairs should be pairwise distinct.

If there are multiple solutions, print any of them.


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
#define fast_io     std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define MOD 1000000007 
using namespace std;



int main()
{
    fast_io;
    int t=1;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        vector<int> ar(n);
        set<int> s;
        vector<pair<int,int>> ans;
        FOR(i,n) { cin >> ar[i]; s.insert(ar[i]); }
        sort(ar.begin(),ar.end());
        int i = 0,j = 1;
        while(ans.size() < floor(n/2)){
            if(j >= ar.size()) { i++; j = i+1;}
            if(i >= ar.size()) break;
            if(!s.count(ar[j]%ar[i]) && ans.size() < floor(n/2)) ans.pb({ar[j],ar[i]});
            j++;
        }
        FOR(i,ans.size()) cout << ans[i].first <<" " << ans[i].second <<"\n";
    }
}