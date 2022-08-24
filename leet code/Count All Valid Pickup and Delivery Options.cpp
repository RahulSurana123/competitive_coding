

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given n orders, each order consist in pickup and delivery services. 

Count all valid pickup/delivery possible sequences such that delivery(i) is always after of pickup(i). 

Since the answer may be too large, return it modulo 10^9 + 7.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int MOD = 1e9+7;
    int fac(int n, int d){
        if(n == 1) return 1;
        return (n%MOD * (long long)fac(n-d,d)%MOD)%MOD;
    }
    
    int countOrders(int n) {
        if(n == 1) return 1;
        int ans = 0;
        ans += fac(n,1);
        ans = (ans%MOD * (long long)fac(((2*n)-1),2)%MOD);
        cout << ans <<" ";
        return ans;
    }
};
