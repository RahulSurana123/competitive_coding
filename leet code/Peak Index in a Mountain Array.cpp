

/* 

    Solution by Rahul Surana
    
    ***********************************************************

An array arr a mountain if the following properties hold:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array arr, return the index i such that 
arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

You must solve it in O(log(arr.length)) time complexity.

    ***********************************************************
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s = 0, e = arr.size()-1;
        while(s<e){
            int m = (e + s)>>1;
            // cout << m << "\n";
            if(m <= 0) m = 1;
            if(arr[m] > arr[m-1] && arr[m+1] < arr[m]){
                return m;
            }
            else if(arr[m] < arr[m+1]){
                s = m+1;
            }
            else{
                e = m-1;
            }
        }
        return s;
    }
};