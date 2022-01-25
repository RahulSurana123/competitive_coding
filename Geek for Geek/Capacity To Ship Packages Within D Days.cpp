

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given an array arr[] of N weights. 
Find the least weight capacity of a boat to ship all weights within D days.
The ith weight has a weight of arr[i]. Each day, we load the boat with weights given by arr[i].
We may not load more weight than the maximum weight capacity of the ship.


    ***********************************************************
*/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int leastWeightCapacity(int arr[], int N, int D) {
        int s = 0,ma=0;
        for(int i = 0; i < N; i++){
            s += arr[i];
            ma = max(arr[i],ma);
        }
        int l = 0 , r = 500000001;
        int ans = 0;
        while(l<=r){
            int m = l+((r-l)/2);
            int z = 0,a = 1;
            for(int i = 0; i < N; i++){
                z+=arr[i];
                if(z > m) {a++;
                z = arr[i];}
            }
            if(a<=D) { r = m-1; ans = m; }
            else { l = m+1; }
            
        }
        // for(int i = 0; i < N; i++){
        //     if(arr[i] < x && i < N-1){
        //         ans = max(ans,arr[i] + arr[i+1]);
        //         i++;
        //     }
        // }
        // cout << ans <<" ";
        return (ans<ma)? ma: ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}  // } Driver Code Ends