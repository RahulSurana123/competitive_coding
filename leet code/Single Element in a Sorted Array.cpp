

/* 

    Solution by Rahul Surana
    

    ***********************************************************


You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

        

    ***********************************************************
*/



#include <bits/stdc++.h>
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0,e = nums.size()-1;
        while(s<=e){
            int m = s+ (e - s) / 2;
            cout << m <<" "<<nums[m]<< "\n";
            if(m>0 && nums[m] == nums[m-1]){
                if(m%2 == 0) e = m-2;
                else{
                    s = m+1;
                }
            }
            else if(m<nums.size()-1 && nums[m] == nums[m+1]){
                if(m%2==0){
                    s = m+2;
                }
                else{
                    e = m-1;
                }
            }
            else{
                return nums[m];
            }
        }
        return nums[s];
    }
};