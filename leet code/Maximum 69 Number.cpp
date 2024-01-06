

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).


    ***********************************************************
*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maximum69Number (int num) {
        string ans = to_string(num);
        int x = 0;
        while(x<ans.length()&&ans[x] == '9') x++;
        if(x==ans.length()) return num;
        ans[x] = '9';
        return stoi(ans);
    }
};