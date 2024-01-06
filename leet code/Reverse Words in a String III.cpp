

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.



    ***********************************************************
*/


class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int st = 0;
        for(int i = 0;i<n;i++){
            if(s[i] == ' '){
                reverse(s.begin()+st,s.begin()+i);
                st=i+1;
            }
        }
        reverse(s.begin()+st,s.end());
        return s;
    }
};