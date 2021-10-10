

/* 
    Solution by Rahul Surana
    
    ***********************************************************


The grandest stage of all, Wrestlemania XXX recently happened. 
And with it, happened one of the biggest heartbreaks for the WWE fans around the world. The Undertaker's undefeated streak was finally over.

Now as an Undertaker fan, you're disappointed, disheartened and shattered to pieces. And Little Jhool doesn't want to upset you in any way possible. 
(After all you are his only friend, true friend!) Little Jhool knows that you're still sensitive to the loss, so he decides to help you out.

Every time you come across a number, Little Jhool carefully manipulates it. He doesn't want you to face numbers which have "21" as a part of them. 
Or, in the worst case possible, are divisible by 21.

If you end up facing such a number you feel sad... and no one wants that - because you start chanting "The streak is broken!" , 
if the number doesn't make you feel sad, you say, "The streak lives still in our heart!"

Help Little Jhool so that he can help you!

Input Format:
The first line contains a number, t, denoting the number of test cases.
After that, for t lines there is one number in every line.

Output Format:
Print the required string, depending on how the number will make you feel.



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


int main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n%21==0) { cout << "The streak is broken!\n"; continue; }
        string s = to_string(n);
        bool f = false;
        for(int i = 0; i < s.length()-1;i++){
            if(s[i] == '2' && s[i+1] == '1') f = true;
        }
        if(f) cout << "The streak is broken!\n";
        else cout << "The streak lives still in our heart!\n";
    }
}