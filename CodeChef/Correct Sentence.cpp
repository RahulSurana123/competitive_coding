

/* 

    Solution by Rahul Surana

    ***********************************************************

Chef knows about two languages spoken in Chefland, but he is not proficient in any of them. The first language contains 
lowercase English letters between 'a' and 'm' inclusive and the second language contains only uppercase English letters between 'N' and 'Z' inclusive.

Due to Chef's limited vocabulary, he sometimes mixes the languages when forming a sentence — each word of Chef's sentence 
contains only characters from one of the languages, but different words may come from different languages.

You are given a sentence as a sequence of K words S1,S2,…,SK. Determine whether it could be a sentence formed by Chef, 
i.e. if it contains only the characters from the two given languages and each word contains only characters from a single language.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains an integer K followed by a space and K space-separated strings S1,S2,…,SK.

Output

For each test case, print a single line containing the string "YES" if the given sentence can be formed by Chef or "NO" if it cannot.
You may print each character of the string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).


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


bool same(int a,string s){
    bool ans = true;
    if(a==3) return false;
    if(a == 1) {
        for(int j = 0; j < s.length(); j++){
            if(!((int)s[j] > 90 && (int)s[j]<110)) return false; 
        }
    }
    if(a == 2) {
        for(int j = 0; j < s.length(); j++){
            if(!((int)s[j] > 77 && (int)s[j]<91)) return false; 
        }
    } 
    return true;
}

int main()
{
    fast_io;
    
    int t;
    cin >> t;
    
    while(t--) {

        ll k;
        cin >> k ;
        string s[k];
        int ar[k];
        FOR(i,k) { cin >> s[i]; if((int)s[i][0] > 77 && (int)s[i][0]<91) ar[i] = 2; else if((int)s[i][0] > 90 && (int)s[i][0]<110) ar[i] = 1; else ar[i] = 3; } 
        bool f = true;
        FOR(int i = 0; i <k ;i++){
            f = same(ar[i], s[i]);
            if(f == false) break;
        }
        if(f) cout << "YES\n";
        else cout << "NO\n";
    }
} 