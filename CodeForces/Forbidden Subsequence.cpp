

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given strings S and T, consisting of lowercase English letters. It is guaranteed that T is a permutation of the string abc.

Find string S′, the lexicographically smallest permutation of S such that T is not a subsequence of S′.

String a is a permutation of string b if the number of occurrences of each distinct character is the same in both strings.

A string a is a subsequence of a string b if a can be obtained from b by deletion of several (possibly, zero or all) elements.

A string a is lexicographically smaller than a string b if and only if one of the following holds:

a is a prefix of b, but a≠b;
in the first position where a and b differ, the string a has a letter that appears earlier in the alphabet than the corresponding letter in b.
Input
Each test contains multiple test cases. The first line contains a single integer t (1≤t≤1000) — the number of test cases. Description of the test cases follows.

The first line of each test case contains a string S (1≤|S|≤100), consisting of lowercase English letters.

The second line of each test case contains a string T that is a permutation of the string abc. (Hence, |T|=3).

Note that there is no limit on the sum of |S| across all test cases.

Output
For each test case, output a single string S′, the lexicographically smallest permutation of S such that T is not a subsequence of S′.


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

int ar[27];
map<int,int> m;
// vector<vector<int>> dp;
// int ans = 0;

int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--) {
        string s,t;
        cin >> s;
        cin >> t;
        FOR(i,27) ar[i] = 0;
        FOR(i,s.length()) ar[s[i]-'a']++;
        string ans = "";
        if(t == "abc" && ar[0] > 0){
            while(ar[0] > 0) { ans += 'a'; ar[0]--; }
            while(ar[2] > 0) { ans += 'c'; ar[2]--; }  
            FOR(i,26){
                while(ar[i] > 0){
                    ans += i +'a';
                    ar[i]--; 
                }
            }
        }
        else {
            FOR(i,26){
                while(ar[i] > 0){
                    ans += i +'a';
                    ar[i]--; 
                }
            } 
        }
        cout << ans <<"\n";  
    }
}
