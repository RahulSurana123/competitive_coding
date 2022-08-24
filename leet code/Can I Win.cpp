

/* 

    Solution by Rahul Surana

    ***********************************************************

In the "100 game" two players take turns adding, to a running total, any integer from 1 to 10. The player who first causes the running total to reach or exceed 100 wins.

What if we change the game so that players cannot re-use integers?

For example, two players might take turns drawing from a common pool of numbers from 1 to 15 without replacement until they reach a total >= 100.

Given two integers maxChoosableInteger and desiredTotal, return true if the first player to move can force a win, otherwise, return false. Assume both players play optimally.

Input: maxChoosableInteger = 10, desiredTotal = 11

Output: false(boolean)


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

int mci,dt;
vector<vector<int>> dp;
    
bool rescurse(int mask, int player,int score){
    if(dp[player][mask] != -1) return dp[player][mask];
    for(int i = 1; i <= mci; i++){
        int cmask = 1<<(i-1);
        if((mask&cmask) == 0){
            if(score+i >= dt || rescurse(mask|cmask,player^1,score+i) == false) return dp[player][mask] = 1;
        }   
    }
    return dp[player][mask] = 0;
}
    
bool canIWin(int m, int d) {
    mci = m;
    dt = d;
    dp.resize(2,vector<int>(1<<mci,-1));
    if(dt <= mci) return true;
    if(dt > ((mci*(mci+1)) /2)) return false;
    return rescurse(0,0,0);
}

int main()
{
    fast_io;
    
    int mc, d;
    cin >> mc >> d;
        
    cout << canIWin(mc,d) << "\n";
    
} 