

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Gintoki has been very lazy recently and he hasn't made enough money to pay the rent this month. So the old landlady has given him a problem to solve instead, 
if he can solve this problem the rent will be waived. The problem is as follows:

A triplet of integers (A,B,C) is considered to be special if it satisfies the following properties for a given integer N :

AmodB=C
BmodC=0
1≤A,B,C≤N
Example: There are three special triplets for N=3.

(1,3,1) is a special triplet, since (1mod3)=1 and (3mod1)=0.
(1,2,1) is a special triplet, since (1mod2)=1 and (2mod1)=0.
(3,2,1) is a special triplet, since (3mod2)=1 and (2mod1)=0.
The landlady gives Gintoki an integer N. Now Gintoki needs to find the number of special triplets. Can you help him to find the answer?

Input Format:

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single integer N.

Output Format:

For each testcase, output in a single line the number of special triplets.



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
        int c = 0;
        for(int i =1; i <= n; i++){
            for(int j = i; j <= n; j+=i){
                for(int k = i; k <=n; k+=j){
                    if(k%j == i && j%i == 0) c++;
                }
            }
        }
        cout << c << "\n";

    }
}
