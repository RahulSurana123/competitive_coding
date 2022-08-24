

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) 
so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    
    // string df(int i, string s,string a){
    //     if(i>=s.length()) return a;
    //     if(s[i] == '('){
    //         string f = df(i+1,s,"(");
    //     }
    //     else if(s[i] == ')') return a;
    //     else{
    //         a += s[i] + df(i+1,s,""); 
    //     }
    //     return "";
    // }
    
    string minRemoveToMakeValid(string s) {
        int cb = 0;
        string ans;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ')'){
                if(cb==0) s[i] = '#';
                else cb--;
            }
            else if(s[i] == '('){
                cb++;
            }
        }
        cb = 0;
        for(int i = s.length()-1; i >=0 ; i--){
            if(s[i] == '('){
                if(cb==0) s[i] = '#';
                else cb--;
            }
            else if(s[i] == ')'){
                cb++;
            }
        }
        for(int i = 0; i < s.length(); i++){
            if(s[i] != '#'){
                ans+=s[i];
            }
        }
        return ans;
    }
};