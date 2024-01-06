

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given a string s, which contains stars *.

In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:

The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    string removeStars(string s) {
        int ind = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '*'){
                ind--;
            }else{
                s[ind++]=s[i];
            }
        }
        return s.substr(0,ind);
    }
};