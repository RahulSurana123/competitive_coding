/* 
   
   Solution by Rahul Surana
    
    ***********************************************************

  Given an integer n, return true if it is a power of four. Otherwise, return false.

  An integer n is a power of four, if there exists an integer x such that n == 4x.

   
   ***********************************************************

*/

class Solution {
  
public:
  
  bool isPowerOfFour(int n) {
  
    return (n>0)&&((n&(n-1))==0) && ((int)ceil(log2(n))%2 == 0);
  }
  
};
