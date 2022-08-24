
/* 

    Solution by Rahul Surana

    ***********************************************************

Manna is extremely disappointed to find out that no one in his college knows his first name. 
Even his classmates call him only by his last name. 
Frustrated, he decides to make his fellow college students know his first name by forcing them to solve this question.

You are given a long string as input in each testcase, containing any ASCII character. 
Your task is to find out the number of times SUVO and SUVOJIT appears in it.



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
    int n;
    string s[n],a="SUVOJIT";
    cin >> n;
    FOR(i,n){
        cin >> s[i];
    }
    FOR(i,n)
    {   int c=0,sc=0,sjc=0;
        FOR(j,s[i].length())
        {
            if(s[i][j]==a[c]){
                c++;
                if (c==7){
                sjc++;
                c=0;
                }
            }
            else{
                if (c>=4){
                sc++;
                }
                c=0;
                if(s[i][j]==a[c]) c++;
            }
            
        }
        if (c>=4 && c<7) sc++;
        if (c==7) sjc++;
        cout << "SUVO = " << sc << ", SUVOJIT = "<<sjc<<endl;
    }

}