


/* 

    Solution by Rahul Surana

    ***********************************************************


Given a A X B matrix with your initial position at the top-left cell, find the number of possible unique paths 
to reach the bottom-right cell of the matrix from the initial position.

Note: Possible moves can be either down or right at any point in time, i.e., we can move to matrix[i+1][j] or matrix[i][j+1] 
from matrix[i][j].



    ***********************************************************
*/




// { Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    int ar[16][16];
    
    int re(int i, int j){
        if(ar[i][j] != -1) return ar[i][j];
        if(i == 0 || j == 0) return 0;
        if(i == 1 || j == 1) return 1;
        ar[i][j] = re(i-1,j) + re(i,j-1);
        return ar[i][j];
    }
    
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        for(int i = 0; i < 16; i++){
         for(int j = 0; j < 16; j++){
            ar[i][j]= -1;
        }   
        }
        int ans = re(a,b);
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}

  // } Driver Code Ends