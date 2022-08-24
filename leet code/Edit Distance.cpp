

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character



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


int lcs(string a, string b){
    int n = a.length();
    int m = b.length();

    int L[n+1][m+1];
    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= m; j++){
    //         cout << L[i][j] <<"";
    //     }
    //     cout << "\n";
    // }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(j == 0 || i == 0){
                if(i == 0) L[i][j] = j;
                else L[i][j] = i;
            }
            else if(a.at(i-1) == b.at(j-1)){
                L[i][j] = L[i-1][j-1];
            }
            else{
                int r = L[i-1][j-1]+1;
                L[i][j] = min(r,min(L[i-1][j]+1,L[i][j-1]+1));
            }
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            cout << L[i][j] <<" ";
        }
        cout << "\n";
    }
    return L[n][m];
}



int main()
{
    fast_io;
    string a,b;
    cin >> a;
    cin >> b;
    int n = a.length();
    int m = b.length();
    int x = lcs(a,b);
    cout << x <<" ";
}
