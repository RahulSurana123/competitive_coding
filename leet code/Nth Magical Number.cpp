

/* 
    Solution by Rahul Surana
    
    ***********************************************************


A positive integer is magical if it is divisible by either a or b.

Given the three integers n, a, and b, return the nth magical number. 
Since the answer may be very large, return it modulo 109 + 7.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long x = (a*b) / __gcd(a,b);
        long z = (x / a) + (x / b) - 1;
        long s = max(0L,(((n/z)-1)*x)), e = (((n/z)+1)*x);
        
        // cout << s << " " << e << " "<< x << " " <<z<<"\n";
        while(s<e){
            long mid = s + (e-s)/2;
            if((mid / a) + (mid / b) - (mid/x) >= n) e = mid;
            else s = mid+1;
        }
        return s%1000000007;
    }
};