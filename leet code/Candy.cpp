

/* 

    Solution by Rahul Surana
    
    ***********************************************************


There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.


    ***********************************************************
    
*/


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), ind = 0, mv = 1e9;
        vector<int> p(n,1);
        for(int i = 1; i < n; i++) { if(ratings[i] > ratings[i-1]) p[i] = p[i-1] + 1; }
        for(int i = n-2; i >= 0; i--) if(ratings[i] > ratings[i+1]) if(p[i] < p[i+1]+1) p[i] = p[i+1] + 1;
        return accumulate(p.begin(),p.end(),0);
    }
};