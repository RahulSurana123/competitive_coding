
/* 

    Solution by Rahul Surana

    ***********************************************************

You have  rectangles. 
A rectangle is golden if the ratio of its sides is in between , both inclusive. 
Your task is to find the number of golden rectangles.



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
    int n,c=0;
    cin >> n;
    FOR(i,n){
        double a,b;
        cin>>a>>b;
        if (a >b){
            if ((a/b) <=1.7 && (a/b)>=1.6) c++;
        } 
        else {
            if((b/a)<=1.7 && (b/a)>=1.6) c++;
            }  
    // cout <<(a/b) <<" "<< (b/a)<<"\n";
    }
    cout << c;    

}