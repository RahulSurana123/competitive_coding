

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Note:
The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.



    ***********************************************************
*/


#include <bits/stdc++.h>

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    
    //Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int>&K,vector<int>&T,int N)
    {
        if(K[0] == T[0] && K[1] == T[1]) return 0;
        queue<pair<int,int>> q;
        q.push({K[0],K[1]});
        int step = 0;
        int v[N+1][N+1];
        for(int i = 0; i < N+1; i++)
        for(int j = 0; j < N+1; j++) v[i][j] =0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x == T[0] && y == T[1]){ return step; }
                if(x < 1 || y < 1 || x>N || y>N) continue;
                if(v[x][y]) continue;
               // cout<< x<<" "<< y<<"\n";
                v[x][y] = 1;
                q.push({x+2,y+1});
                q.push({x+2,y-1});
                q.push({x+1,y+2});
                q.push({x-1,y+2});
                q.push({x-2,y+1});
                q.push({x-2,y-1});
                q.push({x+1,y-2});
                q.push({x-1,y-2});
            }        
            step++;
        }
        return -1;
    }
};

// { Driver Code Starts.
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        vector<int>KnightPos(2);
        vector<int>TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans <<"\n";
    }
    return 0;
}  // } Driver Code Ends