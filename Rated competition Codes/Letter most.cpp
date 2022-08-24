
/* 

    Solution by Rahul Surana

    ***********************************************************

Lonely Y loves his string s of lowercase letters, Y is about to escape so he should choose just one lowercase letter c and carry all letters in s which is equal to c with himself.

What is the maximum number of letters Y can carry with himself?

Input

First line contains only n, legnth of string s.

Second line contains string s of lowercase letters.
 
1 < n <10^5

Output

The only line of output contains an integer which is maximum number of letters that Y can carry.

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

    int n,ar[26];
    cin >> n;
    
    string s;
    cin >> s;
    
    mem(ar,0);
    
    FOR(i,s.length())  ar[s[i]- 'a'] += 1;
        
    // cout << ar[s[i]- 'a'] <<" "<<s[i]<<" ";
    int ma = -1;
    
    FOR(i,26) if (ma<ar[i]) ma = ar[i];
    
    cout << ma;
}