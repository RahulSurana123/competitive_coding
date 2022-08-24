

/* 

    Solution by Rahul Surana

    ***********************************************************

Mysterious Chefland… Recently, Chef realised that Discuss, the educational system of Chefland, is out of date. 
Therefore, he is trying to find ways to update the infrastructure in the country. One possible way is to move all materials from Discuss to Discourse.

Chef will have access to Discourse if his knowledge and power become exactly equal to N and M respectively. Initially, he has power 1 and knowledge 1.

Chef can perform actions of the following types to improve his skills:

    ->  solve a problem — increase his knowledge by X
    ->  do a push-up — increase his power by Y
    ->  install ShareChat to keep in touch with friends — increase both knowledge and power by 1

Chef can only install ShareChat at most once. The remaining actions may be performed any number of times and the actions may be performed in any order.

Help Chef find out whether it is possible to move from Discuss to Discourse.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains four space-separated integers N, M, X and Y.

Output

For each test case, print a single line containing the string "Chefirnemo" if it is possible to reach the required knowledge and power or "Pofik" if it is impossible.



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
#define fast_io     std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define MOD 1000000007 
using namespace std;


bool perfectSquare(ll a){
    return ceil(sqrt((double) a)) == floor(sqrt((double) a));
}


int main()
{
    fast_io;

    int t;
    cin >> t;
    
    while(t--) {

        ll n,m,x,y;
        cin >> n >> m >> x >> y;
        if((n==1 && m==2 && y > 1) || (n==2 &&m==1 &&x>1)) cout << "Pofik\n";
        if(((n-2)%x == 0 && (m-2)%y == 0) || ((n-1)%x == 0 && (m-1)%y == 0)) cout << "Chefirnemo\n";
        else cout << "Pofik\n";
        
    }
} 