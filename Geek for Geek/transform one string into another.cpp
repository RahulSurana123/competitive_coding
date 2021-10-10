

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given two strings ‘str1’ and ‘str2’ of size m and n respectively. 
The task is to remove/delete and insert the minimum number of characters from/in str1 to transform it into str2. 
It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.



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


int lcs(string a, string b){
    int n = a.length();
    int m = b.length();

    int L[n+1][m+1] = {{0}};
    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= m; j++){
    //         cout << L[i][j] <<"";
    //     }
    //     cout << "\n";
    // }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0){
                L[i][j] = 0;
            }
            else if(a.at(i-1) == b.at(j-1)){
                L[i][j] = L[i-1][j-1] + 1;
            }
            else{
                L[i][j] = max(L[i-1][j],L[i][j-1]);
            }
        }
    }
    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= m; j++){
    //         cout << L[i][j] <<" ";
    //     }
    //     cout << "\n";
    // }
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
    cout << n+m-(2*x) <<" ";
}
