

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. 
Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that 
digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    string decodeString(const string& s, int& i) {
        
        string ans = "";

        while (i < s.length() && s[i] != ']') {

            if (s[i] >= '0' && s[i] <= '9')res += s[i++];
            else {
                int n = 0;
                while (i < s.length() && s[i] >= '0' && s[i] <= '9'){
                    n*=10;
                    n+= s[i++] - '0';  
                }
                    
                i++;
                string t = decodeString(s, i);
                i++;
                while (n > 0){
                    n--;
                    res += t;
                }
            }
        }
        return ans;
    }

    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
};