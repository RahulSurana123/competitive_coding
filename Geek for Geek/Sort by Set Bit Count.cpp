

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array of integers, sort the array (in descending order) according to count of 
set bits in binary representation of array elements. 

Note: For integers having same number of set bits in their binary representation, 
sort according to their position in the original array i.e., a stable sort.


    ***********************************************************
*/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    
    int df(int arr){
        int ans = 0;
        for(int j = 31; j>= 0; j--){
            if(arr & 1<<j) ans++;
        }
        return ans;
    }
    
    void sortBySetBitCount(int arr[], int n)
    {
        map<int, vector<int>, greater<int>> m;
        
        vector<int> b(n,0);
        for(int i = 0 ; i < n; i++){
            int x = df(arr[i]);
            m[x].push_back(arr[i]);
        }
        int j = 0;
        for(auto i = m.begin(); i != m.end(); i++){
            for(auto z: i->second){
                arr[j++] = z;
            }
        }
        // sort(arr,arr+n, [&](int &a, int &c){ bool f = b[a]>b[c]; swap(b[a],b[c]); return f; } );
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends