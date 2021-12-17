

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Polycarp has come up with a new game to play with you. He calls it "A missing bigram".

A bigram of a word is a sequence of two adjacent letters in it.

For example, word "abbaaba" contains bigrams "ab", "bb", "ba", "aa", "ab" and "ba".

The game goes as follows. First, Polycarp comes up with a word, consisting only of lowercase letters 'a' and 'b'. Then, he writes down all its bigrams on a whiteboard in the same order as they appear in the word. After that, he wipes one of them off the whiteboard.

Finally, Polycarp invites you to guess what the word that he has come up with was.

Your goal is to find any word such that it's possible to write down all its bigrams and remove one of them, so that the resulting sequence of bigrams is the same as the one Polycarp ended up with.

The tests are generated in such a way that the answer exists. If there are multiple answers, you can print any of them.

Input:

The first line contains a single integer t (1≤t≤2000) — the number of testcases.
The first line of each testcase contains a single integer n (3≤n≤100) — the length of the word Polycarp has come up with.
The second line of each testcase contains n−2 bigrams of that word, separated by a single space. Each bigram consists of two letters, each of them is either 'a' or 'b'.

Additional constraint on the input: there exists at least one string such that it is possible to write down all its bigrams, except one, so that the resulting sequence is the same as the sequence in the input. In other words, the answer exists.

Output:

For each testcase print a word, consisting of n letters, each of them should be either 'a' or 'b'. It should be possible to write down all its bigrams and remove one of them, so that the resulting sequence of bigrams is the same as the one Polycarp ended up with.
The tests are generated in such a way that the answer exists. If there are multiple answers, you can print any of them.



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


// int ar[200001];

// int compare(int a, int b){
//     return ar[a] < ar[b];
// }

int main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<string> s(n-2);
        FOR(i,n-2)  { cin >> s[i]; }
        string ans(s[0]);
        for(int i = 1; i < s.size();i++){
            if(s[i][0] == s[i-1][1]) ans += s[i][1];
            else ans += s[i];
            // cout << ans <<" ";
        }
        while(ans.length() != n) ans += s[s.size()-1][1];
        cout << ans <<"\n";
    }
}
