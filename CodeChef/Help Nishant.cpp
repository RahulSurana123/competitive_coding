

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Nishant does pretty weird stuff. Today, he wants to create a weird sequence.

According to Nishant, a sequence A of length N is called weird if:

N≥3

2⋅Ai>Ai−1+Ai+1 ∀i∈{2,3,4....,N−1}

Nishant wants to construct a long weird sequence to impress his weird friends, 
but there's a problem: he only knows how to count up to K, so the sequence can only contain integers in the range [1,K].

Help Nishant determine the length of the longest weird sequence he can construct using only integers from 1 to K.

Input Format:

The first line contains a single integer T denoting the number of testcases. The description of T testcases follows.
The first and only line of each testcase contains a single integer K.

Output Format:

For each testcase, print one line containing a single integer - 
the maximum length of a weird sequence which can be obtained using only integers in [1,K].



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


int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--) {
        double k;
        cin >> k;
        int i = 1;
        int count = ceil((-1 + sqrt(1+(8*k)))/2);
        // while(k > 0){
        //     k-=i;
        //     i++;
        //     count++;
        // }
        cout << 2* count <<"\n";
    }
}
