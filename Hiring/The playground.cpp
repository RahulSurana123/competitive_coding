
/*


    
    Solution by Rahul Surana
    

    ************************************************************************



You are playing in a playground in form of a 2D matrix of size N x M.

Initially, the playground contains just an outer boundary. 
There are some walls given in an array A of size Q. You construct these walls in the playground.

Task

Determine how many different regions the playground gets divided into.

Notes 

The walls will be given as input x1, y1, x2, y2. 
where (x1, y1) and (x2, y2) are adjacent cells of the matrix and the wall needs to be constructed on the side common to both these adjacent cells. Formally,

    If x1 = x2, then | y1-y2 | = 1, and this will account for a left wall or right wall.

    If y1 = y2, then | x1-x2 | = 1, and this will account for a top wall or bottom wall.

The boundary walls are assumed to be connected initially, they are not given in input. 
Thus, a matrix of size NxM has a total of 1 region initially (without any walls built).

A region is connected to another region if there is any path between the two without any walls.




    **************************************************************************



*/





#include<bits/stdc++.h>
using namespace std;

void dfs(int i,int j, int &N,int &M,vector<vector<set<pair<int,int>>>> &adj, vector<vector<bool>> &v){
    if(i<0 || j<0 || i>=N || j>=M || v[i][j]) return;
    v[i][j] = true;
    if(!adj[i][j].count({i+1,j})){
        dfs(i+1,j,N,M,adj,v);
    }
    if(!adj[i][j].count({i,j+1})){
        dfs(i,j+1,N,M,adj,v);
    }
    if(!adj[i][j].count({i-1,j})){
        dfs(i-1,j,N,M,adj,v);
    }
    if(!adj[i][j].count({i,j-1})){
        dfs(i,j-1,N,M,adj,v);
    }
}

int playground (int N, int M, int Q, vector<vector<int> > A) {
   vector<vector<bool>> v(N+1,vector<bool>(M+1,false));
   vector<vector<set<pair<int,int>>>> adj(N+1,vector<set<pair<int,int>>>(M+1,set<pair<int,int>>()));
   for(int i = 0; i < A.size(); i++){
       int x1 = A[i][0]-1, x2 = A[i][2]-1;
       int y1 = A[i][1]-1, y2 = A[i][3]-1;
       adj[x1][y1].insert({x2,y2});
       adj[x2][y2].insert({x1,y1});
   }
   int ans = 0;
   for(int i = 0; i < N; i++){
       for(int j = 0; j < M; j++){
           if(!v[i][j]){
                dfs(i,j,N,M,adj,v);
                ans++;
           }
       }
   }
   return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        int M;
        cin >> M;
        int Q;
        cin >> Q;
        vector<vector<int> > A(Q, vector<int>(4));
        for (int i_A = 0; i_A < Q; i_A++)
        {
            for(int j_A = 0; j_A < 4; j_A++)
            {
                cin >> A[i_A][j_A];
            }
        }

        int out_;
        out_ = playground(N, M, Q, A);
        cout << out_;
        cout << "\n";
    }
}