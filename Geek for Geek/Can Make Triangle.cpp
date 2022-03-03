

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array A[] of N elements, You'd like to know how many triangles can be formed with side 
lengths equal to adjacent elements from A[].

Construct an array of integers of length N - 2 where ith element is equal to 1 
if it is possible to form a triangle with side lengths A[i], A[i+1], and A[i+2]. otherwise 0.

Note: A triangle can be formed with side lengths a, b and c if a+b>c and a+c>b and b+c>a.



    ***********************************************************
*/


// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<int> canMakeTriangle(vector<int> A, int N){
        vector<int> ans;
        for(int i = 2; i < N; i++){
            if(A[i]+A[i-1] > A[i-2] && A[i-2]+A[i-1] > A[i] && A[i]+A[i-2] > A[i-1]) ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
}; 

// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++)
            cin>>A[i];
        Solution ob;
        auto ans = ob.canMakeTriangle(A, N);
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;
        
    }

    return 0; 
}   // } Driver Code Ends