

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given two n-ary trees. Check if they are mirror images of each other or not. 
You are also given e denoting the number of edges in both trees, and two arrays, A[] and B[]. 
Each array has 2*e space separated values u,v denoting an edge from u to v for the both trees.



    ***********************************************************
*/


// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        map<int,vector<int>>a;
        map<int,vector<int>>b;
        for(int i=0;i<2*e;i+=2)  a[A[i]].push_back(A[i+1]),b[B[i]].push_back(B[i+1]);
        for(auto &x:a){
            reverse(x.second.begin(),x.second.end());
            if(b[x.first]!=x.second) return 0;
        }
        return 1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends