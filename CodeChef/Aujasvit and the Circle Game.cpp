

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Aujasvit just came up with a new game to play with his friends. N people stand in a circle, each assigned an index from 1 to N in clockwise order. Then the following operation is done N−1 times.

The person with the lowest index holds a coin.
Then, the coin then moves to the next person clockwise M−1 times.
Then, the person who is holding the coin is removed from the circle.
The last person remaining after N−1 operations is the winner.

Aujasvit has already decided on the integer M to be used in the game. Before inviting people to play his game, Aujasvit wants to know the winner if the game has 1 player, 2 players, 3 players, …, X players. That is, you need to output the winner when N=1,N=2,...,N=X.

Input Format

The first line of each input contains T - the number of test cases. The test cases then follow.
The only line of each test case contains two space-separated integers M and X.

Output Format

For each testcase, output X integers A1,A2,…,AX, where Ai is the index of the winner if i people are playing this game.


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
    int t;
    cin >> t;
    while(t--) {
        int m,x;
        cin >> m >> x;
        m--;
        vector<int> ans(x);
        ans[0] = 1;
        
        for(int i = 1; i < x; i++){
            int z = (m%(i+1)) +1;
            if(ans[i-1]<z)ans[i] =ans[i-1];
            else ans[i] = ans[i-1]+1; 
        }
        for(int k = 0; k < x; k++) cout << ans[k] <<" ";
        cout <<"\n";
    }
}
