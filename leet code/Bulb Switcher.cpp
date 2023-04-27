
/*


Solution By Rahul Surana


***********************************


There are n bulbs that are initially off. You first turn on all the bulbs, then you turn off every second bulb.

On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). 
For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb.

Return the number of bulbs that are on after n rounds.
 


*************************************/



#include<bits/stdc++.h>

class Solution {
public:
    int bulbSwitch(int n) {
        
        // if(n<=1) return n;
        int x = 0;
        for(int i = 1; i*i <= n; i++){
            x++;
        }
        return x;
    }
};