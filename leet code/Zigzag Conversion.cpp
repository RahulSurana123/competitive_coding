

/* 
    Solution by Rahul Surana
    
    ***********************************************************


The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        if(numRows == 1) return s;
        for(int i = 0; i < numRows; i++){
            if(i < s.length()) ans += s[i];
            if(i == 0 || i == numRows-1){
                int j = i + numRows + numRows-2;
                while(j<s.length()) { 
                    ans += s[j]; 
                    j += numRows + numRows-2;
                    cout << ans <<" ";
                }   
            } else {
                int k = 2*(numRows-i-1);
                int j = numRows + numRows-2 - k;
                while(k+i<s.length()) { 
                    
                    ans += s[i+k];
                    if(i+k+j < s.length()) ans +=s[i+k+j]; 
                    
                    k += numRows + numRows-2;
                    cout << ans <<" ";
                }
            }
        }
        return ans;
    }
};