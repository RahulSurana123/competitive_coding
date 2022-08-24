

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a grid of size (N * N) that has the following specifications:

Each cell in the grid contains either a policeman or a thief.
A policeman can only catch a thief if both of them are in the same row.
Each policeman can only catch one thief.
A policeman cannot catch a thief who is more than K units away from the policeman.
Write a program to find the maximum number of thieves that can be caught in the grid.

Input format

First line: T (number of test cases)
For each test case
First line: Two space-separated integers N and K
Next N lines: N space-separated characters (denoting each cell in the grid)
Output format

For each test case, print the maximum number of thieves that can be caught in the grid.



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
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        FOR(i,n){
            FOR(j,n){
                char a;
                cin >> a;
                if(a == 'P'){
                    ar[i][j] = 0;
                }
                else{
                    ar[i][j] = 1;
                }
            }
        }
        ll ans = 0;
        FOR(i,n){
            FOR(j,n){
                if(ar[i][j] == 0){
                    int r = min(j+1,n-1);
                    while(r != j+k+1) {
                        if(r > n-1) break; 
                        if(ar[i][r] == 1) {
                            // cout << i << " " << j << " "<<r << " \n";
                            ar[i][r] = 2;
                            ar[i][j] = 2; 
                            ans++ ;
                            break; 
                        }
                        r++; 
                    }
                }
                else if(ar[i][j] == 1){
                    int r = min(j+1,n-1);
                    while(r != j+k+1) {
                        if(r > n-1) break; 
                        if(ar[i][r] == 0) {
                            // cout << i << " " << j << " "<<r << " \n"; 
                            ar[i][j] = 2;
                            ar[i][r] = 2; 
                            ans++;
                            break; 
                        }
                        r++; 
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}