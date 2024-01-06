

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Alice has n balloons arranged on a rope. 
You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. 
She does not want two consecutive balloons to be of the same color, so she asks Bob for help. 
Bob can remove some balloons from the rope to make it colorful. 
You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) 
that Bob needs to remove the ith balloon from the rope.

Return the minimum time Bob needs to make the rope colorful.


    ***********************************************************
*/

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int p = 0, c = 1, ans  = 0, n  = neededTime.size();
        while(c < n){
            if(colors[p] == colors[c]){
                if(neededTime[p] > neededTime[c]) ans += neededTime[c];
                else {
                    ans += neededTime[p]; 
                    p = c;
                }
            }
            else {
                p = c;
            }
            c++;
        }
        return ans;
    }
};