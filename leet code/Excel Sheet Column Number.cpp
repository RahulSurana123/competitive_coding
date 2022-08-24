

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 



    ***********************************************************
*/


#include <bits/stdc++.h>


class Solution {
public:
    int titleToNumber(string cT) {
        int ans = 0;
        for(int i = cT.size()-1 ; i >= 0; i-- ){
            ans += pow(26,cT.size()-1-i) * (cT[i] - 'A'+1);
        }
        return ans;
    }
};