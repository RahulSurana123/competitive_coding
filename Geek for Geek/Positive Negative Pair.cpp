

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array of distinct integers, find all the pairs having both negative and positive values of a number in the array.



    ***********************************************************
*/


#include <bits/stdc++.h>


// { Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
#include <unordered_map>
#include <math.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
  public:
    //Function to return list containing all the pairs having both
    //negative and positive values of a number in the array.
    vector <int> findPairs(int arr[], int n) 
    {
        set<int> s;
        vector<int> ans;
        // for(int i = 0 ;i < n; i++) 
        for(int i = 0 ;i < n; i++) { 
            if(s.count(-arr[i])){ 
                // cout << -arr[i] <<"\n";
                if(arr[i] > 0) {
                    ans.push_back(-arr[i]); 
                    ans.push_back(arr[i]);
                }
                else {
                    ans.push_back(arr[i]); 
                    ans.push_back(-arr[i]);
                }
            } 
            s.insert(arr[i]);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        vector <int> res = obj.findPairs(arr, n);
        if(res.size()!=0)
        {
            for (int i : res) 
                cout << i << " ";
            cout << endl;   
        }
        else
            cout<<0<<endl;
    }

    return 0;
}  // } Driver Code Ends