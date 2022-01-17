

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string> m;
        set<string> x;
        int j = 0;
        for(int i = 0; i < pattern.length(); i++){
            string a;
            if(m.find(pattern[i]) != m.end()){
                while(j < s.length() && s[j] != ' ') a+=s[j++];
                // a+="a";
                cout<< pattern[i] <<" 1 "<< a<<"\n";
                if(a != m[pattern[i]]) return false;
                
            }
            else{
                while(j < s.length() && s[j] != ' ') a+=s[j++];
                // a+="a";
                
                if(x.count(a)) return false;
                m[pattern[i]] = a;
                cout<< m[pattern[i]] <<" 2 "<< a << "\n";
                x.insert(a);
            }
            if(j >= s.length() && i < pattern.length()-1 ) return false;
            j++;
        }
        if(j < s.length()) return false;
        return true;
    }
};