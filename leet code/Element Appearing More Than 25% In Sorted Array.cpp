

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer array sorted in non-decreasing order, 
there is exactly one integer in the array that occurs more than 25% of the time, 
return that integer.


    ***********************************************************
*/

    
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int x = arr.size(), n = arr.size()/4;
        for(int i = n; i< x;i++){
            if(arr[i] == arr[i-n]) return arr[i];
        }
        return -1;
    }
};