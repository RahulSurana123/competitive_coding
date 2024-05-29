

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the binary representation of an integer as a string s, 
return the number of steps to reduce it to 1 under the following rules:

If the current number is even, you have to divide it by 2.

If the current number is odd, you have to add 1 to it.

It is guaranteed that you can always reach one for all test cases.


    ***********************************************************
*/


class Solution {
public:
    int numSteps(string s) {
        int ans = 0, n = s.length();
        for(int i = n-1; i > 0; i--){
            if(s[i] == '1') { 
                int j = 0; 
                while(i-j >= 0 && s[i-j] == '1'){ 
                    s[i-j] = '0'; 
                    j++;
                }
                if(i-j >= 0) 
                    s[i-j] = '1'; 
                else {
                    s = "1" + s; 
                    i++;
                } 
                ans+=2; 
            }
            else ans += 1;
            // cout << s<<" " << ans <<"\n";
        }
        return ans + (s[0] == '0'); 
    }
};