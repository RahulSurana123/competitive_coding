

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Alice is teaching Bob maths via a game called N-guesser.

Alice has a positive integer N which Bob needs to guess. She gives him two pieces of information with which to do this:

A positive integer X, which denotes the sum of divisors of N.
Two positive integers A and B, which denote that the sum of reciprocals of divisors of N is A/B.
Bob either needs to guess N or tell that no such number exists.

It can be shown that if a valid N exists, it is unique.

Input Format:

The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follows.
Each test case consists of a single line of input, containing three space-separated integers X,A,B.

Output Format:

For each test case, output a new line containing the answer — Alice's number N, or −1 if no such number exists.



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
 
using namespace std;


int main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--) {
        ll x, a,b;
        cin >> x >> a >> b;
        // if(x%a != 0) { cout << "-1\n"; continue; }
        // auto z = [&](int g){
        //     int s = 0;
        //     double q = 0.0;
        //     for(int k = 1; k <= ceil(g/2); k++){
        //         if(g%k == 0) {
        //             s+= (k) + (g/k);
        //             q += (double)(1/(double)k) + (double)((double)k/g);
        //         }
        //     }
        //     // cout << g <<" "<< s <<" " << (double)q <<"\n";
        //     if(s == x && q == ((double)a/b)) return true;
        //     return false;
        // };
        // int ans = -1;
        // for(int i = 1; i < x; i++){
        //     // cout << z(i) <<" ";
        //     if(z(i)) {
        //         ans = i;
        //         break;
        //     }
        // }
        // cout << ans <<"\n";
        if(x%a != 0) { cout << "-1\n"; continue; }
        ll z = x/a;
        ll d = z*b;
        ll s = 0;
        for(int i = 1; i <= sqrtl(d); i++){
            if(s > x) break;
                // cout << z*a<< " "<< i + (b/i)<<" ";
            if(d%i == 0) {
                s += i;
                if((d/i) != i) s += (d/i) ;
             }
        }
        if(s!=x) cout << "-1\n";
        else cout << d << "\n"; 
    }
}
