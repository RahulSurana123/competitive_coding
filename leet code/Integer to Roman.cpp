

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 
12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. 
However, the numeral for four is not IIII. Instead, the number four is written as IV. 
Because the one is before the five we subtract it making four. 
The same principle applies to the number nine, which is written as IX. 
There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    string intToRoman(int num) {
        
        string ans;

        while(num >= 1000){ ans += 'M'; num -= 1000; }

        if(num >= 900){ ans += "CM"; num-=900; }
        while(num >= 500){ ans += 'D'; num -= 500; }
        
        if(num >= 400){ ans += "CD"; num -= 400; }
        while(num >= 100){ ans += 'C'; num -= 100; }
        
        if(num >= 90){ ans += "XC"; num-=90; }
        while(num >= 50){ ans += 'L'; num -= 50; }

        if(num >= 40){ ans += "XL"; num -= 40; }
        while(num >= 10){ ans += 'X'; num -= 10; }

        if(num >= 9){ ans += "IX"; num-=9; }
        while(num >= 5){ ans += 'V'; num -= 5; }

        if(num >= 4){ ans += "IV"; num -= 4; }
        while(num>0){ ans+='I'; num--; }
        
        return ans;
    }
};