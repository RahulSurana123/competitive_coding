


/* 

    Solution by Rahul Surana

    ***********************************************************

Input:

The first line contains an integer T, the number of test cases. T testcases follow.
N and M the rows and column of matrix
M lines with N Values in each line 

Output:

Print The Traversal shown in figure

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
#define FOR(i,a)    for(int i = 0; i < a;i++)
#define F           first
#define S           second
#define trace(x)    cerr<<#x<<" : "<<x<<endl;
#define trace2(x,y) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<" | "<<#z<<" : "<<z<<endl;
#define fast_io     std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;
int inf=1e9+7, MOD=1e9+7;

int ar[100][100];

int main()
{
    fast_io;
    int n,m;
    cin >> m >> n;
    FOR(i,n) FOR(j,m) { cin >> ar[j][i]; }
    int  ki = 0,kj = 0,kni = 0,knj = 0;
    // int count = 0;
    // n++;
    // m++;
    for(int i = 0; i < (min(n,m)/2) + 1;i++){
        // cout << "1l" <<" ";
        for(int j = i; j < n-i; j++){
            cout<< ar[i][j]<<" ";
            // passer.push_back(grid[i][j]);
        }
        // cout << "2l" <<" ";
        for(int j = i+1; j < m-i; j++){
            cout<< ar[j][n-1-i]<<" ";
            // passer.push_back(grid[j][n-1-i]);
        }
        // cout << "3l" <<" ";
        for(int j = n-i-2; j > i; j--){
            cout<< ar[m-1-i][j]<<" ";
            // passer.push_back(grid[m-1-i][j]);
        }
        // cout << "4l" <<" ";
        for(int j = m-2-i; j > i; j--){
            cout<< ar[j][i]<<"  ";
            // passer.push_back(grid[j][i]);
        }
    }
    // while(count < n*m){
    //     while(j+kj<m-knj) { cout << ar[i+ki][j+kj] <<" a "; j++; count++; }
    //     ki++;
    //     while(i+ki < n - kni) { cout << ar[i + ki][j+kj] <<" b "; i++; count++; }
    //     knj++;
    //     while(j - knj > kj) { cout << ar[i + ki][j - knj] <<" c "; j--; count++; }
    //     kni++;
    //     while(i - kni > ki) { cout << ar[i - kni][j+kj] <<" d "; i--; count++; }
    //     kj++;
    // }

}