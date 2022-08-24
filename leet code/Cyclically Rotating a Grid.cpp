

/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are given an m x n integer matrix grid, where m and n are both even integers, and an integer k.

The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:

111111
122221
122221
111111

A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, 
each element in the layer will take the place of the adjacent element in the counter-clockwise direction. An example rotation is shown below:
                     
1  2  3  4               2  3  4  5
16 1  2  5               1  2  3  6
15 8  3  6               16 1  4  7
14 7  4  7    k = 1 =>   15 8  5  8
13 6  5  8               14 7  6  9
12 11 10 9               13 12 11 10

Return the matrix after applying k cyclic rotations to it.


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
#define fast_io 	std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;

vector<vector<int>> ar;

vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
    int n = grid[0].size();
    int m = grid.size();
    vector<vector<int>> ans(m,vector<int>(n,0));
    for(int i = 0; i<min(n,m)/2;i++){
        int x = (2*(n-(2*i)) + 2*(m-(2*i))-4);
        int y = k % x;
        vector<int> passer;
        cout << "1l" <<" ";
        for(int j = i; j < n-i; j++){
            cout<< grid[i][j]<<" ";
            passer.push_back(grid[i][j]);
        }
        cout << "2l" <<" ";
        for(int j = i+1; j < m-i; j++){
            cout<< grid[j][n-1-i]<<" ";
            passer.push_back(grid[j][n-1-i]);
        }
        cout << "3l" <<" ";
        for(int j = n-i-2; j >= i; j--){
            cout<< grid[m-1-i][j]<<" ";
            passer.push_back(grid[m-1-i][j]);
        }
        cout << "4l" <<" ";
        for(int j = m-2-i; j > i; j--){
            cout<< grid[j][i]<<"  ";
            passer.push_back(grid[j][i]);
        }
        cout << "\n";
        int s = k;
        cout << x<<" \n";
        // vector<int> replacer = rotator(passer);
        for(int j = i; j < n-i; j++){
            grid[i][j] = (passer[s%x]);
            s++;
            s=s%x;
        }
        for(int j = i+1; j < m-i; j++){
            grid[j][n-1-i] = (passer[s%x]);
            s++;
            s=s%x;
        }
        for(int j = n-i-2; j >= i; j--){
            grid[m-1-i][j] = (passer[s%x]);
            s++;
            s=s%x;
        }
        for(int j = m-2-i; j > i; j--){
            grid[j][i] = (passer[s%x]);
            s++;
            s=s%x;
        }
    }
    return grid;
}


int main()
{
	fast_io;
    
    ll m,n,k;
    cin >> m >> n;
    ar.resize(m,vector<int>(n));
    FOR(i,m){
        FOR(j,n){
            cin >> ar[i][j];
        }
    }
    cin >> k;
    vector<vector<int>> ans = rotateGrid(ar,k);
    FOR(i,m){
        FOR(j,n){
            cin >> ans[i][j];
        }
    }
}



 
    
