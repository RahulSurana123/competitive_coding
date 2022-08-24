

/* 
    Solution by Rahul Surana
    
    ***********************************************************


The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer n, return its complement.


    ***********************************************************
*/


class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int ans = 0;
        int i = 0;
        while(n>0){
            if(n%2==0) ans += 1<<i;
            n/=2;
            i++;
        }
        return ans;
    }
};