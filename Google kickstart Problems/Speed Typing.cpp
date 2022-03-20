
/* 

    Solution by Rahul Surana

    ***********************************************************

Barbara is a speed typer. In order to check her typing speed, she performs a speed test. 
She is given a string I that she is supposed to type.

While Barbara is typing, she may make some mistakes, such as pressing the wrong key. 
As her typing speed is important to her, she does not want to spend additional time correcting the mistakes, 
so she continues to type with the errors until she finishes the speed test. After she finishes the speed test, she produces a P.

Now she wonders how many extra letters she needs to delete in order to get I from P. 
It is possible that Barbara made a mistake and P cannot be converted back to I just by deleting some letters. 
In particular, it is possible that Barbara missed some letters.

Help Barbara find out how many extra letters she needs to remove in order to obtain I or 
if I cannot be obtained from P by removing letters then output IMPOSSIBLE.

Input
The first line of the input gives the number of test cases, T. T test cases follow.

Each test case has 2 lines. The first line of each test case is an input string I 
(that denotes the string that the typing test has provided). The next line is the produced string P 
(that Barbara has entered).

Output
For each test case, output one line containing Case #x: y, 
where x is the test case number (starting from 1) and y is the number of extra letters 
that need to be removed in order to obtain I. If it is not possible to obtain I then output IMPOSSIBLE as y.

Limits
Memory limit: 1 GB.
1≤T≤100.
Both the strings contain letters from a-z and A-Z.
Length of the given strings will be 1≤|I|,|P|≤105.


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


int main()
{
	fast_io;
    int t,w = 1;
    cin >> t;
    while(t >= (w)){

        ll ans = 0;
        string a,b;
        cin >> a;
        cin >> b;
         // cout << a << " " << b <<"\n";
        if(a.length()>=b.length()){
            if(a.length() == b.length() && a==b) ans = 0;
            else ans = -1;
        }
        else{
            int j = 0;
            for(int i = 0; i< a.length(); i++){
                while(i+j < b.length() && a[i] != b[i+j]) j++;
                if(i+j >= b.length()) { ans = -1; break; }
            }
            if(ans != -1)
            ans = b.length() - a.length();
        }
        cout << "Case #" << w << ": " << ((ans == -1)? "IMPOSSIBLE" : to_string(ans)) <<"\n";
        w++;
    }
        
}