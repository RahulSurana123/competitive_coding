

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given a parent array arr[] of a binary tree of N nodes. 
Element at index i in the array arr[] represents the parent of ith node, i.e, arr[i] = parent(i). 
Find the height of this binary tree.
Note: There will be a node in the array arr[], where arr[i] = -1, which means this node is the root of binary tree.



    ***********************************************************
*/


// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findHeight(int N, int arr[]){
        vector<int> h(N,1);
        int ans = 1;
        for(int i = 0; i<N;i++){
            if(h[i] != 1)  ans = max(h[i],ans);
            else{
                int x = i;
                // int c = 0;
                while(arr[x]!=-1){
                    h[x] = h[arr[x]]+1;
                    x = arr[x];
                    // cout << x<<" ";
                }
                ans = max(h[i],ans);
            }
            // cout << "\n";
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.findHeight(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends