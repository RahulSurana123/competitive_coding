

/* 
    Solution by Rahul Surana
    
    ***********************************************************


This Diwali, Chef has decided to treat himself to a laddu feast. Chef's friends brought him some laddus, 
which he stored in an array A. It is guaranteed that the length of A is a power of 2. 
The ith element of the array A is a laddu of size Ai. 
Chef would like to eat every laddu, but sadly he is on a diet and is allowed to eat only one laddu. 
He came up with a novel way to resolve this problem.

Chef performs the following steps in order:

First, he pairs up every laddu from A with some other laddu - if there are N laddus in A, exactly N/2 pairs are created, with each laddu being in exactly one of the pairs. 
Further, every pair (x,y) must satisfy the condition |x−y|≤1; in other words, the sizes of the laddus in each pair cannot differ by more than 1.
Next, for each pair of laddus (x,y) formed in step 1, mash them together to form a new laddu of size x+y. At the end of this process, 
Chef is left with exactly N/2 laddus. Repeat the process with the N/2 laddus he now has.
At any point in time, if Chef is unable to form N/2 pairs (either because N=1, 
or because there is no way to pair up laddus satisfying the condition on their sizes) he will immediately stop the process.

If there is only one laddu left in A when the process stops, Chef considers his efforts to be a success; else he considers it a failure.

Print "YES" if there is a way for Chef to achieve success, else print "NO".

Input Format:

The first line contains a single integer T, denoting the number of testcases. The description of T testcases follows.
Each testcase consists of two lines:
The first line contains an integer N, denoting that Chef starts with 2N laddus.
The next line contains 2N space-separated integers, denoting the initial sizes of the laddus.

Output Format:

For each testcase, output in a single line "YES" or "NO"; the answer to the problem.
You may print each character of the answer in uppercase or lowercase 
(for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).



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
        int x = (1<<n); 
        vector<int> ar(x);
        FOR(i,x) cin >> ar[i];
        sort(ar.begin(),ar.end());
        // bool f = false;
        int diff =  0;
        // int level = 1;
        for(int i = 1; i < x; i++){
            diff += (ar[i]- ar[i-1]);
            // if( i == (1<<level) && diff > level) { f = true; break; }  
        }
        // while(ar.size() > 0){
        //     vector<int> nar(ar.size()/2);
        //     if(ar.size() == 1) break;
        //     // FOR(i,ar.size()) cout << ar[i]<<" ";
        //     // cout<<"\n";
        //     // FOR(i,nar.size()) cout << nar[i]<<" ";
        //     // cout<<"\n";
        //     for(int i = 0; i < ar.size(); i+=2){
        //         if(ar[i+1]-ar[i] > 1) { f = true; break; }
        //         else{ nar[i/2] = ar[i+1]+ar[i]; }
        //     }
        //     ar.clear();
        //     ar.resize(ar.size()/2);
        //     swap(ar,nar);
        // }
        if(diff>1) cout << "NO\n";
        else cout << "YES\n";
    }
}
