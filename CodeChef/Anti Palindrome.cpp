

/* 
    Solution by Rahul Surana
    
    ***********************************************************


A (1-indexed) string S of length N is said to be anti-palindrome if, for each 1≤i≤N, Si≠S(N+1−i).

You are given a string S of length N (consisting of lowercase Latin letters only). 
Rearrange the string to convert it into an anti-palindrome or determine that there is no rearrangement which is an anti-palindrome.

If there are multiple rearrangements of the string which are anti-palindromic, print any of them.

Input Format:

The first line of input contains a single integer T — the number of test cases. The description of T test cases follows.
The first line of each test case contains an integer N — the length of the string S.
The second line of each test case contains the string S.

Output Format:

For each test case, if it is possible to rearrange S to convert it into an anti-palindrome, 
print YES in the first line and print the rearranged string in the second line. Otherwise, print NO.
You may print each character of YES and NO in uppercase or lowercase (for e.g. yes, yEs, Yes will be considered identical).
If there are multiple rearrangements of the string which are anti-palindromic, print any of them.



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
        string s;
        cin >> s;
        int f[26];
        FOR(i,26) f[i] = 0;
        FOR(i,n) f[s[i] - 'a']++;

        if(n%2 == 1) cout << "NO\n";
        else{
            bool fa = false, fc = false;
            int x = 0;
            vector<int> a1,a2;
            FOR(i,26){
                if(f[i] > (n/2)) fa = true;
                if(f[i] == (n/2)) { fc = true; x = i; f[i] = 0; break;  }
                if(f[x] <= f[i]) { x = i; }
                if(f[i] %2 == 0 && f[i] != 0) a2.push_back(i);
                else if(f[i] %2 == 1) a1.push_back(i);
            }
            if(fa) { cout <<"NO\n"; continue; }
            else if(fc){
                string ans(n,x+'a');
                int k = 0;
                for(int i = 0; i<26;i++){
                    while(k < n && f[i]>0) { ans[k++] = i+'a'; f[i]--; }
                }
                cout << "YES\n" << ans <<"\n";
                continue;
            } 
            else {
                string ans(n,' ');
                int j = n-1;
                int k = 0;
                for(auto z: a2){
                    // cout << z <<" ";
                    while(f[z] > 0){
                        if(k<n/2){
                            ans[k++] = z + 'a';
                            f[z]--;
                        }
                        else{
                            ans[j--] = z + 'a';
                            f[z]--;   
                        }
                    }
                }
                // cout <<" ";
                for(auto z: a1){
                    while(f[z] > 0){
                        if(k<n/2){
                            ans[k++] = z + 'a';
                            f[z]--;
                        }
                        else{
                            ans[j--] = z + 'a';
                            f[z]--;   
                        }
                    }
                }
                cout << "YES\n" << ans <<"\n";
            }
        }
    }
}
