

/* 

    Solution by Rahul Surana

    ***********************************************************

Deep wants to become a 7-star coder on CodeChef. To achieve this goal, everyday, he has to solve as many problems as he can. 
But for the first time since he was new to programming, he wasn't able to solve a single problem and lost his confidence. 
Can you help him solve the problem so that he gets a new boost to go ahead?

In this problem, you are given a matrix that extends infinitely to the right and down, filled with values as shown below.

1 2 4 7 . .
3 5 8 . . .
6 9 . . . .
10 . . . .
. . . . . .

Let (x,y) denote the cell in the x-th row and y-th column. The upper-left cell (1,1) contains an integer 1. 
You begin at the cell (x1,y1) and must walk to the cell (x2,y2) by only moving right and down. 
Formally, from the cell (x,y), in one step you can move to the cell (x+1,y) or (x,y+1).

The value of a path is the sum of the values in all visited cells, including (x1,y1) and (x2,y2). 
You need to calculate the maximum possible value on the path of a path from (x1,y1) to (x2,y2).

Input

The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains of a single line of input, four integers x1, y1, x2, y2.

Output

For each test case, output in a single line the maximum possible value of a path from (x1,y1) to (x2,y2).   


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


int ar[1001][1001];

int main()
{
    fast_io;
    for(int i = 1; i <= 1000; i++) {
        ar[i][1] = (i*(i+1))/2;
        int k = i;
        int m = i;
        for(int j = 2; j <= 1000; j++){
            ar[i][j] = ar[i][j-1] + m;
            k += m;
            m++;
        }
    }
    // for(int i = 1; i <= 10; i++) {
    //     for(int j = 1; j <= 10; j++){
    //         cout << ar[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    int t;
    cin >> t;
    
    while(t--) {

        int x1,y1,x2,y2;
        cin >>x1>>y1>>x2>>y2;

        ll sum = 0;
        while(x1 <= x2) { sum += ar[x1][y1]; x1++; }
        y1++;
        while(y1 <= y2) { sum += ar[x2][y1]; y1++; }
        cout << sum << "\n";
    }
}