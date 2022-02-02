

/* 
    Solution by Rahul Surana
    
    ***********************************************************


A hostel has N rooms in a straight line. It has to accommodate X people. 
Unfortunately, out of these X people, Y of them are infected with chickenpox. 
Due to safety norms, the following precaution must be taken:

No person should occupy a room directly adjacent to a room occupied by a chickenpox-infected person. 
In particular, two chickenpox-infected people cannot occupy adjacent rooms.
For example, if room 4 has a chickenpox-infected person, then nobody should occupy rooms 3 and 5. 
Similarly, if room 1 has a chickenpox-infected person then nobody should occupy room 2.

What's the minimum value of N for which all the people can be accommodated in the hostel, following the above condition?

Input Format:

The first line of input contains a single integer T — the number of test cases. The description of T test cases follows.
The first and only line of each test case contains two integers X and Y — the total number of people and the number of chickenpox-infected people.

Output Format:

For each test case, output on a new line a single integer — the minimum value of N for which all the people can be accommodated in the hostel.



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
        int x, y;
        cin >> x >> y;
        int ans;
        if(x == y){
            ans = (2*y) -1;
        }
        else{
            ans = (2*y) +x-y;
        }
        cout << ans <<"\n";
    }
}
