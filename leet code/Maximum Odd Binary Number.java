

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a binary string s that contains at least one '1'.

You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.

Return a string representing the maximum odd binary number that can be created from the given combination.

Note that the resulting string can have leading zeros.


    ***********************************************************
*/

class Solution {
    public String maximumOddBinaryNumber(String s) {
        int c = 0;
        for(char x: s.toCharArray()) if(x=='1') c++;;
        return ("1".repeat(c-1) + "0".repeat(s.length()-c)  + "1") ;
    }
}