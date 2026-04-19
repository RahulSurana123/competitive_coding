

/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are given an integer n.

Define its mirror distance as: abs(n - reverse(n))​​​​​​​ where reverse(n) is the integer formed by reversing the digits of n.

Return an integer denoting the mirror distance of n​​​​​​​.

abs(x) denotes the absolute value of x.


    ***********************************************************
*/

class Solution {
public:
    int mirrorDistance(int n) {
        string a = to_string(n);
        reverse(a.begin(),a.end());
        return abs(n-stoi(a));
    }
};
