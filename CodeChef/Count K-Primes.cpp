

/* 

    Solution by Rahul Surana

    ***********************************************************

Alice and Bob are studying for their class test together. The topic of the test is Prime Numbers. The preparation is getting too boring for their liking. 
To make it interesting, they turn it into a game. The winner will get an ice-cream treat from the other.

The game is called Count K-Primes. A number is a K-prime if it has exactly K distinct prime factors. The game is quite simple. 
Alice will give three numbers A, B & K to Bob. Bob needs to tell Alice the number of K-prime numbers between A & B (both inclusive). 
If Bob gives the correct answer, he gets a point. If not, Alice gets a point. They play this game T times.

Bob hasn't prepared so well. But he really wants to win the game. He wants you to tell him the correct answer.

Input

First line of input contains a single integer T, the number of times they play.
Each game is described in a single line containing the three numbers A,B & K.

Output

For each game, output on a separate line the number of K-primes between A & B.



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


int ar[100001];

void seive_of_erathros(){
    ar[0] = 1;
    ar[1] = 1;
    for(int i = 2; i< 100001; i++ ){
        if(!ar[i]){
            for(int j = i; j < 100001; j+=i){
                ar[j]++;
            }
        }
    }
}

int main()
{
    fast_io;
    FOR(i,100001) ar[i] = 0;
    seive_of_erathros();
    // FOR(i,ar.size()) cout << ar[i]<<" "; 
    
    // FOR(i,sop.size()) cout << sop[i]<<" ";  
    int t;
    cin >> t;
    
    while(t--) {

        ll a,b,k;
        cin >> a >> b >> k;
        ll c = 0;
        for (int i = a; i <= b; ++i)
            if(ar[i] == k) { c++; }
        cout << c << "\n";
    }
} 