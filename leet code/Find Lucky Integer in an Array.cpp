

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

Return the largest lucky integer in the array. If there is no lucky integer return -1.



    ***********************************************************
*/

    
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int f[501] = {0};
        for(auto &a :arr){
            f[a]++;
        }
        for(int i = 500; i >= 1; i--) if(i == f[i]) return i;
        return -1;
    }
};
