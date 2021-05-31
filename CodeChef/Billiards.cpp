

/* 

    Solution by Rahul Surana

    ***********************************************************

BILLIARDS is a really interesting game. It is played on a green baize with 3 balls-red, white and yellow.
Sheldon and Leonard are playing a game of billiards. Sheldon is playing the game for the first time and is not familiar with the rules. 
So he asks Leonard to explain the rules to him. Leonard explains the rules to Sheldon in the following way:

“A Cannon shot gives 2 points and an In-Off Shot gives 3 points.”

Sheldon is curious, and wants to figure out that given a score X, in how many ways can he get that score by hitting a combination of Cannon and In-Off shots?

Leonard is baffled when he is asked this question.

Your task is to help Leonard in writing a program to compute the total number of ways one can score a total of X points by hitting 
any combination of Cannon and In-Off shots. The order in which the shots are hit have importance.

For example, 5 can be scored in two ways, by hitting an In-Off Shot followed by a Cannon shot or a Cannon Shot followed by an In-Off shot. 
A score of 7 can be achieved in three ways – Cannon,In-Off,Cannon Cannon,Cannon,In-Off and In-Off,Cannon,Cannon.

Input

The first line of input will contain an integer T which denotes the number of test cases. 1≤T≤2000
The next T lines will each have a positive integer X, denoting the score which has to be achieved.

Output

For each test case, Output a single line containing the total number of ways one can score a score of X by hitting only Cannon and In-Off shots. 
Since the number can be very large, Output the answer MOD 1000000009 (109+9)



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
#define MOD7 1000000007 
#define MOD9 1000000009
using namespace std;

int ar[1000006];

int main()
{
    fast_io;
    ar[2] = 1;
    ar[3] = 1;
    for(int i = 4; i < 1000006; i++ ) ar[i] = (ar[i-2] + ar[i-3])%MOD9;

    int t;
    cin >> t;
    
    while(t--) {

        ll x;
        cin >> x;
        
        cout << ar[x] << "\n";
        
    }
} 