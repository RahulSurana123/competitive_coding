

/* 

    Solution by Rahul Surana

    ***********************************************************

Everything was going well in Wasseypur until Ramadhir Singh found out that Sahid Khan plans to kill him someday and takeover his mine. 
To protect himself, he decided to take preemptive measures and kill Sahid Khan first. However, 
Sahid Khan also learnt of Ramadhir Singh's plan to kill him, and soon Wasseypur was all set for bloodshed 
- but Chef intervened! Instead of resorting to violence, he convinced them to settle things by playing a game called the Game of Wasseypur.

The game is as follows: There is a string S of length N consisting of only 0′s and 1′s. 
Players take turns moving - on his turn, a player chooses some block of S and erases it. 
The remaining parts of S are then concatenated together (without changing the order), and the other player then makes a move on this modified string.

A block in the string is defined as a maximal non-empty substring consisting of the same character. 
For example, if S=0001110110011, there are 6 blocks: in order from left to right, 000,111,0,11,00,11.

The player who is unable to make a move at the end loses the game and has to leave Wasseypur. 
Assuming that both players play optimally and Sahid Khan starts, find the winner of the game.

Input Format:

The first line of input contains a single integer T denoting the number of test cases. 
The description of T test cases follows.
The first line of each test case contains a single integer N denoting the length of the string.
The second line of each test case contains the binary string S.

Output Format:

For each test case, output a single line containing the string “SAHID” (without quotes) 
if Sahid Khan will be the winner, and “RAMADHIR” otherwise.

Each character of the output can be printed either in lowercase or uppercase 
(so if Sahid wins, “SAHID”, “sahid” and “sAHiD” are all acceptable outputs).



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


bool sw(int i, bool s){
    if(i == 1 || i == 3 || i==4) return s;
    if(i == 2) return s^s;

    return (sw(i-1,s^s) || sw(i-2,s^s));
}


int main()
{
    fast_io;
    
    int t;
    cin >> t;
    
    while(t--) {

        ll n;
        cin >> n;
        string s;
        cin>>s;
        int c = 1;
        FOR(i,n-1) {
            if(s[i+1] != s[i]) c++; 
        }
        // cout << c << "\n";
        if(c==1){
            cout << "SAHID\n";    
        }
        else if(c==2) cout << "RAMADHIR\n";
        else {
            c-=2;
            if(c%3 == 0){
                cout << "RAMADHIR\n";  
            }
            else{
                cout << "SAHID\n";
            }
        }

    }
} 