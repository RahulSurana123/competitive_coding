

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a binary array A[] of size N. The task is to arrange the array in increasing order.
Note: The binary array contains only 0  and 1.


    ***********************************************************
*/


// { Driver Code Starts
// A Sample C++ program for beginners with Competitive Programming

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    
    // A[]: input array
    // N: input array
    //Function to sort the binary array.
    void binSort(int A[], int N)
    {
        int i = 0,j=0;
        while(j<N){
            while(j < N && A[j] == 1) j++;
            while(i<j && A[i] == 0) i++;
            if(j<N) {
                A[j]=1;
                A[i]=0;
            }
            j++;
            // cout << A[i] << " " << A[j] <<"\n";
        }
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin>>T;
    // Input the number of testcases
    while(T--)
    {
        int N;
        cin>>N; //Input size of array N
        int A[N]; 
        
        for(int i = 0; i  < N; i++)
          cin>>A[i];
          
        Solution obj;
        obj.binSort(A,N);
        
        for(int x:A)
        cout<<x<<" ";
          
        cout<<endl;
    }
    return 0;
}



  // } Driver Code Ends