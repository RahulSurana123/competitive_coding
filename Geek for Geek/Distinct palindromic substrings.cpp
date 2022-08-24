

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a string str of lowercase ASCII characters, 
Count the number of distinct continuous palindromic sub-strings which are present in the string str.



    ***********************************************************
*/



// { Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int palindromeSubStrs(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        set<string> set;
        for(int g = 0; g < n; g++){
            for(int i = 0, j = g; i < n-g; i++,j++){
                if(s[i] == s[j]){
                    if(i==j) dp[i][j] = 1;
                    else if(g==1) dp[i][j]= dp[i][j-1];
                    else dp[i][j] = dp[i+1][j-1];
                }
                if(dp[i][j]) set.insert(s.substr(i,j-i+1));
            }
        }
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << dp[i][j] <<" ";
        //     } 
        //     cout << "\n";
        // }
        return set.size();
    }
};

// { Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}
  // } Driver Code Ends