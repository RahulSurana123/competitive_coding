

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given an array A[ ] of N integers and an integer X. In one operation, 
you can change the ith element of the array to any integer value where 1 ≤ i ≤ N. 
Calculate minimum number of such operations required such that the bitwise AND of 
all the elements of the array is strictly greater than X.



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
    int count(int N, vector<int> A,int X)
    {
        int ans = 1e9;
        int bits = 0;
        for(int i = 30; i >= 0; i--){
            if(((1<<i)&X)){
                bits = bits | (1<<i);
            }
            else{
                int z = 0;
                int temp = bits | (1<<i); 
                for(int j = 0; j < N;j++){
                    if((temp&A[j]) != temp){
                      z++;  
                    }
                }
                ans = min(ans,z);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> A(N);
        for(auto &i:A)
            cin>>i;
        Solution obj;
        int ans = obj.count(N, A, X);
        cout<<ans<<endl;
    }
}  // } Driver Code Ends