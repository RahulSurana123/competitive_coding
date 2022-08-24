

/* 
    Solution by Rahul Surana
    
    ***********************************************************


A binary string is called alternating if no two adjacent characters of the string are equal. 
Formally, a binary string T of length M is called alternating if Ti≠Ti+1 for each 1≤i<M.

For example, 0, 1, 01, 10, 101, 010, 1010 are alternating strings while 11, 001, 1110 are not.

You are given a binary string S of length N. 
You would like to rearrange the characters of S such that the length of the longest alternating substring of S is maximum. 
Find this maximum value.

A binary string is a string that consists of characters 0 and 1. 
A string a is a substring of a string b if a can be obtained from b by deletion of several (possibly, zero or all) 
characters from the beginning and several (possibly, zero or all) characters from the end.

Input Format
The first line of input contains an integer T, denoting the number of test cases. The T test cases then follow:
The first line of each test case contains an integer N.
The second line of each test case contains the binary string S.
Output Format
For each test case, output the maximum possible length of the longest alternating substring of S after rearrangement.



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


int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string a;
        cin >> a;
        int e= 0,o=0;
        for(int i = 0; i < n; i++){
            if(a[i] == '1'){
                e++;
            }
            else{
                o++;
            }
        }
        ll ans = min(e,o)*2;
        if(e> o){
            ans = 2*o+1;
        }
        else if(e< o){
            ans = 2*e+1;
        }
        else{
            ans = 2*o;
        }
        if(ans == a.length()-1 && a.length()%2==1) ans = a.length();
        if(ans == 0) ans = 1;
        cout << ans <<"\n";
        // cout << ans <<"\n";
    }
}
