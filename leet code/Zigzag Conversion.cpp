

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
        if(numRows == 1 || s.length()==1) return s;
        int t = numRows + numRows-2;
        for(int i = 0; i < numRows; i++){
            for(int j = 0;j+i<s.length(); j += t){
                 ans += s[i+j]; 
                // cout << i << " "<< s[j]<< " this was called\n";    
                if(i != 0 && i != numRows-1 && t-i+j < s.length()) ans +=s[t-i+j]; 
                
                // k += t;
            }
            // cout << ans<<"\n";
        }
        return ans;
    }

};