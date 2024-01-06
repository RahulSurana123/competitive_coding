

/* 
    Solution by Rahul Surana
    
    ***********************************************************


The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

For example, the saying and conversion for digit string "3322251":


Given a positive integer n, return the nth term of the count-and-say sequence.
 



    ***********************************************************
*/


class Solution {
public:
    string countAndSay(int n) {
        
        if(n==1) return "1";
        
        string x = countAndSay(n-1);
        string ans="";
        int i = 0;
        
        while(i < x.length()){
            int j = 1;
            while(i+j < x.length() && x[i] == x[i+j]) j++;
            ans += to_string(j)+x[i]; 
            i+=j;
        }
        return ans;
    }
};