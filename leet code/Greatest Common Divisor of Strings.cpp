

/* 
    Solution by Rahul Surana
    
    ***********************************************************


For two strings s and t, we say "t divides s" if and only if s = t + ... + t 
(i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:

    bool checkd(string a,string& b, string& c){
        if(b.length()%a.length() > 0 || c.length()%a.length() > 0) return false;
        string t = a;
        while(t.length() < b.length() && t != b) t+=a;
        string t2 = a;
        while(t2.length() < c.length() && t2 != c) t2+=a;
        if(t==b && t2==c) return true;
        return false;
    }

    string gcdOfStrings(string str1, string str2) {
        int x = 0;
        bool f = false;
        string temp = str2;
        if(str2.length()>str1.length()) temp = str1;
        for(int i = temp.length(); i > 0; i--){
            // cout << temp.substr(0,i) <<"\n";
            if(checkd(temp.substr(0,i),str1,str2)) return temp.substr(0,i);
        }
        return "";
    }
};