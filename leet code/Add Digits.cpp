

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.



    ***********************************************************
*/


class Solution {
public:
    int addDigits(int num) {
        int ans = 0;
        while(num>=10){
            while(num>0){
                ans += num%10;
                num/=10;
            }
            // cout << ans <<" ";
            num = ans;
            ans = 0;
        }
        return num;
    }
};