

/* 

    Solution by Rahul Surana
    
    ***********************************************************

You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, 
but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


    ***********************************************************
*/


class Solution {
public:

    vector<vector<int>> dp;

    int df(int i, vector<int>& prices, int &fee, bool b){
        if(i>= prices.size()) return 0;
        // cout << i <<" "<<b<<"\n"; 
        if(dp[b][i] != -1) return dp[b][i];
        if(b){
            return dp[b][i] = max(df(i+1,prices,fee,b), df(i+1,prices,fee, b^1) + prices[i]-fee);
        }
        else{
            return dp[b][i] = max(df(i+1,prices,fee,b), df(i+1,prices,fee, b^1) - prices[i]);
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        dp.resize(2,vector<int>(prices.size(),-1));
        return df(0,prices,fee, false);
    }
};