
/* 

    Solution by Rahul Surana

    ***********************************************************

Ada gives John a positive integer N. She challenges him to construct a new number (without leading zeros), 
that is a multiple of 9, by inserting exactly one digit (0 … 9) anywhere in the given number N. 
It is guaranteed that N does not have any leading zeros.

As John prefers smaller numbers, he wants to construct the smallest such number possible. Can you help John?

Input
The first line of the input gives the number of test cases, T. T test cases follow.

Each test case has a single line containing a positive integer N: the number Ada gives John.

Output
For each test case, output one line containing Case #x: y, where x is the test case number 
(starting from 1) and y is the new number constructed by John. As mentioned earlier, y cannot have leading zeros.

Limits
Memory limit: 1 GB.
1≤T≤100.


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
        ll s = 0;
        string a;
        cin >> a;
        for(int i = 0; i< a.length(); i++){
            s += a[i] - '0'; 
        }
        int x = s%9;
        x = 9 - x;
        string ans;
        if(x == 9){
            ans += a[0];
            ans+='0';
            ans+= a.substr(1);
        }
        else{
            int k = 0;
            while(k < a.length() && (a[k]-'0') <= x) k++;
            ans += a.substr(0,k);
            ans += ('0'+x);
            ans += a.substr(k);
        }
        cout << "Case #" << w << ": " << ans <<"\n";
        w++;
    }
}
