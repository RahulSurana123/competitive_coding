



/* 
    Solution by Rahul Surana
    
    ***********************************************************

Given an integer array arr, return the length of a maximum size turbulent subarray of arr.

A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:

=>  For i <= k < j:
       arr[k] > arr[k + 1] when k is odd, and
       arr[k] < arr[k + 1] when k is even.
=>  Or, for i <= k < j:
       arr[k] > arr[k + 1] when k is even, and
       arr[k] < arr[k + 1] when k is odd.



    ***********************************************************
*/


class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() == 2 && arr[0] == arr[1]) return 1;
        if(arr.size() < 3) return arr.size();
        int ans = 2;
        int ma = 0;
        bool f = false;
        if(arr[0]>arr[1]) f = true;
        
        for(int i = 2; i < arr.size(); i++){
            if(f && arr[i-1] < arr[i]) ans++;
            else if(!f && arr[i-1]>arr[i]) ans++;
            else if(arr[i-1] == arr[i]) { 
                ans =1; 
                if(i<arr.size()-1) f = arr[i] > arr[i+1];
            } 
            else {
                ans = 2;
                if(f) f = false;
                else f = true;
            }
            if(f) f = false;
            else f = true;
            // cout << ans << " ";
            if(ans > ma) ma = ans;
        }
        return ma;
    }
};