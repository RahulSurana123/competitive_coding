

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given a graph with n vertices, e edges and an array arr[] denoting the edges connected to each other, 
check whether it is Biconnected or not.
Note: The given graph is Undirected.



    ***********************************************************
*/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int biGraph(int arr[], int n, int e) {
        if(e<n-1) return 0;
        if(n==2 && e==1) return 1;
        vector<vector<int>> adj(n+1);
        for(int i = 0; i < 2*e; i+=2){
            adj[arr[i]].push_back(arr[i+1]);
            adj[arr[i+1]].push_back(arr[i]);
        }
        for(int i = 0 ; i < n; i++){
            if(adj[i].size()==1) return 0;
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
        
        int arr[2*e];
        for(int i=0; i<2*e; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.biGraph(arr,n,e) << endl;
    }
    return 0;
}  // } Driver Code Ends