

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a string S consisting of the characters 0, 1 and 2. 
Your task is to find the length of the smallest substring of string S that contains all the three characters 0, 1 and 2. 
If no such substring exists, then return -1.



    ***********************************************************
*/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        vector<int> f(3,0);
        int i=0,j=0,ans = 1e9;
        while(i<S.length()&&j<S.length()){
            if(f[0]&&f[1]&&f[2]){
                f[S[i]-'0']--;
                ans = min(ans,j-i);
                i++;
            }
            else{
                f[S[j++]-'0']++;
            }
        }
        while(i<S.length() && f[0]&&f[1]&&f[2]){
            f[S[i]-'0']--;
            ans = min(ans,j-i);
            i++;
        }
        return ans == 1e9 ? -1 : ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}  // } Driver Code Ends