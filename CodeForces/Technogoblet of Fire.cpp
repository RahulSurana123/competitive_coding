

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Everybody knows that the m-coder Tournament will happen soon. m schools participate in the tournament, and only one student from each school participates.

There are a total of n students in those schools. Before the tournament, all students put their names and the names of their schools into the Technogoblet of Fire. 
After that, Technogoblet selects the strongest student from each school to participate.

Arkady is a hacker who wants to have k Chosen Ones selected by the Technogoblet. Unfortunately, not all of them are the strongest in their schools, 
but Arkady can make up some new school names and replace some names from Technogoblet with those. 
You can't use each made-up name more than once. 
In that case, Technogoblet would select the strongest student in those made-up schools too.

You know the power of each student and schools they study in. Calculate the minimal number of schools Arkady has to make up so that k Chosen Ones would be selected by the Technogoblet.

Input:

The first line contains three integers n, m and k (1≤n≤100, 1≤m,k≤n) — the total number of students, the number of schools and the number of the Chosen Ones.
The second line contains n different integers p1,p2,…,pn (1≤pi≤n), where pi denotes the power of i-th student. The bigger the power, the stronger the student.
The third line contains n integers s1,s2,…,sn (1≤si≤m), where si denotes the school the i-th student goes to. At least one student studies in each of the schools.
The fourth line contains k different integers c1,c2,…,ck (1≤ci≤n)  — the id's of the Chosen Ones.

Output:

Output a single integer  — the minimal number of schools to be made up by Arkady so that k Chosen Ones would be selected by the Technogoblet.



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
 
using namespace std;



int main()
{
    fast_io;
    // int t;
    // cin >> t;
    // while(t--) {
        int n,m,k;
        cin >> n >> m >> k;
        map<int,int> x;
        int p[n+1], sid[n+1], s[k+1];
        FOR(i,n) cin >> p[i];
        FOR(i,n) { cin >> sid[i]; if(x.find(sid[i]) == x.end()) x[sid[i]] = i;  if(p[i] > p[x[sid[i]]]) x[sid[i]] = i; }
        FOR(i,k) { cin >> s[i]; }
        int ans = 0;
        for(int i = k-1; i >=0; i--){
            if(x[sid[s[i]-1]] != s[i]-1) { 
                ans++; 
            }
        }
        cout << ans <<"\n";
    // }
}
