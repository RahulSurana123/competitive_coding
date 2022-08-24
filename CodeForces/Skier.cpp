

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Skier rides on a snowy field. Its movements can be described by a string of characters 'S', 'N', 'W', 'E' (which correspond to 1 meter movement in the south, north, west or east direction respectively).

It is known that if he moves along a previously unvisited segment of a path (i.e. this segment of the path is visited the first time), then the time of such movement is 5 seconds. If he rolls along previously visited segment of a path (i.e., this segment of the path has been covered by his path before), then it takes 1 second.

Find the skier's time to roll all the path.

Input:

The first line contains an integer t (1≤t≤104) — the number of test cases in the input. Then t test cases follow.
Each set is given by one nonempty string of the characters 'S', 'N', 'W', 'E'. The length of the string does not exceed 105 characters.
The sum of the lengths of t given lines over all test cases in the input does not exceed 105.

Output:

For each test case, print the desired path time in seconds.



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
        set<vector<int>> se;
        int ans = 0;
        int x = 0, y = 0;
        // se.insert({0,0});
        for(int i = 0; i<s.length(); i++){
            int l=x,m=y;
            if(s[i] == 'N') l++;
            if(s[i] == 'S') l--;
            if(s[i] == 'W') m--;
            if(s[i] == 'E') m++;
            
            if(se.count({x,y,l,m}) || se.count({l,m,x,y})) ans++;
            else { ans+=5; se.insert({x,y,l,m}); }
            x =l;
            y=m;
        }
        cout <<ans<<"\n";
    }
}
