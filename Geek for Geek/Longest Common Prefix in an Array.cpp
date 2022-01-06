

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a array of N strings, find the longest common prefix among all strings present in the array.


    ***********************************************************
*/


// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        string ans;
        int x = INT_MAX;
        for(int i = 0; i < N; i++){
            if(x > arr[i].length())
            x = arr[i].length();
        }
        bool f = true;
        for(int i = 0; i < x; i++){
            char z = arr[0][i];
            for(int j = 1; j < N; j++) if(z != arr[j][i]) { f = false; break; }
            if(f)
            ans += z;
            else break;
        }
        if(ans.length() == 0) return "-1";
        else return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends