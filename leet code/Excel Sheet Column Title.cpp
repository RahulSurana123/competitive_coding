

/* 

    Solution by Rahul Surana
    
    ***********************************************************

Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

 


    ***********************************************************
*/


class Solution {
public:
static constexpr auto fast_io =  [](){  std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL); };
    string convertToTitle(int cN) {
        string ans = "";
        int d = 26;
        while(cN>0){
            int r = cN%d;
            ans += (r == 0)? 'Z' : ('A'+ (r-1));
            cN /= 26;
            if(r == 0) cN-=1;
        }
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};