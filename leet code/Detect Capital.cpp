



/* 

    Solution by Rahul Surana
    
    ***********************************************************

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.


    ***********************************************************
*/




#include<bits/stdc++.h>

class Solution {
public:
    bool detectCapitalUse(string word) {
        int c = 0;
        for(int i= 0 ;i < word.length(); i++){
            if(word[i] >= 'A' && word[i] <='Z') c++;
        }
        if(c == word.length() || c == 0) return true;
        if(c == 1 && word[0] >='A' && word[0] <='Z') return true;
        return false;
            
    }
};