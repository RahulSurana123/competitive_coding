



/* 
    Solution by Rahul Surana
    
    ***********************************************************


Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).

 

    ***********************************************************
*/



class Solution {
public:
    double myPow(double x, int n) {
        bool neg = (n < 0);
        n = abs(n);
        double ans = 1;
        while(n > 0){
            if(n&1) ans*=x;
            x*=x;
            n = n>>1;
        }
        return neg? (1/ans) : ans;
    }
};