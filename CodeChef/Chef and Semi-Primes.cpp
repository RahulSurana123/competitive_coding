

/* 

    Solution by Rahul Surana

    ***********************************************************

Chef likes prime numbers. However, there is one thing he loves even more. 
Of course, it's semi-primes! A semi-prime number is an integer which can be expressed as a product of two distinct primes. 
For example, 15=3⋅5 is a semi-prime number, but 1, 9=3⋅3 and 5 are not.

Chef is wondering how to check if an integer can be expressed as a sum of two (not necessarily distinct) semi-primes. 
Help Chef with this tough task!

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single integer N.

Output

For each test case, print a single line containing the string "YES" if it is possible to express N as a sum of two semi-primes or "NO" otherwise.



    ***********************************************************
*/


#include <bits/stdc++.h>
#define ll          unsigned long long int
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


vi ar;

void seive_of_erathros(){
    vi a(201,1);
    a[0] = 0;
    a[1] = 0;
    for(int i = 2; i * i < 201; i++ ){
        if(a[i]){
            for(int j = i*i; j < 201; j+=i){
                a[j] = 0;
            }
        }
    }
    FOR(i,201) if(a[i]) ar.pb(i);
}

int main()
{
    fast_io;
    seive_of_erathros();
    // FOR(i,ar.size()) cout << ar[i]<<" "; 
    vi sop;
    for (int i = 0; i < ar.size(); ++i)
        for(int j = i+1; j < ar.size(); j++)
            if(ar[i]*ar[j] < 200) sop.pb(ar[i]*ar[j]);
    
    // FOR(i,sop.size()) cout << sop[i]<<" ";  
    int t;
    cin >> t;
    
    while(t--) {

        ll n;
        cin >> n;
        bool f = false;
        for (int i = 0; i < sop.size(); ++i)
            for(int j = 0; j < sop.size();j++)
                if(n - sop[i] == sop[j]) { f = true; break; }
        if(f) cout << "YES\n";
        else cout << "NO\n";
        
    }
} 