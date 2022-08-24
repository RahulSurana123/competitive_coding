

/* 


    Solution by Rahul Surana
    

    ***********************************************************

A wonderful string is a string where at most one letter appears an odd number of times.

For example, "ccjjc" and "abab" are wonderful, but "ab" is not.
Given a string word that consists of the first ten lowercase English letters ('a' through 'j'), return the number of wonderful non-empty substrings in word. 
If the same substring appears multiple times in word, then count each occurrence separately.

A substring is a contiguous sequence of characters in a string.

Input format

-> a String word. eg word = "aba"


Output format

Count of possible wonderful substrings.

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

vector<int> dp;

int main()
{
	fast_io;
	string word;
	cin >> word;
    dp.resize(1024,0);
    dp[0]=1;
    int curr = 0;
    long long ans = 0;
    for(int i = 0; i < word.length(); i++){
        curr ^= 1<<(word[i] - 'a');
        ans += dp[curr];
        for(int j = 0; j < 10;j++){
            ans+= dp[curr^1<<j];
        }
        dp[curr]++;
    }
    cout << ans;
}