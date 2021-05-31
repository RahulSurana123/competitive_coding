

/* 

    Solution by Rahul Surana

    ***********************************************************

You are an administrator of a popular quiz website. Every day, you hold a quiz on the website.

There are N users (numbered 1 through N) and M admins (numbered N+1 through N+M). For each quiz, each user is allowed to attempt it at most once. 
Sometimes, admins attempt the quizzes for testing purposes too; an admin may attempt a quiz any number of times.

On a certain day, the quiz was attempted K times. For each i (1≤i≤K), the i-th of these attempts was made by the person with number Li. 
Find all the users who attempted the quiz more than once, in order to disqualify them.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains three space-separated integers N, M and K.
The second line contains K space-separated integers L1,L2,…,LK.

Output

For each test case, print a single line containing an integer D denoting the number of users who should be disqualified, 
followed by a space and D space-separated integers denoting their numbers in ascending order.



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

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    fast_io;
    
    int t;
    cin >> t;
    
    while(t--) {

        ll n,m,k;
        cin >> n >> m >> k;
        int ar[k];
        int freq[n+1];
        FOR(i,n+1) freq[i] = 0;
        FOR(i,k) cin >> ar[i];
        FOR(i,k) if(ar[i]<n+1) freq[ar[i]]++;
        vl c;
        for(int i = 1; i < n+1; i++){
            if(freq[i] > 1) c.pb(i);
        }
        cout << c.size() << " ";
        FOR(i,c.size()) cout << c[i] << " ";
        cout << "\n";
    }
} 