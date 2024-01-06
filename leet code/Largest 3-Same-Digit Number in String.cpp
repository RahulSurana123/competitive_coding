

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a string num representing a large integer. 
An integer is good if it meets the following conditions:

It is a substring of num with length 3.
It consists of only one unique digit.
Return the maximum good integer as a string or an empty string "" if no such integer exists.

Note:

A substring is a contiguous sequence of characters within a string.
There may be leading zeroes in num or a good integer.


    ***********************************************************
*/

    
class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int n = num.length();
        for(int i = 2; i < n; i++){
            if(num[i-2] == num[i-1] && num[i-1] == num[i]) {
                string t = string(3,num[i]); 
                ans = max(t,ans);
            }
        }
        return ans;
    }
};