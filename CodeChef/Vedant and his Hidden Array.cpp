

/* 
    Solution by Rahul Surana
    
    ***********************************************************

Vedant has a hidden array of N elements. Given the bitwise AND of all elements of the array, determine whether the total sum of the elements is odd, even or cannot be determined.

Input Format

The first line of each input contains T - the number of test cases. The test cases then follow.
The only line of each test case contains two space-separated integers N and A - the number of elements in the hidden array and the bitwise AND of all the elements in the hidden array.

Output Format

For each test case, output Even if the sum of all elements in the hidden array is even, Odd if the sum of all elements in the hidden array is odd, or Impossible if the parity cannot be determined.

Note: You may print each character of the string in uppercase or lowercase (for example, the strings eVen, EvEn, even and EVEN will all be treated as identical).



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
        int n,a;
        cin >> n >> a;
        if((a&1) && n%2 == 1) cout << "Odd\n";
        else if(((a&1) && n%2 == 0)) cout << "Even\n";
        else if((!(a&1) && n == 1)) cout << "Even\n";
        else cout << "Impossible\n";
    }
}
