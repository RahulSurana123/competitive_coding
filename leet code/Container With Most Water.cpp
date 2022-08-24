

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given an integer array height of length n. 
There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, i = 0, j = height.size()-1;
        while(i < j){
            ans = max(ans,min(height[i],height[j])*(j-i));
            
            if(height[i] < height[j]) i++;
            else if(height[i] > height[j]) j--;
            else {
                j--;
                i++;
            }
        }
        return ans;
    }
};