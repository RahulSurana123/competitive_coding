

/* 

    Solution by Rahul Surana
    

    ***********************************************************


YouKn0wWho has two even integers x and y. Help him to find an integer n such that 1≤n≤2⋅1018 and nmodx=ymodn. 
Here, amodb denotes the remainder of a after division by b. If there are multiple such integers, output any. 
It can be shown that such an integer always exists under the given constraints.

Input
The first line contains a single integer t (1≤t≤105)  — the number of test cases.

The first and only line of each test case contains two integers x and y (2≤x,y≤109, both are even).

Output
For each test case, print a single integer n (1≤n≤2⋅1018) that satisfies the condition mentioned in the statement. 
If there are multiple such integers, output any. 
It can be shown that such an integer always exists under the given constraints.

        

    ***********************************************************
*/



#include <bits/stdc++.h>
#define ll          long long
#define mem(a,x)    memset(a,x,sizeof(a))
#define pb          push_back
#define F           first
#define S           second
#define FOR(i,a)     for(int i = 0; i < a; i++)
#define fast_io     std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;


int main()
{
    fast_io;
    int t;
    cin >> t;

    while(t--){
        ll n,m;
        cin >> n >> m;
        if (n > m) cout << n + m <<"\n";
        else{
            cout << m - (m%n)/2 << "\n"; 
        }
    }
    
    return 0;
}