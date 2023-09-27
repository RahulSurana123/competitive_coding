

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given an encoded string s. 
To decode the string to a tape, the encoded string is read one character at a time and the following steps are taken:

If the character read is a letter, that letter is written onto the tape.
If the character read is a digit d, the entire current tape is repeatedly written d - 1 more times in total.
Given an integer k, return the kth letter (1-indexed) in the decoded string.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int i = 0;
        long cl = 0;
        while(cl < k){
            if(isalpha(s[i])){
                cl++;
            }
            else{
                cl *= s[i]-'0';       
            }
            i++;
        }
        
        for(int j = i-1; j >= 0; j--) {
            if(isalpha(s[j])){
                if(k == 0 || k == cl) return string(1,s[j]);
                cl--;
            }
            else{
                cl /= s[j]-'0';
                k%=cl;       
            }
        }
        return "";
    }
};