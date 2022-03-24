

/* 

    Solution by Rahul Surana
    
    ***********************************************************


There is a broken calculator that has the integer startValue on its display initially. In one operation, you can:

multiply the number on display by 2, or
subtract 1 from the number on display.
Given two integers startValue and target, return the minimum number of operations needed to display target on the calculator.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    
    int brokenCalc(int X, int Y) {
        int ans = 0;
        while(X<Y){
            ans++;
            if(Y%2)Y++;
            else Y/=2;
            cout << X <<" "<<Y <<"\n";
        }
        return X-Y+ans;
        // return df(startValue,target,0);
    }
};