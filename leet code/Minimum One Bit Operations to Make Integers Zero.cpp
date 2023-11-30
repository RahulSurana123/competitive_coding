

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer n, you must transform it into 0 using the following operations any number of times:

Change the rightmost (0th) bit in the binary representation of n.
Change the ith bit in the binary representation of n if the (i-1)th bit is set to 1 and 
the (i-2)th through 0th bits are set to 0.
Return the minimum number of operations to transform n into 0.


    ***********************************************************
*/

    
class Solution {
public:
    int minimumOneBitOperations(int n) {
        // 0 1 3 2 7 6 4 5 15 14 12 13 8 9 11 10 31
        if(n <= 1) return n;
        int c = 0;
        while(1<<c <= n) c++;
        return (1<<c)- 1 - minimumOneBitOperations(n-(1<<(c-1)));
    }
};