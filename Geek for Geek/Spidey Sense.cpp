

/* 
    Solution by Rahul Surana
    
    ***********************************************************


He has a blueprint of the building which is a M x N matrix that is filled with the characters O, B, and W where: 
O represents an open space.
B represents a bomb.
W represents a wall.
You have to replace all of the Os (open spaces) in the matrix with their shortest 
distance from a bomb without being able to go through any walls. 
Also, replace the bombs with 0 and walls with -1 in the resultant matrix. 
If no path exists between a bomb and an open space replace the corresponding 'O' with -1.



    ***********************************************************
*/


// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

    public:
    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int M, int N) 
    { 
        vector<vector<int>> ans(M,vector<int>(N,INT_MAX));
        queue<pair<int,int>> q;
        for(int i = 0; i < ans.size(); i++){
            for(int j = 0; j < ans[0].size(); j++){
                if(matrix[i][j] == 'W') ans[i][j] = -1;
                else if(matrix[i][j] == 'B') {
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }   
        }
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            if(x.first >= M || x.second >= N || x.first < 0 || x.second < 0) continue;
            // // if(ans[x.first][x.second] != INT_MAX) continue;
            if(x.first > 0 && ans[x.first-1][x.second] == INT_MAX){
                q.push({x.first-1,x.second});
                ans[x.first-1][x.second] = min(ans[x.first][x.second]+1,ans[x.first-1][x.second]);
            }
            if(x.first < M-1  && ans[x.first+1][x.second] == INT_MAX){
                q.push({x.first+1,x.second});
                ans[x.first+1][x.second] = min(ans[x.first][x.second]+1,ans[x.first+1][x.second]);
            }
            if(x.second > 0 && ans[x.first][x.second-1] == INT_MAX){
                q.push({x.first,x.second-1});
                ans[x.first][x.second-1] = min(ans[x.first][x.second]+1,ans[x.first][x.second-1]);
            }
            if(x.second < N-1 && ans[x.first][x.second+1] == INT_MAX){
                q.push({x.first,x.second+1});
                ans[x.first][x.second+1] = min(ans[x.first][x.second]+1,ans[x.first][x.second+1]);
            }
        }
        for(int i = 0; i < ans.size(); i++){
            for(int j = 0; j < ans[0].size(); j++){
                if(ans[i][j] == INT_MAX) ans[i][j] = -1;
            }   
        }
        return ans;
    } 
};

// { Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
        int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}  // } Driver Code Ends