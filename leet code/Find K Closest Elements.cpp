

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. 
The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 



    ***********************************************************
*/


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        sort(arr.begin(),arr.end(),[&](auto a, auto b){ 
            if(abs(x-a)==abs(x-b)){ 
                return a<b; 
            } 
            return abs(x-a)<abs(x-b);
        });
        
        vector<int> ans(arr.begin(),arr.begin()+k);
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};