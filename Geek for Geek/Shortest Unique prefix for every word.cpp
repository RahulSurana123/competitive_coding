

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array of words, find all shortest unique prefixes to represent each word in the given array. 
Assume that no word is prefix of another.



    ***********************************************************
*/


// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Node{
public:
    Node* arr[26];
    int cnt;
    Node(){
        for(int i = 0; i < 26; i++){
            arr[i] = NULL;
        }
        cnt = 0;
    }
};

class Solution
{
    public:
    void insert_string(Node* root, string s){
        for(int i = 0; i < s.length(); i++){
            if(root -> arr[s[i] - 'a'] == NULL){
                root -> arr[s[i] - 'a'] = new Node();
            }
            root = root -> arr[s[i] - 'a'];
            (root -> cnt)++;
        }
    }
    
    vector<string> findPrefixes(string arr[], int n)
    {
        Node* root = new Node();
        for(int i = 0; i < n; i++){
            insert_string(root, arr[i]);
        }
        vector<string>ans;
        for(int i = 0; i < n; i++){
            string s = arr[i];
            Node* node = root;
            for(int j = 0; j < s.length(); j++){
                node = node -> arr[s[j] - 'a'];
                if(node -> cnt == 1){
                    ans.push_back(s.substr(0, j + 1));
                    break;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}
  // } Driver Code Ends