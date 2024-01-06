

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Hercy wants to save money for his first car. He puts money in the Leetcode bank every day.

He starts by putting in $1 on Monday, the first day. 
Every day from Tuesday to Sunday, he will put in $1 more than the day before. On every subsequent Monday, 
he will put in $1 more than the previous Monday.
Given n, return the total amount of money he will have in the Leetcode bank at the end of the nth day.


    ***********************************************************
*/

    
class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int s = 28;
        int x = n/7, y = n%7;
        for(int i = 0; i < x; i++) {ans += s; s+=7;}
        for(int i = 0; i < y; i++) ans+=++x;
        return ans;    
    }
};