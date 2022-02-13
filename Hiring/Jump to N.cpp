

/* 
    Solution by Rahul Surana
    
    ***********************************************************

Jump to N

There are N squares in a row numbered from 1 to N from left to right. Alice asked Bob to go from square number 1 to square number N. But Alice marked some of the squares forbidden, i.e Bob can’t go to that square which is marked as forbidden.

Bob is allowed to take a jump of size X or less, i.e if currently, Bob is standing on the square number i then in one jump he is allowed to go to any of the squares numbered i+1, i+2, …, i+X.

You have been given a binary string S of length N. If i-th square is forbidden then S[i] will be ‘0’ otherwise S[i] will be ‘1’. Bob asked you to print “YES” if it is possible to go to square number N without going to any forbidden square otherwise print “NO”.

Note:- Square numbers 1 and N will not be forbidden.

Constraints

• 1 <= t <= 10^3 
• 1 <= X <= N <= 10^5
• 0 <= S[i] <=  1

Input Format

• First-line contains a single integer t, the number of test cases.
• The first line of each test case contains two integers N, and X.
• The second line of each test case contains a binary string S of length N.
• The sum of N over all test cases doesn’t exceed 2*10^5
Output Format
For each test case, output a single line— Print “YES” if it is possible to go to square number N from square number 1 without going to any forbidden square otherwise print “NO”.(Output should be in uppercase English letter without Quotation marks).



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
        int n, x;
        cin >> n >> x;
        string s;
        cin >> s;
        int c = 0;
        int ans = 0;
        for(int i = 0 ; i < n; i++){
            if(s[i] == '0') c++;
            else c = 0;
            ans = max(ans,c);
        }
        if(ans < x) cout << "YES\n";
        else cout << "NO\n";
    }
}
