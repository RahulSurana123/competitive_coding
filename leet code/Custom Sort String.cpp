

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given two strings order and s. 
All the characters of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. 
More specifically, if a character x occurs before a character y in order, 
then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.


    ***********************************************************
*/


class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> a;
        int c = 0;
        for(int i = 0;i < order.length(); i++){
            a[order[i]] = c++;
        }
        for(char x = 'a'; x <= 'z'; x++) if(!a.count(x)) a[x] = c++;
        string t = s;
        sort(t.begin(),t.end(), [&](char aa, char bb){ return a[aa] < a[bb]; });
        return t;
    }
};