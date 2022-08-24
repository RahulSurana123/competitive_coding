


/*

Solution by Rahul Surana

    ***********************************************************


Given an array of strings arr[] of size N, 
find if there exists 2 strings arr[i] and arr[j] such that arr[i]+arr[j] is a palindrome 
i.e the concatenation of string arr[i] and arr[j] results into a palindrome.


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
    
    // map<char, >
    
    // struct Trie{
    //     public:
    //         char x;
    //         vector<Trie*> n;
    //         Trie(char x): x(x){
                
    //         }
    // }
    
    bool isPalindrome(string s){
        for(int i = 0; i < s.length()/2; i++){
            if(s[i] != s[s.length()-1-i]) return false;
        }
        return true;
    }
    
    
    bool palindromepair(int N, string arr[]) {
        map<char,vector<int>> m;
        for(int i = 0; i < N; i++){
            m[arr[i].back()].push_back(i);
        }
        for(int i = 0; i < N; i++){
            for(auto z: m[arr[i][0]]){
                if(z == i) continue;
                if(isPalindrome(arr[i]+arr[z])){
                    return true;
                }
            }
        }
        return false;
    }

};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        string arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.palindromepair(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends