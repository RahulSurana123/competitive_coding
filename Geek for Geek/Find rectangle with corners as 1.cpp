

/* 

    Solution by Rahul Surana
    
    ***********************************************************

Given a NxM binary matrix consisting of 0s and 1s. 
Find if there exists a rectangle/ square within the matrix whose all four corners are 1. 



    ***********************************************************
*/


// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
#include <unordered_map>
#include <unordered_set>
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool ValidCorner(const vector<vector<int> >& matrix)
    {
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
               if(matrix[i][j]){
                   for(int k = i+1; k < matrix.size(); k++){
                       for(int l = j+1; l < matrix[0].size(); l++){
                        //   cout<< matrix[i][j] <<" "<< matrix[i][l] << " "<< matrix[k][j]<<" "<< matrix[k][l] <<"\n";
                           if(matrix[i][l] && matrix[k][j] && matrix[k][l]){
                               return true;
                           }
                        //   cout<< i <<" "<< j << " "<< k <<" "<< l <<"\n";
                       }
                   }
               }
            }      
        }
        return false;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int row, col;
        cin>> row>> col;

        vector<vector<int> > matrix(row);
            
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        Solution ob;
        if (ob.ValidCorner(matrix)) 
            cout << "Yes\n"; 
        else
            cout << "No\n"; 
    }

    return 0;
} 


  // } Driver Code Ends