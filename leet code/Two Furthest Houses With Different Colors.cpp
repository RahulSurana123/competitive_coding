

/* 
    Solution by Rahul Surana
    
    ***********************************************************

There are n houses evenly lined up on the street, and each house is beautifully painted. You are given a 0-indexed integer array colors of length n, where colors[i] represents the color of the ith house.

Return the maximum distance between two houses with different colors.

The distance between the ith and jth houses is abs(i - j), where abs(x) is the absolute value of x.


    ***********************************************************
*/

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0;
        for(int i = 0; i < colors.size();i++){
            for(int j = colors.size()-1; j > i;j--){
                if(colors[j] != colors[i]) { ans = max(ans,j-i); break;}
            }   
        }
        return ans;
    }
};
