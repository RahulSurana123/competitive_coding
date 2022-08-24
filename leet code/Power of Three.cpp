/* 
   
   Solution by Rahul Surana
    
    ***********************************************************
 
  Given an integer n, return true if it is a power of three. Otherwise, return false.

  An integer n is a power of three, if there exists an integer x such that n == 3^x.
   
   ***********************************************************
   
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        double x = log10(n)/log10(3);
        return (int)(x) == (x);
    }
};
