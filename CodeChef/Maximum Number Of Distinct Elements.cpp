

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array B of length N, find an array A of length N where 0≤Ai≤109 such that array C where Ci=AimodBi, ∀i∈{1,N} has maximum number of distinct integers.

In case of multiple answers, print any.

Input Format:

First-line will contain T, the number of test cases. Then the test cases follow.
Each test case contains two lines of input.
First-line contains a single integer N.
Second-line contains N space-separated integers B1,B2,…,BN.

Output Format :

For each test case, output in a single line N space-separated integers A1,A2,…,AN, the elements of the array A such that array C has the maximum number of distinct elements.
If the output array doesn't follow the constraints or the number of distinct elements in the array C is less than the optimal value, you will receive a wrong answer verdict.



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


int ar[200005];

int compare(int a, int b){
    return ar[a]<ar[b];
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    
    while(t--) {

        int n;
        cin >> n;
        int ind[n];
        int ans[n] = {0};
        FOR(i,n) { cin >> ar[i]; ind[i] = i; }
        sort(ind,ind+n,compare);
        int count = 0;
        FOR(i,n) { ans[ind[i]] = count; if(ar[ind[i]]>count) count++; }
        FOR(i,n) { cout << ans[i] <<" ";}
        cout << "\n";
        
    }
} 