

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Monocarp wrote down two numbers on a whiteboard. Both numbers follow a specific format: a positive integer x with p zeros appended to its end.

Now Monocarp asks you to compare these two numbers. Can you help him?

Input
The first line contains a single integer t (1≤t≤104) — the number of testcases.

The first line of each testcase contains two integers x1 and p1 (1≤x1≤106;0≤p1≤106) — the description of the first number.

The second line of each testcase contains two integers x2 and p2 (1≤x2≤106;0≤p2≤106) — the description of the second number.

Output
For each testcase print the result of the comparison of the given two numbers. If the first number is smaller than the second one, print '<'. 
If the first number is greater than the second one, print '>'. If they are equal, print '='.


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
    int t=1;
    cin >> t;
    while(t--){
        
        double n[2],m[2],k=0,l=0;
        FOR(i,2) cin >> n[i];
        FOR(i,2) cin >> m[i];
        while(n[0] > pow(10,k)) k++;
        while(m[0] > pow(10,l)) l++;
        // cout << n[0] << " "<<n[1]+k <<" "<< m[0] << " "<<m[1]+l<<" ";
        if(n[1]+k > m[1]+l) cout << ">\n";
        else if(n[1]+k < m[1]+l)  cout << "<\n";
        else{
            if(k>l) n[0] /= (int)(pow(10,k - l));
            else if(k<l) m[0]/=(int)(pow(10,l - k));
            if(n[0] > m[0]) cout<<">\n";
            else if(n[0] < m[0]) cout<<"<\n";
            else cout<<"=\n";
        }

        // cout << ans<<"\n";
    }
}