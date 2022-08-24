
/* 

    Solution by Rahul Surana

    ***********************************************************

You are given a string S.You need to check whether it's a palindrome or not. Print "YES" (without quotes) if S is a palindrome and "NO" (without quotes) if S is not a palindrome.

To know what a palindrome is you can check http://bit.ly/HashesPallindrome

INPUT First line will contain an integer T that is the number of test cases. The following T lines will contain: -A string S consisting of only lowercase letters.

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
int inf=1e9+7,MOD=1e9+7;

int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--){
        string s;
        int f = 1;
        cin>>s;
        FOR(i,(int)s.length()/2){
            if(s[i]!=s[s.length()-i-1]) {
                cout<<"NO\n"; 
                f=0; 
                break;
            }
        }
        if(f == 1) cout<< "YES\n";
    }
    

}