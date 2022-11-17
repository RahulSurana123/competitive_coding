



/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, 
and then at each step perform either of the following:

Append the character '0' zero times.
Append the character '1' one times.
This can be performed any number of times.

A good string is a string constructed by the above process having a length between low and high (inclusive).

Return the number of different good strings that can be constructed satisfying these properties. 
Since the answer can be large, return it modulo 109 + 7.

 

    ***********************************************************
*/



#define MOD 1000000007

class Solution {
public:
    
    vector<int> dp;
    
    //  memonization
    
    // int df(int x, int y, int len, int l, int h){
    //     if(len > h) return 0;
    //     if(dp[len] != -1) return dp[len]; 
    //     if(len >= l && len <= h) 
    //     return dp[len] = (1 + df(x,y,len+x,l,h)%MOD + df(x,y,len+y,l,h)%MOD)%MOD;
    //     return dp[len] = (df(x,y,len+x,l,h)%MOD + df(x,y,len+y,l,h)%MOD)%MOD;
    // }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        dp.resize(high+1,0);
        
        // return df(zero,one,0,low,high);
        
       
        //Tabulation
        
        for(int i = high; i >= 0; i--){
            if(i < low) {
                dp[i] += ((((i+zero) > high)? 0 : dp[i+zero]) + 
                          (((i+one) > high) ? 0 : dp[i+one]))%MOD;
            }
            else{
                dp[i] += (1 + 
                          (((i+zero) > high)? 0 : dp[i+zero]) + 
                          (((i+one) > high) ? 0 : dp[i+one]))%MOD;
            }
        }
        
        return dp[0];
    }
};