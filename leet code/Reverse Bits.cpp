

/* 

    Solution by Rahul Surana
    
    ***********************************************************

Reverse bits of a given 32 bits unsigned integer.

    ***********************************************************
*/


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t x=0;
        for(int i = 0; i < 32; i++){
            x += ((((n)>>i)&1) << (31-i));
        }
        return x;
    }
};