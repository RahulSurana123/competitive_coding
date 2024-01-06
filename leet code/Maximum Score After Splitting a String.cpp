

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a string s of zeros and ones, 
return the maximum score after splitting the string into two non-empty substrings 
(i.e. left substring and right substring).

The score after splitting a string is the number of zeros in the left substring plus 
the number of ones in the right substring.


    ***********************************************************
*/

class Solution {
public:
    int maxScore(string s) {
        int c = 0, n = s.length();
        for(int i = 1; i < n; i++) c += s[i] == '1';
        int ans = (s[0] == '0')+c, z = (s[0] == '0');
        for(int i = 1; i < n; i++){
            ans = max(ans,c+z);
            if(s[i] == '0') z++;
            else c--;
        }
        return ans;
    }
};