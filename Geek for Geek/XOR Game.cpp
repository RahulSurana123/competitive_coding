

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a positive number k, we need to find a minimum value of positive integer n, 
such that XOR of n and n+1 is equal to k. If no such n exist then print -1.


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
    int xorCal(int k){
        if(k==1) return 2;
        if(ceil(log2(k+1)) == floor(log2(k+1))) return k/2;
        return -1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        
        Solution ob;
        cout<<ob.xorCal(k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends