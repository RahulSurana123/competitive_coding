

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a sorted array keys[0.. n-1] of search keys and an array freq[0.. n-1] of frequency counts, 
where freq[i] is the number of searches to keys[i]. Construct a binary search tree of 
all keys such that the total cost of all the searches is as small as possible.

Let us first define the cost of a BST. The cost of a BST node is level of that node multiplied by its frequency. 
Level of root is 1.



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
    
    int dp[101][101][101];
    
    int df(int k[],int f[],int s, int e, int l){
        if(s>e) return 0;
        if(dp[s][e][l] != -1) return dp[s][e][l];
        int t = 1e9;
        for(int i = s ; i <= e; i++){
            t = min(t,l*f[i] + df(k,f,i+1,e,l+1) + df(k,f,s,i-1,l+1));
        }
        return dp[s][e][l] = t;
    }
    
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        memset(dp,-1,sizeof(dp));
        return df(keys,freq,0,n-1,1);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends