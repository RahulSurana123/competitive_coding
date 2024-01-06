

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a 0-indexed string s, permute s to get a new string t such that:

All consonants remain in their original places. 
More formally, if there is an index i with 0 <= i < s.length such that s[i] is a consonant, 
then t[i] = s[i].
The vowels must be sorted in the nondecreasing order of their ASCII values. 
More formally, for pairs of indices i, j with 0 <= i < j < s.length such that s[i] and s[j] are vowels, 
then t[i] must not have a higher ASCII value than t[j].
Return the resulting string.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in lowercase or uppercase. 
Consonants comprise all letters that are not vowels.


    ***********************************************************
*/

class Solution {
public:
    // set<char> ss{'a','e','i','o','u','A','E','I','O','U'};
    string sortVowels(string s) {
        auto isV = [](char a){ return ( a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') || (a== 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U'); };
        string v;
        for(int i = 0; i < s.length(); i++){
            if(isV(s[i])) v += s[i];
        }
        sort(v.begin(),v.end());
        if(v.length() == s.length()) return v;
        int j = 0;
        for(int i = 0; i < s.length(); i++){
            if(isV(s[i])) s[i] = v[j++];
        }
        return s;
    }
};