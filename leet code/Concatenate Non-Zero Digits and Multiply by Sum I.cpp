


/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are given an integer n.

Form a new integer x by concatenating all the non-zero digits of n in their original order. If there are no non-zero digits, x = 0.

Let sum be the sum of digits in x.

Return an integer representing the value of x * sum.

    ***********************************************************
*/

class Solution {
public:
    long long sumAndMultiply(int n) {
        int x = 0;
        int s = 0;
        while(n>0){
            if((n%10) > 0){
                x*=10;
                x+=n%10;
                s+=n%10;
            }
            n/=10;
        }
        long long ans = 0;
        while(x>0){
            ans*=10;
            ans+=x%10;
            x/=10;
        }
        ans*=s;
        return ans;
    }
};
