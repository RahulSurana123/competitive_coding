

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a binary matrix of dimensions N * M. One can perform the given operation in the matrix.

If the value of matrix[i][j] is 0, then traverse in the same direction and check the next value.
If the value of matrix[i][j] is 1, then update matrix[i][j] to 0 and change the current direction 
from up, right, down, or left to the directions right, down, left, and up respectively.
Initially you start from cell(0, 0), moving in right direction.

The task is to find the indices of the matrix  which leads to outside the matrix from 
the traversal of the given matrix from the cell (0, 0) by performing the operations.



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
    pair<int,int> endPoints(vector<vector<int>> &matrix){
        int i = 0,j = 0, x = 0,y=1;
        while(((i >= 0 && i < matrix.size()) && (j >= 0 && j < matrix[0].size()))){
            if(matrix[i][j] == 0){
                i = x + i;
                j = y + j;
            }
            else{
                matrix[i][j] = 0;
                if(x == 0 && y == 1){
                    x = 1;
                    y = 0;
                }
                else if(x == 1 && y == 0){
                    x = 0;
                    y = -1;
                }
                else if(x == 0 && y == -1){
                    x = -1;
                    y = 0;
                }
                else if(x == -1 && y == 0){
                    x = 0;
                    y = 1;
                }
            }
            // cout << i << " "<< j <<"\n";
        }
        return {i-x,j-y};
    }

};

// { Driver Code Starts.


int main()
{
    int tc;
    scanf("%d", &tc);
    while(tc--){
        int row, col;
        scanf("%d", &row);
        scanf("%d", &col);
        vector<vector<int>> matrix(row , vector<int> (col));
     
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                cin>>matrix[i][j];
            }
        }
        Solution obj;
        pair<int,int> p = obj.endPoints(matrix);
        
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
    return 0;
}  // } Driver Code Ends