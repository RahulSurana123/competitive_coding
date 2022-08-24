

/* 

    Solution by Rahul Surana

    ***********************************************************

Two strings A and B comprising of lower case English letters are compatible if they are equal or can be made equal by following this step any number of times:

Select a prefix from the string A (possibly empty), and increase the alphabetical value of all the characters in the prefix by the same valid amount. For example if the string is xyz and we select the prefix xy then we can convert it to yz by increasing the alphabetical value by 1. But if we select the prefix xyz then we cannot increase the alphabetical value.
Your task is to determine if given strings A and B are compatible.

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
    string a,b;
    cin >> a;
    cin >> b;
    if(a.length()!=b.length()){ cout<<"NO"; return 0;}
    if(a==b) cout<<"YES";
    else{
        int diff[a.length()];
        FOR(i,(int)a.length()){
            diff[i]=(int)b[i]-(int)a[i]; 
            // cout << diff[i] <<"  ";
        }
        reverse(diff,diff+a.length());
        bool sor = is_sorted(diff,diff+a.length());
        if(sor) cout<<"YES";
        else cout<<"NO";
    }
}