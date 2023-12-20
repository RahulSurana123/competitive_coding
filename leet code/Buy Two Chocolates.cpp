

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an integer array prices representing the prices of various chocolates in a store. 
You are also given a single integer money, which represents your initial amount of money.

You must buy exactly two chocolates in such a way that you still have some non-negative leftover money. 
You would like to minimize the sum of the prices of the two chocolates you buy.

Return the amount of money you will have leftover after buying the two chocolates. 
If there is no way for you to buy two chocolates without ending up in debt, return money. 
Note that the leftover must be non-negative.


    ***********************************************************
*/

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int a = 10000, b = 10000, n = prices.size();
        for(int i = 0; i < n; i++){
            if(prices[i] < a){
                b = a;
                a = prices[i];
            }
            else{
                b = min(b,prices[i]);
            }
        }
        return money < a+b ? money : money-a-b;
    }
};