
/* 

    Solution by Rahul Surana

    ***********************************************************

You are in a book shop which sells n different books. You know the price and number of pages of each book.

You have decided that the total price of your purchases will be at most x. 
What is the maximum number of pages you can buy? You can buy each book at most once.

Input

The first input line contains two integers n and x: 
the number of books and the maximum total price.

The next line contains n integers h1,h2,…,hn: 
the price of each book.

The last line contains n integers s1,s2,…,sn: 
the number of pages of each book.

Output
Print one integer: the maximum number of pages.


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
#define fast_io 	std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
// #define TIME
#ifdef TIME
#include <chrono>
using namespace std::chrono;
#endif
using namespace std;

int main() {
	fast_io;
#ifdef TIME
    auto start = high_resolution_clock::now();
#endif
    int n, x;
    cin >> n >> x;
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    vector<int> p(n),pp(n);
    FOR(i,n){
        cin >> p[i];
    }
    FOR(i,n){
        cin >> pp[i];
    for(int i = 1; i <=n; i++){
        FOR(j,x+1){
            dp[i][j] = dp[i-1][j];
            if(p[i-1] <= j)
            dp[i][j] = max(dp[i][j], dp[i-1][j-p[i-1]] + pp[i-1]);
        }
    }
    cout << dp[n][x] <<"\n";
#ifdef TIME
    cout << (duration_cast<milliseconds>(high_resolution_clock::now() - start).count()) <<"ms\n";
#endif
}
