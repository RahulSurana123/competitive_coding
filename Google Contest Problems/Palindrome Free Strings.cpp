
/* 

    Solution by Rahul Surana

    ***********************************************************

You are given a string S consisting of characters 0, 1, and ?. You can replace each ? with either 0 or 1. Your task is to find if it is possible to assign each ? to either 0 or 1 such that the resulting string has no substrings that are palindromes of length 5 or more.

Input
The first line of the input gives the number of test cases, T. T test cases follow.

Each test case consists of two lines.
The first line of each test case contains an integer N, denoting the length of the string S.
The second line of each test case contains a string S of length N.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is POSSIBLE if there is a possible resulting string that has no palindromic substrings of length 5 or more, or IMPOSSIBLE otherwise.

Limits
Memory limit: 1 GB.
1≤T≤100.
S only consists of characters 0, 1 and ?.

Test Set 1
Time limit: 20 seconds.
1≤N≤15.
Test Set 2
Time limit: 90 seconds.
1≤N≤5×10^4


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
#define trace(x)    cerr<<#x<<" : "<<x<<endl;
#define trace2(x,y) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<" | "<<#z<<" : "<<z<<endl;
#define fast_io 	std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;

int MOD=1e9+7;

bool pal(string &s, int i, int j){
    if(i<0) return false;
    int l = i,r = j;
    while(i<j){
        if(s[i] != s[j]) { 
            // cout << s.substr(l,r-l+1) <<"\n"; 
            return false; 
        }
        i++; j--;
    }
    return true;
}

bool df(string &s, int i, int n){

    // cout << i <<"\n";
    if(i==n){
        return true;
    }
    bool f = true;
    if(s[i] == '?'){
        s[i] = '0';
        if(pal(s,i-4,i)) f = false;
        else if(pal(s,i-5,i)) f = false;
        if(f && df(s,i+1,n)) return true;
        s[i] = '1';
        f = true;
        if(pal(s,i-4,i)) f = false;
        else if(pal(s,i-5,i)) f = false;
        if(f && df(s,i+1,n)) return true;
        s[i] = '?';
    }
    else{
        if(pal(s,i-4,i)) f = false;
        else if(pal(s,i-5,i)) f = false;
        if(f && df(s,i+1,n)) return true;
    }
    return false;
}

int main()
{
	fast_io;
    int t,w = 1;
    cin >> t;
    while(t >= (w)){
        int n;
        cin >> n;
        string a;
        cin >> a;
        bool f = df(a,0,n);

        cout << "Case #" << w << ": " << (f?"POSSIBLE":"IMPOSSIBLE") <<"\n";
        w++;
    }
}
