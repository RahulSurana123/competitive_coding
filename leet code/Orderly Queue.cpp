

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given a string s and an integer k. You can choose one of the first k letters of s and append it at the end of the string..

Return the lexicographically smallest string you could have after applying the mentioned step any number of moves.

    ***********************************************************
*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k==1){
            string ans = s;
            for(int i = 1; i < s.length();i++){
                if(ans > s.substr(i,s.length()-i) + s.substr(0,i)){
                    ans = s.substr(i,s.length()-i) + s.substr(0,i);
                }
            }
            return ans;
        }
        sort(s.begin(),s.end());
        return s;
    }
};