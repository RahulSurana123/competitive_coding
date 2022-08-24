


/* 

    Solution by Rahul Surana
    
    ***********************************************************


Ezzat has an array of n integers (maybe negative). He wants to split it into two non-empty subsequences a and b, such that every element from the array belongs to 
exactly one subsequence, and the value of f(a)+f(b) is the maximum possible value, where f(x) is the average of the subsequence x.

A sequence x is a subsequence of a sequence y if x can be obtained from y by deletion of several (possibly, zero or all) elements.

The average of a subsequence is the sum of the numbers of this subsequence divided by the size of the subsequence.

For example, the average of [1,5,6] is (1+5+6)/3=12/3=4, so f([1,5,6])=4.

Input
The first line contains a single integer t (1 ≤ t ≤ 10 ^ 3)— the number of test cases. Each test case consists of two lines.

The first line contains a single integer n (2 ≤ n ≤ 10 ^ 5).

The second line contains n integers a1 , a2 , … , an (−10 ^ 9 ≤ ai ≤ 10 ^ 9).

It is guaranteed that the sum of n over all test cases does not exceed 3⋅105.

Output
For each test case, print a single value — the maximum value that Ezzat can achieve.

Your answer is considered correct if its absolute or relative error does not exceed 10−6.

Formally, let your answer be a, and the jury's answer be b. Your answer is accepted if and only if | a − b | max( 1 , | b | ) ≤ 10 ^ −6.


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

double ar[100001];


int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        FOR(i,n) { cin >> ar[i]; }
        // cout << s <<" "<< m <<"\n";
        // double a[n+1],b[n+1];
        double m = -1000000000.0;;
        double s = 0.0;
        FOR(i,n) { s+=ar[i]; if(m<ar[i]) m = ar[i]; }
        // s = 0.0;
        // FOR(i,n) { s+=ar[n-1-i]; b[n-i] = s /(i+1); }
        double ans = (s-m)/(n-1) + m;
        // FOR(i,n-1) { ans = max(ans, a[i+1] + b[i+2]); }
        cout << fixed <<setprecision(10) << ans <<"\n";
    }
}
