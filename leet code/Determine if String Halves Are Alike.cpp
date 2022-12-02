

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
    
    set<char> st;
    
    bool halvesAreAlike(string s) {
        
        int a = 0, b = 0;
        st.insert('a');st.insert('e');st.insert('i');st.insert('o');st.insert('u');
        st.insert('A');st.insert('E');st.insert('I');st.insert('O');st.insert('U');
        for(int i = 0; i < s.length()/2; i++){
            a += st.count(s[i]);
            b += st.count(s[s.length()-1-i]);
        }
        return a==b;
    }
};