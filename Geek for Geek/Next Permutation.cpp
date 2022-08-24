

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Implement the next permutation, which rearranges the list of numbers into Lexicographically next greater permutation of list of numbers. 
If such arrangement is not possible, it must be rearranged to the lowest possible order i.e. sorted in an ascending order. 
You are given an list of numbers arr[ ] of size N.



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
    vector<int> nextPermutation(int N, vector<int> arr){
        int i = N-2;
        while(i>=0 && arr[i+1] < arr[i]) i--;
        if(i == -1) {
            sort(arr.begin(),arr.end());
            return arr;
        }
        int j = N-1;
        while(j>=0 && arr[j] < arr[i]) j--;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        sort(arr.begin()+i+1,arr.end());
        return arr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends