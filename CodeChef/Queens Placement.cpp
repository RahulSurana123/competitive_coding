

/* 
    Solution by Rahul Surana
    
    ***********************************************************


In order to impress Chefina, Chef is trying to improve his chess calculation skills.

Today, Chef took a big chessboard with N rows (numbered 1 through N) and N columns (numbered 1 through N). 
Let's denote the square in row r and column c of the chessboard by (r,c). 
Chef wants to place some queens on this chessboard in such a way that the following conditions are satisfied:

Each square of the board contains at most one queen.
There are exactly N−2 queens on the board.
All squares are reachable by at least one queen.
A queen can reach all cells along the row, column, and diagonals it is placed at.

Formally, a queen placed at square (r,c) can reach square (x,y) if at least one of the following conditions holds:

x=r
y=c
r+c=x+y
r−c=x−y
Help Chef find a possible distribution of queens. If there are multiple solutions, you may find any one. 
It is guaranteed that under the given constraints, a solution always exists.

Input Format:

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single integer N.

Output Format:

For each test case, print N lines. 
For each valid i, the i-th of these lines should contain a single string with length N describing row i of the chessboard; 
for each valid j, the j-th character of this string should be 'Q' if there is a queen in the square (i,j) or '.' if this square is empty. 
Please note you have to place exactly N−2 queens.



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
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){

                if(i == j && (i != 0 && i !=2)){
                    cout << "Q";
                }
                else {
                    cout <<".";
                }

            }
            cout << "\n";
        }
    }
}
