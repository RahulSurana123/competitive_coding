

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given two integers M and N, generate all primes between M and N.


    ***********************************************************
*/


// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> primeRange(int M, int N) {
        vector<int> ans;
        for(int i = max(M,2); i <= N; i++){
            bool f = false;
            for(int j = 2 ; j <= sqrt(i); j++){
                if(i%j == 0){
                    f= true; 
                    break;
                }
            }
            if(!f) ans.push_back(i);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}  // } Driver Code Ends