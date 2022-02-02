

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Rock... Paper!

After Karen have found the deterministic winning (losing?) strategy for rock-paper-scissors, her brother, Koyomi, comes up with a new game as a substitute. The game works as follows.

A positive integer n is decided first. Both Koyomi and Karen independently choose n distinct positive integers, denoted by x1, x2, ..., xn and y1, y2, ..., yn respectively. 
They reveal their sequences, and repeat until all of 2n integers become distinct, which is the only final state to be kept and considered.

Then they count the number of ordered pairs (i, j) (1 ≤ i, j ≤ n) such that the value xi xor yj equals to one of the 2n integers. Here xor means the bitwise exclusive or operation on two integers, 
and is denoted by operators ^ and/or xor in most programming languages.

Karen claims a win if the number of such pairs is even, and Koyomi does otherwise. And you're here to help determine the winner of their latest game.

Input:

The first line of input contains a positive integer n (1 ≤ n ≤ 2 000) — the length of both sequences.
The second line contains n space-separated integers x1, x2, ..., xn (1 ≤ xi ≤ 2·106) — the integers finally chosen by Koyomi.
The third line contains n space-separated integers y1, y2, ..., yn (1 ≤ yi ≤ 2·106) — the integers finally chosen by Karen.
Input guarantees that the given 2n integers are pairwise distinct, that is, no pair (i, j) (1 ≤ i, j ≤ n) exists such that one of the following holds: 
xi = yj; i ≠ j and xi = xj; i ≠ j and yi = yj.

Output:

Output one line — the name of the winner, that is, "Koyomi" or "Karen" (without quotes). Please be aware of the capitalization.



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
#define fast_io 	std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;


uint64_t fac(uint64_t x,uint64_t y){
    if(x == y) return 1;
    return (((ll)fac(x-1,y)%10) * (x %10))%10;
}


int main()
{
	fast_io;
    int t=1;
    // cin >> t;
    while(t--) {
        uint64_t n,m;
        cin >> n>>m;
        if((m-n) >= 5) cout <<"0";
        else cout <<fac(m,n);
        // cout << ans <<"\n";
    }
}
