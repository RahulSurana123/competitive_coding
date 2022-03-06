

/* 

    Solution by Rahul Surana
    
    ***********************************************************


For a given 2D Matrix before, the corresponding cell (x, y) of the after matrix is calculated as follows: 

res = 0;
for(i = 0; i <= x; i++){
    for( j = 0; j <= y; j++){              
        res += before(i,j);
    }
}
after(x,y) = res;
Given an N*M 2D-Matrix after, your task is to find the corresponding before matrix for the given matrix.



    ***********************************************************
*/


// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<vector<int>> computeBeforeMatrix(int N, int M, vector<vector<int>> after){
        vector<vector<int>> b(N,vector<int>(M,0));
        b[0][0] = after[0][0];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(i != 0 || j != 0){
                    int z = after[i][j];
                    if(i != 0) z -= after[i-1][j];
                    if(j != 0) z -= after[i][j-1];
                    if(j != 0 && i != 0) z+= after[i-1][j-1];
                    b[i][j] = z;
                }
            }   
        }
        return b;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M; 
        vector<vector<int>> after(N,vector<int>(M));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>after[i][j];
            }
        } 
        Solution obj;
        vector<vector<int>> before=obj.computeBeforeMatrix(N,M,after); 
        for(int i=0;i<before.size();i++){
            for(int j=0;j<before[i].size();j++){
                cout<<before[i][j]<<' ';
            } 
            cout<<endl;
        }
    }
}  // } Driver Code Ends