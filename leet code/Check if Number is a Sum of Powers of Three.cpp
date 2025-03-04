
/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.

An integer y is a power of three if there exists an integer x such that y == 3x.



    ***********************************************************
*/

class Solution {
public:
    bool checkPowersOfThree(int n) {
        int x = ceil(log2(n)/log2(3));
        while(x>-1){
            if(n >= pow(3,x)) n-=pow(3,x);
            x--;
        }
        return n==0;
    }
};
