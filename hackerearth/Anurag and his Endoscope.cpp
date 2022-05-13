/* 

    Solution by Rahul Surana

    ***********************************************************

Anurag, a CSE student from MANIT developed an endoscope to explore inner part of ruined water pipes. 
It is possible explore the inner part of the pipes putting the endoscope into a certain part of the pipe. 
The endoscope can be moved in the pipes only. Meanwhile, when the pipes are connected to each other, 
if the length of the endoscope is long enough to explore, it is able to inspect the connected pipe. 
However, we cannot observe every pipe because the length of the endoscope is limited.

When the map of the ground water pipe, the location where the endoscope to out in, 
and the length of the endoscope is given, calculate the number of pipe which are available to explore. 
Length of endoscope means the range upto which endoscope can explore. 
There are seven kind of pipes, and description for each pipe are shown below

enter image description here - 1 enter image description here - 2 enter image description here - 3 enter image 
description here - 4 enter image description here - 5 enter image description here - 6 enter image description here - 7

Fig 1 Shows an example of a map of ground water pipes. In this case, the height of the map is 5, and the width is 6 
If a certain point where the endoscope to put in is given as (2,1), it means the vertical location will be 2, 
and the horizontal location will be 1, shown as a red highlighted pipe in fig 2. If the length of the endoscope is 1, 
we can explore only one water pipe which is at the intersection point If the length of the endoscope is 2, 
we can explore 3 water pipes including a blue highlighted pipe and a red marked pipe with the endoscope Fig-3 . 
If the length of the endoscope is 3, we can explore 5 water pipes total Fig-4

enter image description here ::Fig-1

enter image description here ::Fig-2

enter image description here ::Fig-3

enter image description here ::Fig-4

INPUT:

In the first line, T, the number of total test cases is given. From the second line, T test cases are given. 
In the first line of each test case, N, the height of the map of the ground water pipes, M, 
the width, R, the vertical location of the water pipe where to put in the endoscope, 
C, the horizontal location of it, and the length of the endoscope L are given. 
In the following N lines information of the map of ground water pipe is given. Each line has M numbers. 
Each number (from 1 to 7) means the type of water pipe for that point. 
0 means there is no water pipe buried in that place.

OUTPUT:

Print the respective answer for T test cases in total for T lines. 
The answer is the number of water pipes which is available to observe using the endoscope.



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

map<int,set<string>> map_s;
vector<vector<bool>> v;
map<string,string> ee_map; 

int main()
{
    fast_io;
    int t;
    cin >> t;
    map_s[0] = {};
    map_s[1] = {"UP","DOWN","LEFT","RIGHT"};
    map_s.insert({2,{"UP","DOWN"}});
    map_s.insert({3,{"LEFT","RIGHT"}});
    map_s.insert({4,{"UP","RIGHT"}});
    map_s.insert({5,{"DOWN","RIGHT"}});
    map_s.insert({6,{"DOWN","LEFT"}});
    map_s.insert({7,{"UP","LEFT"}});
    ee_map.insert({"UP","DOWN"});
    ee_map.insert({"DOWN","UP"});
    ee_map.insert({"LEFT","RIGHT"});
    ee_map.insert({"RIGHT","LEFT"});
    while(t--) {
        int n,m,x,y,l;
        cin >> n >> m >> x >> y >> l;
        vector<vector<int>> ar(n,vector<int>(m,0));
        v.clear();
        v.resize(n,vector<bool>(m,false));
        FOR(i,n) {
            FOR(j,m){
                cin >> ar[i][j];
                // cout << ar[i][j] <<" ";
            }
            // cout << "\n";
        }
        if(ar[x][y] == 0) { cout << "0\n"; continue; }
        int ans = 0;
        v[x][y] = true;
        queue<vector<int>> q;
        q.push({x,y});
        while(!q.empty()){
            int s = q.size();
            ans += s;
            if(l==1) break;
            while(s--){
                vector<int> a = q.front();
                q.pop();
                if(ar[a[0]][a[1]] == 0) continue;
                v[a[0]][a[1]] = true;
                for(auto z: map_s[ar[a[0]][a[1]]]){
                    if(z == "UP" && a[0] - 1 >= 0 && ar[a[0] - 1][a[1]] != 0 && !v[a[0] - 1][a[1]] && map_s[ar[a[0] - 1][a[1]]].count(ee_map[z])){
                        // cout << a[0]-1<<" "<<a[1] <<" "<< z <<" " << map_s[ar[a[0] - 1][a[1]]].count(ee_map[z])<<" "<< ar[a[0] - 1][a[1]] <<"\n";
                        v[a[0] - 1][a[1]] = true;
                        q.push({a[0]-1,a[1]});
                    }
                    if(z == "DOWN" && a[0] + 1 < n && ar[a[0] + 1][a[1]] != 0 && !v[a[0] + 1][a[1]] && map_s[ar[a[0] + 1][a[1]]].count(ee_map[z])){
                        // cout << a[0] + 1<<" "<<a[1] <<" "<< z <<" " << map_s[ar[a[0] + 1][a[1]]].count(ee_map[z])<<" "<<ar[a[0] + 1][a[1]] <<"\n";
                        v[a[0] + 1][a[1]] = true;
                        q.push({a[0]+1,a[1]});
                    }
                    if(z == "RIGHT" && a[1] + 1 < m && ar[a[0]][a[1]+1] != 0 && !v[a[0]][a[1]+1] && map_s[ar[a[0]][a[1]+1]].count(ee_map[z])){
                        // cout << a[0]<<" "<<a[1]+1 <<" "<< z <<" " << map_s[ar[a[0]][a[1]+1]].count(ee_map[z]) <<" " << ar[a[0]][a[1]+1]<<"\n";
                        v[a[0]][a[1]+1] = true;
                        q.push({a[0],a[1]+1});
                    }
                    if(z == "LEFT" && a[1] - 1 >= 0 && ar[a[0]][a[1]-1] != 0 && !v[a[0]][a[1]-1] && map_s[ar[a[0]][a[1]-1]].count(ee_map[z])){
                        // cout << a[0]<<" "<<a[1]-1 <<" "<< z <<" " << map_s[ar[a[0]][a[1]-1]].count(ee_map[z])<<" "<<ar[a[0]][a[1]+1] <<"\n";
                        v[a[0]][a[1]-1] = true;
                        q.push({a[0],a[1]-1});
                    }
                }
                
            }
            // cout << ans <<" "<<l<<"\n";
            l--;
        }

        cout << ans <<"\n";
    }
}