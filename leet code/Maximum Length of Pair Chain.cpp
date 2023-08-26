

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

Return the length longest chain which can be formed.

You do not need to use up all the given intervals. You can select pairs in any order.
    

    ***********************************************************
*/


class Solution {
public:
    vector<int> dp;
    int df(int i,vector<vector<int>>& pairs, int a){
        if(i > pairs.size()-1) return 0;
        if(dp[i] != -1) return dp[i];
        // cout << pairs[i][0] <<" "<<pairs[i][1]<<" "<<a<<"\n";
        if(pairs[i][0] > a)
        return dp[i] = max( 1 + df(i+1,pairs,pairs[i][1]), df(i+1,pairs,a));
        return dp[i] = df(i+1,pairs,a); 
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        dp.resize(pairs.size()+1,-1);
        sort(pairs.begin(),pairs.end(),[&](auto a,auto b){ return a[1] < b[1]; });
        return df(0,pairs,-1001);
    }
};