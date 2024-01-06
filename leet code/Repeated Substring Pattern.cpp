

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a string s, check if it can be constructed by 
taking a substring of it and appending multiple copies of the substring together.


    ***********************************************************
*/


class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i = 1; i <= s.length()/2; i++){
            if(s.length()%i != 0) continue;
            string rs = s.substr(0,i);
            for(int j = 0; j < s.length(); j += i){
                if(rs != s.substr(j,i)) break;
                if( j == s.length()-i) return true;
            }
        }
        return false;
    }
};