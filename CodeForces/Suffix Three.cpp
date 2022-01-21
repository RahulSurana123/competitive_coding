

/* 
    Solution by Rahul Surana
    
    ***********************************************************


We just discovered a new data structure in our research group: a suffix three!

It's very useful for natural language processing. Given three languages and three suffixes, a suffix three can determine which language a sentence is written in.

It's super simple, 100% accurate, and doesn't involve advanced machine learning algorithms.

Let us tell you how it works.

If a sentence ends with "po" the language is Filipino.
If a sentence ends with "desu" or "masu" the language is Japanese.
If a sentence ends with "mnida" the language is Korean.
Given this, we need you to implement a suffix three that can differentiate Filipino, Japanese, and Korean.

Oh, did I say three suffixes? I meant four.

Input:

The first line of input contains a single integer t (1≤t≤30) denoting the number of test cases. The next lines contain descriptions of the test cases.
Each test case consists of a single line containing a single string denoting the sentence. Spaces are represented as underscores (the symbol "_") for ease of reading. 
The sentence has at least 1 and at most 1000 characters, and consists only of lowercase English letters and underscores. 
The sentence has no leading or trailing underscores and no two consecutive underscores. 
It is guaranteed that the sentence ends with one of the four suffixes mentioned above.

Output:

For each test case, print a single line containing either "FILIPINO", "JAPANESE", or "KOREAN" (all in uppercase, without quotes), depending on the detected language.



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

// int p[1001];


// void seive_of_erathros(){
//     p[0] = 0;
//     p[1] = 1;
//     for(int i = 2; i < 1000; i++){
//         p[i] = 1;
//         for(int j = i*i;j< 1000;j+=i){
//             p[i] = 0;
//         }
//     }
// }

int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        if(s.length() >= 2 && s.substr(s.length()-2,2) == "po") cout <<"FILIPINO\n";
        else if(s.length() >= 4 && (s.substr(s.length()-4,4) == "desu" || s.substr(s.length()-4,4) == "masu")) cout <<"JAPANESE\n";
        else if(s.length() >= 5 && (s.substr(s.length()-5,5) == "mnida")) cout <<"KOREAN\n";
        // cout << s.substr(s.length()-5,5)<<"\n";
    }
}
