
/* 

    Solution by Rahul Surana

    ***********************************************************

Problem
You are part of the executive committee of the Database Design Day festivities. 
You are in charge of promotions and want to print three D's to create a logo of the contest. 
You can choose any color you want to print them, but all three have to be printed in the same color.

Illustration of Sample #1.

You were given three printers and will use each one to print one of the D's. All printers use ink from 4 individual cartridges of different colors (cyan, magenta, yellow, and black) to form any color. 
For these printers, a color is uniquely defined by 4 non-negative integers c, m, y, and k, 
which indicate the number of ink units of cyan, magenta, yellow, and black ink (respectively) needed to make the color.

The total amount of ink needed to print a single D is exactly 106 units. For example, printing a D in pure yellow would use 106 units of yellow ink and 0 from all others. Printing a D in the Code Jam red uses 0 units of cyan ink, 500000 units of magenta ink, 450000 units of yellow ink, and 50000 units of black ink.

To print a color, a printer must have at least the required amount of ink for each of its 4 color cartridges. Given the number of units of ink each printer has in each cartridge, output any color, defined as 4 non-negative integers that add up to 106, such that all three printers have enough ink to print it.

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of 3 lines. The i-th line of a test case contains 4 integers Ci, Mi, Yi, and Ki, representing the number of ink units in the i-th printer's cartridge for the colors cyan, magenta, yellow, and black, respectively.

Output
For each test case, output one line containing Case #x: r, where x is the test case number (starting from 1) and r is IMPOSSIBLE if there is no color that can be printed by all 3 printers. Otherwise, r must be equal to "c m y k" where c, m, y, and k are non-negative integers that add up to 106 and c≤Ci, m≤Mi, y≤Yi, and k≤Ki, for all i.

If there are multiple solutions, you may output any one of them. (See "What if a test case has multiple correct solutions?" in the Competing section of the FAQ.) This information about multiple solutions will not be explicitly stated in the remainder of the 2022 contest.


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
#define FOR(i,n) for(int i = 0; i < n; i++)
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

        vector<vector<int>> ar(3,vector<int>(4,0));
        vector<int> c(4,1e6);
        FOR(i,3){
        	FOR(j,4){
        		cin >> ar[i][j];
        		c[j] = min(c[j],ar[i][j]);
        	}
        }
        // cout <<  c[0] <<" "<<c[1]<<" "<<c[2] <<" "<<c[3] <<"\n";
        int ans = 1e6;
        vector<int> p(4,0);
        cout << "Case #" << w << ": ";
        if(ans > 0) { p[0] = min(c[0],ans); ans -= p[0]; }
        if(ans > 0) { p[1] = min(c[1],ans); ans -= p[1]; }
        if(ans > 0) { p[2] = min(c[2],ans); ans -= p[2]; }
        if(ans > 0) { p[3] = min(c[3],ans); ans -= p[3]; }
        if(ans > 0) {
         	cout << "IMPOSSIBLE"<<"\n";
        }
        else{
        	cout << p[0] <<" "<<p[1]<<" "<<p[2] <<" "<<p[3] <<"\n";
        }
        w++;
    }
        
}