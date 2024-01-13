

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given a string s of even length. Split this string into two halves of equal lengths, 
and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). 
Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.


    ***********************************************************
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isV(char x){
        return (x == 'a' || x=='e' || x=='i' || x=='o' || x=='u' ||x == 'A' || x=='E' || x=='I' || x=='O' || x=='U');
    }

    bool halvesAreAlike(string s) {
        int i = 0, j = s.length()-1, ans = 0;
        while(i<j) ans += (isV(s[i++]) - isV(s[j--]));
        return ans == 0;
    }
};