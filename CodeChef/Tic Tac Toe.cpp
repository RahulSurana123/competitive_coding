

/* 

    Solution by Rahul Surana

    ***********************************************************

Tic-tac-toe is a game played between two players on a 3×3 grid. In a turn, a player chooses an empty cell and places their symbol on the cell. 
The players take alternating turns, where the player with the first turn uses the symbol X and the other player uses the symbol O. 
The game continues until there is a row, column, or diagonal containing three of the same symbol (X or O), and the player with that token is declared the winner. 
Otherwise if every cell of the grid contains a symbol and nobody won, then the game ends and it is considered a draw.

You are given a tic-tac-toe board A after a certain number of moves, consisting of symbols O, X, and underscore(_). 
Underscore signifies an empty cell.

Print

1: if the position is reachable, and the game has drawn or one of the players won.
2: if the position is reachable, and the game will continue for at least one more move.
3: if the position is not reachable.

Input

The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains 3 lines of input where each line contains a string describing the state of the game in ith row.

Output

For each test case, output in a single line 1, 2 or 3 as described in the problem.


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

ll ar[3][3];


bool win(int x){
	FOR(i,3) {
		if(ar[i][0] == x && ar[i][1] == x && ar[i][2] == x) return true;
		if(ar[0][i] == x && ar[1][i] == x && ar[2][i] == x) return true;
	}
	if(ar[0][0] == x && ar[1][1] == x && ar[2][2] == x) return true;
	if(ar[0][2] == x && ar[1][1] == x && ar[2][0] == x) return true;
	return false;
}

bool validBoard(){
    int x = 0, o = 0;
    FOR(i,3) FOR(j,3) { if(ar[i][j] == 0) x++; else if(ar[i][j] == 1) o++; }
    if(x == o || x == o + 1){
        bool ow = win(1);
        bool xw = win(0);
        if(ow){
            if(xw) return false;
            return x==o;
        }
        if(xw && x!=o+1) return false;
        return true;
    }
    return false;
}


int main()
{
    fast_io;
    ll t;
    cin >> t;
    while(t--) {
        int x=0,o=0,m=0;
        bool xw=false,ow=false;
        FOR(i,3) {
            string s;
            cin >> s; 
            FOR(j,s.length()) {
                if(s[j] == 'X') { 
                    ar[i][j] = 0; 
                    x+=1; 
                } 
                else if(s[j] == 'O') { 
                    ar[i][j] = 1; 
                    o+=1; 
                }
                else {
                    ar[i][j] = 2;
                    m+=1;
                }
            }
        }
        // FOR(i,3) { FOR(j,3) cout << ar[i][j]; cout << "\n"; }
        // cout <<x <<" "<< o << " "<<m<<"\n";
        xw = win(0);
        ow = win(1);
        // cout <<xw <<" "<< ow << "\n";
        if(!validBoard()) cout << 3 <<"\n"; 
        else if((!xw && !ow) && m != 0) cout << 2 << "\n";
        else cout << 1<<"\n";
    }
}