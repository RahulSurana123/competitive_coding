

/* 
    Solution by Rahul Surana
    
    ***********************************************************


A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. 
time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

 


    ***********************************************************
*/



#include<bits/stdc++.h>

class Solution {
public:

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int ans = 0, cs = 0;
        for(int i = satisfaction.size()-1; i>=0; i--){
            ans = max(ans,ans+cs+satisfaction[i]);
            cs+=satisfaction[i];
        }
        return ans;
    }
};