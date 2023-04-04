

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. 
That is, no letter appears in a single substring more than once.

Return the minimum number of substrings in such a partition.

Note that each character should belong to exactly one substring in a partition.

 


    ***********************************************************
*/



#include<bits/stdc++.h>

class Solution {
public:
    int partitionString(string &s) {
        int f=0,ans = 1;
        for(auto &x: s){
            if(f & (1 << (x - 'a'))) { ans++; f = 0; }
            f = f | (1 << ( x - 'a'));
        }
        return ans;
    }
};