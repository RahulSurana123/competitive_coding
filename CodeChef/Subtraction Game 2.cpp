

/* 

    Solution by Rahul Surana

    ***********************************************************

Chef is playing a game on a sequence of N positive integers, say A1,A2,...AN The game is played as follows.

-> If all the numbers are equal, the game ends.
-> Otherwise
    () Select two numbers which are unequal
    () Subtract the smaller number from the larger number
    () Replace the larger number with the result from above
Chef has already figured out that the game always terminates. 
He also knows, for a given sequence of integers, the game will always terminate on the same value, no matter how the game is played. 
Chef wants you to simulate the game for him and tell him if the game terminates on 1.

In fact, there may be many such games. Given a sequence of integers Chef wants to know the number of sub-sequences of the given sequence, for which, 
playing the above game on the subsuquence will terminate on 1. 
A sub-sequence can be obtained from the original sequence by deleting 0 or more integers from the original sequence. See the explanation section for clarity.

Input

The first line of the input contains an integer T, the number of test cases. Then follow the description of T test cases.
The first line of each test case contains a single integer N, the length of the sequence.
The second line contains N positive integers, each separated by a single space.

Output

For each test case, output a single integer - the number of sub-sequences of the original sequence, such that, 
playing the game on the sub-sequence results in ending the game with all the values equal to 1.



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

int ar[60];
ll ans;
vector<vector<int>> seq;
int gcd(int a, int b){
    while(b)              // while b is non-zero
    {
       int temp = b;      // cache current value of b
       b = (a % b);       // set b equal to (a modulo b)
       a = temp;          // set a equal to the original value of b
    }
    return a; 
}

int findGCD(vector<int> arr)
{
    int result = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        result = gcd(arr[i], result);
 
        if(result == 1)
        {
           return 1;
        }
    }
    return result;
}

void combo(int n, int index,vector<int> subarr){
    if(index == n){
        if(subarr.size() != 0) seq.pb(subarr);
        // ans += (findGCD(subarr) == 1);
        // cout << ans << "\n";
    }
    else {
        combo(n,index + 1, subarr);
        subarr.push_back(ar[index]);
        combo(n,index + 1, subarr);
    }
    // cout << ans << "\n";
}

int main()
{
    fast_io;
    int t;
    cin >> t;

    while(t--) {
    seq.clear();
    int n;
    cin >> n;
    FOR(i,n) cin >> ar[i];
    // FOR(i,n) cout << ar[i] <<" ";
    ans = 0;
    vector<int> b;
    combo(n,0,b);
    // FOR(i,seq.size()) { FOR(j,seq[i].size()) cout << seq[i][j] << " "; cout << "\n"; }
    // cout << "****************\n";
    FOR(i,seq.size()) ans += (findGCD(seq[i]) == 1) ;
    cout << ans << "\n";

    }
} 