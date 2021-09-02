


/* 

    Solution by Rahul Surana

    ***********************************************************



Given an array arr[] of size, N. Find the subarray with maximum XOR. \
A subarray is a contiguous part of the array.



    ***********************************************************
*/


// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++



class Solution{   
public:
    struct TrieNode 
    { 
        int value;  // Only used in leaf nodes 
        TrieNode *arr[2]; 
    };
    void insert(TrieNode *root, int pre_xor) 
    { 
        TrieNode *temp = root; 
  
    
        for (int i=32-1; i>=0; i--) 
        { 
        // Find current bit in given prefix 
            bool val = pre_xor & (1<<i); 
            if (temp->arr[val] == NULL) 
                temp->arr[val] = new TrieNode(); 
  
            temp = temp->arr[val]; 
        } 
  
        temp->value = pre_xor; 
    } 
  
    int query(TrieNode *root, int pre_xor) 
    { 
        TrieNode *temp = root; 
        for (int i=32-1; i>=0; i--) 
        { 
            bool val = pre_xor & (1<<i); 
            if (temp->arr[1-val]!=NULL) 
                temp = temp->arr[1-val]; 
  
            else if (temp->arr[val] != NULL) 
                temp = temp->arr[val]; 
        } 
        return pre_xor^(temp->value); 
    } 
    int maxSubarrayXOR(int N, int arr[]){    
        TrieNode *root = new TrieNode(); 
        insert(root, 0); 
        int result = INT_MIN, pre_xor =0; 
        for (int i=0; i<N; i++) 
        { 
            pre_xor = pre_xor^arr[i]; 
            insert(root, pre_xor); 
  
            result = max(result, query(root, pre_xor)); 
        } 
        return result; 
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.maxSubarrayXOR(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends