

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given an array people where people[i] is the weight of the ith person, 
and an infinite number of boats where each boat can carry a maximum weight of limit. 
Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0,i=0,j =people.size()-1;
        sort(people.begin(),people.end());
        while(i <= j){
            ans++;
            if(people[i]+people[j] <= limit){
                i++;
            }
            j--;        
        }
        return ans;
    }
};